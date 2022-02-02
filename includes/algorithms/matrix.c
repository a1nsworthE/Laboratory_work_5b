#include "matrix.h"

/// Выделение памяти под матрицу nRows x nCols
/// \param nRows - кол-во строк
/// \param nCols - кол-во столбцов
/// \return возвращает {values, nRows, nCols} ; values - указатель на матрицу
matrix getMemMatrix(const int nRows, const int nCols) {
    assert(nRows > 0 && nCols > 0);

    int **values = (int **) malloc(nRows * sizeof(int *));
    assert(values != NULL);

    for (register size_t i = 0; i < nRows; ++i) {
        values[i] = (int *) malloc(nCols * sizeof(int));
        assert(values[i] != NULL);
    }
    return (matrix) {values, nRows, nCols};
}

/// Выделение памяти под матрицу матриц, в котором содержатся матрицы размера nRows x nCols
/// \param nMatrices - размер массива матриц
/// \param nRows - кол-во строк
/// \param nCols - кол-во столбцов
/// \return Возвращает указатель на массив матриц
matrix *getMemArrayOfMatrices(const int nMatrices, const int nRows, const int nCols) {
    assert(nMatrices > 0);

    matrix *ms = (matrix *) malloc(nMatrices * sizeof(matrix));
    assert(ms != NULL);

    for (register size_t i = 0; i < nMatrices; ++i)
        ms[i] = getMemMatrix(nRows, nCols);
    return ms;
}

/// Освобождает память выделеную под хранение матрицу
/// \param m - матрица
void freeMemMatrix(matrix m) {
    for (register size_t i = 0; i < m.nRows; ++i)
        free(m.values[i]);
    free(m.values);
}

/// Освобождает память выделеную под хранение матрицы матриц
/// \param ms - указатель на массив матриц
/// \param nMatrices - размер массива матриц (кол-во матриц)
void freeMemMatrices(matrix *ms, const int nMatrices) {
    assert(nMatrices > 0);

    for (register size_t i = 0; i < nMatrices; ++i)
        freeMemMatrix(ms[i]);
    free(ms);
}

/// Ввод матрицы
/// \param m - матрица
void inputMatrix(matrix m) {
    for (register size_t i = 0; i < m.nRows; ++i)
        for (register size_t j = 0; j < m.nCols; ++j)
            scanf("%d", &(m.values[i][j]));
}

/// Ввод матрицы матриц матриц
/// \param ms - указатель на массив матриц
/// \param nMatrices - размер массива матриц
void inputMatrices(matrix *ms, const int nMatrices) {
    for (register size_t i = 0; i < nMatrices; ++i)
        inputMatrix(ms[i]);
}

/// Вывод матрицы
/// \param m - матрица
void outputMatrix(matrix m) {
    for (register size_t i = 0; i < m.nRows; ++i) {
        printf("|");
        for (register size_t j = 0; j < m.nCols; ++j)
            printf("%d ", m.values[i][j]);
        printf("\b| \n");
    }
}

/// Вывод матрицы матриц
/// \param ms - адрес нулевой матрицы матриц
/// \param nMatrices - размер массива матриц
void outputMatrices(matrix *ms, const int nMatrices) {
    assert(nMatrices > 0);

    for (register size_t i = 0; i < nMatrices; ++i) {
        outputMatrix(ms[i]);
        printf(", ");
    }

    if (nMatrices == 1)
        printf("\b\b");
}

/// Обменивает строки матрицы
/// \param m - матрица
/// \param i1,i2 - индекс строк (начиная с 0) для обмена
void swapRows(const matrix m, const int i1, const int i2) {
    assert(i1 >= 0 && i2 >= 0 && i1 <= m.nRows - 1 && i2 <= m.nRows - 1);

    int *f = m.values[i1];
    m.values[i1] = m.values[i2];
    m.values[i2] = f;
}


/// Обменивает столбцы матрицы
/// \param m - матрица
/// \param j1, j2 - индекс столбцов(начиная с 0) для обмена
void swapColumns(matrix m, const int j1, const int j2) {
    assert(j1 >= 0 && j2 >= 0);

    for (register size_t i = 0; i < m.nRows; ++i)
        swap(&(m.values[i][j1]), &(m.values[i][j2]));
}

