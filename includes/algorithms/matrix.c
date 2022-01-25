#include "matrix.h"

///
/// \param nRows
/// \param nCols
/// \return
matrix getMemMatrix(const int nRows, const int nCols) {
    assert(nRows > 0 && nCols > 0);

    int **values = (int **) malloc(nRows * sizeof(int *));
    assert(values != NULL);

    for (size_t i = 0; i < nRows; ++i) {
        values[i] = (int *) malloc(nCols * sizeof(int));
        assert(values[i] != NULL);
    }
    return (matrix) {values, nRows, nCols};
}

///
/// \param nMatrices
/// \param nRows
/// \param nCols
/// \return
matrix *getMemArrayOfMatrices(const int nMatrices, const int nRows, const int nCols) {
    assert(nMatrices > 0);

    matrix *ms = (matrix *) malloc(nMatrices * sizeof(matrix));
    assert(ms != NULL);

    for (size_t i = 0; i < nMatrices; ++i)
        ms[i] = getMemMatrix(nRows, nCols);
    return ms;
}

///
/// \param m
void freeMemMatrix(matrix m) {
    for (size_t i = 0; i < m.nCols; ++i)
        free(m.values[i]);
    free(m.values);
}

///
/// \param ms
/// \param nMatrices
void freeMemMatrices(matrix *ms, const int nMatrices) {
    assert(nMatrices > 0);

    for (size_t i = 0; i < nMatrices; ++i)
        freeMemMatrix(ms[i]);
    free(ms);
}

///
/// \param m
void inputMatrix(matrix m) {
    for (size_t i = 0; i < m.nRows; ++i)
        for (size_t j = 0; j < m.nCols; ++j)
            scanf("%d", &(m.values[i][j]));
}

///
/// \param ms
/// \param nMatrices
void inputMatrices(matrix *ms, const int nMatrices) {
    for (size_t i = 0; i < nMatrices; ++i)
        inputMatrix(ms[i]);
}

///
/// \param m
void outputMatrix(matrix m) {
    for (size_t i = 0; i < m.nRows; ++i) {
        printf("|");
        for (size_t j = 0; j < m.nCols; ++j)
            printf("%d ", m.values[i][j]);
        printf("\b| \n");
    }
}

///
/// \param ms
/// \param nMatrices
void outputMatrices(matrix *ms, const int nMatrices) {
    assert(nMatrices > 0);

    for (size_t i = 0; i < nMatrices; ++i) {
        outputMatrix(ms[i]);
        printf(", ");
    }

    if (nMatrices == 1)
        printf("\b\b");
}

///
/// \param m
/// \param i1
/// \param i2
void swapRows(const matrix m, const int i1, const int i2) {
    assert(i1 >= 0 && i2 >= 0 && i1 <= m.nRows - 1 && i2 <= m.nRows - 1);

    int *const f = m.values[i1];
    m.values[i1] = m.values[i2];
    m.values[i2] = f;
}


///
/// \param m
/// \param j1
/// \param j2
void swapColumns(matrix m, const int j1, const int j2) {
    assert(j1 >= 0 && j2 >= 0);

    for (size_t i = 0; i < m.nRows; ++i)
        swap(&(m.values[i][j1]), &(m.values[i][j2]));
}

///
/// \param m
/// \param criteria
void insertionSortRowsMatrixByRowCriteria(matrix m, int (*criteria)(int *, int)) {
    int *arrayForSort = (int *) malloc(m.nRows * sizeof(int));
    assert(arrayForSort != NULL);

    for (size_t i = 0; i < m.nRows; ++i)
        arrayForSort[i] = criteria(m.values[i], m.nCols);

    for (size_t i = 1; i < m.nRows; ++i) {
        int tArray = arrayForSort[i];
        size_t j = i;
        while (j > 0 && arrayForSort[j - 1] < tArray) {
            arrayForSort[j] = arrayForSort[j - 1];
            m.values[j] = m.values[j - 1];
            --j;
        }
        arrayForSort[j] = tArray;
        swapRows(m, i, j);
    }

    free(arrayForSort);
}

