#include "matrix.h"

///
/// \param nRows
/// \param nCols
/// \return
matrix getMemMatrix(const int nRows, const int nCols) {
    assert(nRows > 0 && nCols > 0);

    int **values = (int **) malloc(nRows * sizeof(int *));
    for (size_t i = 0; i < nRows; ++i)
        values[i] = (int *) malloc(nCols * sizeof(int));
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
void inputMatrices(matrix *ms, const size_t nMatrices) {
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
void outputMatrices(matrix *ms, const size_t nMatrices) {
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

void swapColumns(matrix m, const int j1, const int j2) {
    assert(j1 >= 0 && j2 >= 0);

    for (size_t i = 0; i < m.nRows; ++i)
        swap(&(m.values[i][j1]), &(m.values[i][j2]));
}

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