/// Сортирует строки матрицы по неубыванию по критерию
/// \param m - матрица
/// \param criteria - критерий для сортировки
void insertionSortRowsMatrixByRowCriteria(matrix m, int (*criteria)(const int *, size_t)) {
    int *arrayForSort = (int *) malloc(m.nRows * sizeof(int));
    assert(arrayForSort != NULL);

    for (size_t i = 0; i < m.nRows; ++i)
        arrayForSort[i] = criteria(m.values[i], m.nCols);

    for (register size_t i = 1; i < m.nRows; ++i) {
        int tArray = arrayForSort[i];
        register size_t j = i;
        while (j > 0 && arrayForSort[j - 1] > tArray) {
            arrayForSort[j] = arrayForSort[j - 1];
            swapRows(m, j, j - 1);
            --j;
        }
        arrayForSort[j] = tArray;
    }

    free(arrayForSort);
}

/// Сортирует строки матрицы по неубыванию по критерию
/// \param m - матрица
/// \param criteria - критерий для сортировки
void insertionSortRowsMatrixByRowCriteriaD(matrix m, double (*criteria)(const int *, size_t)) {
    double *arrayForSort = (double *) malloc(m.nRows * sizeof(double));
    assert(arrayForSort != NULL);

    for (size_t i = 0; i < m.nRows; ++i)
        arrayForSort[i] = criteria(m.values[i], m.nCols);

    for (register size_t i = 1; i < m.nRows; ++i) {
        double tArray = arrayForSort[i];
        register size_t j = i;
        while (j > 0 && arrayForSort[j - 1] > tArray) {
            arrayForSort[j] = arrayForSort[j - 1];
            swapRows(m, j, j - 1);
            --j;
        }
        arrayForSort[j] = tArray;
    }

    free(arrayForSort);
}


/// Сортирует столбцы матрицы по неубыванию по критерию
/// \param m - матрица
/// \param criteria - критерий для сортировки
void insertionSortColsMatrixByColCriteria(matrix m, int (*criteria)(const int *, size_t)) {
    int *arrayForSort = (int *) malloc(m.nCols * sizeof(int));
    assert(arrayForSort != NULL);

    // Получение вспомогательного массива и массива со значением в столбцах
    int *arrayColumn = (int *) (malloc(m.nRows * sizeof(int)));
    assert(arrayColumn != NULL);

    for (register size_t i = 0; i < m.nCols; ++i) {
        for (register size_t j = 0; j < m.nRows; ++j)
            arrayColumn[j] = m.values[j][i];
        arrayForSort[i] = criteria(arrayColumn, m.nRows);
    }
    free(arrayColumn);

    for (size_t i = 0; i < m.nCols; ++i) {
        int tArray = arrayForSort[i];
        register size_t j = i;
        while (j > 0 && arrayForSort[j - 1] > tArray) {
            arrayForSort[j] = arrayForSort[j - 1];
            swapColumns(m, j, j - 1);
            --j;
        }
        arrayForSort[j] = tArray;
    }

    free(arrayForSort);
}

///  Проверка на квадратность
/// \param m - матрица
/// \return Возвращает true, если матрица квадратная, иначе false
bool isSquareMatrix(const matrix m) {
    return m.nRows == m.nCols ? true : false;
}

/// Проверка двух матриц на равенство
/// \param m1 - первая матрица
/// \param m2 - вторая матрица
/// \return Возращает true, если матрицы m1 и m2, иначе false
bool twoMatricesEqual(const matrix m1, const matrix m2) {
    if (m1.nRows != m2.nRows || m1.nCols != m2.nCols)
        return false;
    if (m1.nRows == m2.nRows && m1.nCols == m2.nCols) {
        for (size_t i = 0; i < m1.nRows; ++i)
            for (size_t j = 0; j < m2.nCols; ++j)
                if (m1.values[i][j] != m2.values[i][j])
                    return false;
    } else
        return false;

    return true;
}