///
/// \param m
/// \param criteria
void insertionSortColsMatrixByColCriteria(matrix m, int (*criteria)(int *, int)) {
    int *arrayForSort = (int *) malloc(m.nCols * sizeof(int));
    assert(arrayForSort != NULL);

    // Получение вспомогательного массива и массива со значением в столбцах
    int *arrayColumn = (int *) (malloc(m.nRows * sizeof(int)));
    assert(arrayColumn != NULL);

    for (register size_t i = 0; i < m.nCols; ++i) {
        for (register size_t j = 0; j < m.nRows; ++j)
            arrayColumn[j] = m.values[i][j];
        arrayForSort[i] = criteria(arrayColumn, m.nRows);
    }
    free(arrayColumn);

    for (size_t i = 0; i < m.nCols; ++i) {
        int tArray = arrayForSort[i];
        size_t j = i;
        while (j > 0 && arrayForSort[j - 1] < tArray) {
            arrayForSort[j] = arrayForSort[j - 1];
            swapColumns(m, j, j - 1);
            --j;
        }
        arrayForSort[j] = tArray;
        swapColumns(m, j, i);
    }
    free(arrayForSort);
}

///
/// \param m
/// \return
bool isSquareMatrix(const matrix m) {
    return m.nRows == m.nCols ? true : false;
}

///
/// \param m1
/// \param m2
/// \return
bool twoMatricesEqual(const matrix m1, const matrix m2) {
    if (m1.nRows == m2.nRows && m1.nCols == m2.nCols) {
        for (size_t i = 0; i < m1.nRows; ++i)
            for (size_t j = 0; j < m2.nCols; ++j)
                if (m1.values[i][j] != m2.values[i][j])
                    return false;
    } else
        return false;

    return true;
}

///
/// \param m
/// \return
bool isEMatrix(const matrix m) {
    if (isSquareMatrix(m)) {
        for (size_t i = 0; i < m.nRows; ++i) {
            for (size_t j = 0; j < m.nCols; ++j) {
                if (!(i == j && m.values[i][j] == 1))
                    return false;
                else if (!(i != j && m.values[i][j] == 0))
                    return false;
            }
        }
    } else
        return false;

    return true;
}

///
/// \param m
/// \return
bool isSymmetricMatrix(const matrix m) {
    if (isSquareMatrix(m)) {
        for (size_t i = 0; i < m.nRows; ++i)
            for (size_t j = 0; j < m.nCols; ++j)
                if (!(i != j && m.values[i][j] == m.values[j][i]))
                    return false;
    } else
        return false;

    return true;
}

///
/// \param m
void transposeSquareMatrix(matrix m) {
    assert(isSquareMatrix(m));

    for (size_t j = 1; j < m.nCols; ++j)
        swap(&(m.values[0][j]), &(m.values[j][0]));
}

///
/// \param m
/// \return
position getMinValuePos(const matrix m) {
    int minValue = m.values[0][0];
    position indexMin = {0, 0};
    for (size_t i = 0; i < m.nRows; ++i)
        for (size_t j = 0; j < m.nCols; ++j)
            if (m.values[i][j] < minValue) {
                minValue = m.values[i][j];
                indexMin.rowIndex = i;
                indexMin.colIndex = j;
            }

    return indexMin;
}

///
/// \param m
/// \return
position getMaxValuePos(const matrix m) {
    int maxValue = m.values[0][0];
    position indexMax = {0, 0};
    for (size_t i = 0; i < m.nRows; ++i)
        for (size_t j = 0; j < m.nCols; ++j)
            if (m.values[i][j] > maxValue) {
                maxValue = m.values[i][j];
                indexMax.rowIndex = i;
                indexMax.colIndex = j;
            }

    return indexMax;
}

matrix createMatrixFromArray(const int *a, const int nRows, const int nCols) {
    matrix m = getMemMatrix(nRows, nCols);
    size_t k = 0;
    for (int i = 0; i < nRows; i++)
        for (int j = 0; j < nCols; j++)
            m.values[i][j] = a[k++];

    return m;
}

matrix *createArrayOfMatrixFromArray(const int *values, const size_t nMatrices, const size_t nRows, const size_t nCols) {
    matrix *ms = getMemArrayOfMatrices(nMatrices, nRows, nCols);

    size_t l = 0;
    for (int k = 0; k < nMatrices; k++)
        for (int i = 0; i < nRows; i++)
            for (int j = 0; j < nCols; j++)
                ms[k].values[i][j] = values[l++];

    return ms;
}