/// Проверяет, является ли матрица еденичной
/// \param m - матрица
/// \return - возвращает true, если матрица еденичная, иначе false
bool isEMatrix(const matrix m) {
    if (isSquareMatrix(m)) {
        for (register size_t i = 0; i < m.nRows; ++i)
            for (register size_t j = i; j < m.nCols; ++j) {
                if (i == j) {
                    if (m.values[i][j] != 1)
                        return false;
                } else if (i != j) {
                    if (m.values[i][j] != 0)
                        return false;
                }
            }
    } else
        return false;

    return true;
}

/// Проверяет матрицу на симметрию (относительно главной диагонали)
/// \param m - матрица
/// \return Возвращает true, если матрица симметрична, иначе false
bool isSymmetricMatrix(const matrix m) {
    if (isSquareMatrix(m) && m.nRows == 1)
        return true;
    if (isSquareMatrix(m)) {
        for (register size_t i = 0; i < m.nRows; ++i)
            for (register size_t j = 0; j < m.nCols; ++j)
                if (i != j) {
                    if (m.values[i][j] != m.values[j][i])
                        return false;
                }
    } else
        return false;

    return true;
}

/// Транспонирует квадратную матрицу
/// \param m - матрица
void transposeSquareMatrix(matrix m) {
    assert(isSquareMatrix(m));

    for (size_t j = 1; j < m.nCols; ++j)
        swap(&(m.values[0][j]), &(m.values[j][0]));
}

/// Получает индекс минимального элемента
/// \param m - матрица
/// \return Возвращает индекс минимального элемента
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

/// Получает индекс максимального элемента
/// \param m - матрица
/// \return Возвращает индекс максимального элемента
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

/// Создает матрицу из массива
/// \param a - адрес ячейки памяти
/// \param nRows - кол - во строк
/// \param nCols - кол - во столбцов
/// \return Возвращает матрицу
matrix createMatrixFromArray(const int *a, const int nRows, const int nCols) {
    matrix m = getMemMatrix(nRows, nCols);
    size_t k = 0;
    for (int i = 0; i < nRows; i++)
        for (int j = 0; j < nCols; j++)
            m.values[i][j] = a[k++];

    return m;
}

/// Создает матрицу матриц
/// \param values - адрес ячейки памяти
/// \param nMatrices - кол - во матриц
/// \param nRows - кол - во строк
/// \param nCols - кол - во столбцов
/// \return Возвращает указатель на нулевую матрицу из nMatrices
matrix *
createArrayOfMatrixFromArray(const int *values, const size_t nMatrices, const size_t nRows, const size_t nCols) {
    matrix *ms = getMemArrayOfMatrices(nMatrices, nRows, nCols);

    size_t l = 0;
    for (int k = 0; k < nMatrices; k++)
        for (int i = 0; i < nRows; i++)
            for (int j = 0; j < nCols; j++)
                ms[k].values[i][j] = values[l++];

    return ms;
}

///
/// \param m1
/// \param m2
/// \return
matrix mulMatrices(const matrix m1, const matrix m2) {
    assert(m1.nCols == m2.nRows);

    matrix mulM1M2 = getMemMatrix(m1.nRows, m2.nCols);
    for (size_t i = 0; i < m1.nRows; ++i)
        for (size_t j = 0; j < m2.nCols; ++j) {
            mulM1M2.values[i][j] = 0;
            for (size_t k = 0; k < m1.nCols; ++k)
                mulM1M2.values[i][j] += m1.values[i][k] * m2.values[k][j];
        }

    return mulM1M2;
}

position getLeftMinPositionElement(const matrix m) {
    position minPos = {0, 0};
    int minElement = m.values[0][0];
    for (size_t i = 0; i < m.nRows; ++i) {
        for (size_t j = 0; j < m.nCols; ++j) {
            if (m.values[i][j] < minElement)
                minElement = m.values[i][j];
            else if (m.values[i][j] == minElement) {
                if (j < minPos.colIndex)
                    minPos.colIndex = j;
            }
        }
    }

    return minPos;
}