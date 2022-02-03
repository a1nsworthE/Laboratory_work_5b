#include "includes/algorithms/matrix.h"

void sortRowsByMaxElement(matrix m) {
    insertionSortRowsMatrixByRowCriteria(m, getMaxElemArray);
}

void sortColsByMinElement(matrix m) {
    insertionSortColsMatrixByColCriteria(m, getMinElemArray);
}

void getSquareOfMatrixIfSymmetric(matrix *m) {
    if (isSymmetricMatrix(*m))
        *m = mulMatrices(*m, *m);
}

void transposeIfMatrixHasEqualSumOfRows(matrix m) {
    long long *arraySum = (long long *) calloc(m.nRows, sizeof(long long));
    if (arraySum == NULL) {
        fprintf(stderr, "bad data");
        exit(1);
    }

    for (register size_t i = 0; i < m.nRows; ++i)
        arraySum[i] += getSumArrayLL(m.values[i], m.nCols);

    if (isUniqueArrayElements(arraySum, m.nRows))
        transposeSquareMatrix(m);

    free(arraySum);
}

bool isMutuallyInverseMatrices(const matrix m1, const matrix m2) {
    if (m1.nCols != m2.nRows)
        return false;

    const matrix m3 = mulMatrices(m1, m2);

    if (isEMatrix(m3))
        return true;
    else
        return false;
}

long long findSumOfMaxesOfPseudoDiagonal(const matrix m) {
    assert(m.nRows != 0 || m.nCols != 0);

    // Массив максимумов из псевдогоналей матрицы
    int *arrayMaxElemsPseudoDiagonal = (int *) malloc((m.nRows + m.nCols - 2) * sizeof(int));
    size_t sizeArrayMaxElemsPseudoDiagonal = 0;

    // Поиск максимальных значений на псевдогоналях слева и справа от главной диагонали
    position leftI = {1, 0};
    position rightI = {0, 1};
    while (leftI.rowIndex < m.nRows && leftI.colIndex < 1 ||
           rightI.colIndex < m.nCols && rightI.rowIndex < 1) {

        // Поиск слева
        if (leftI.rowIndex < m.nRows && leftI.colIndex < 1) {
            int maxElemLeft = m.values[leftI.rowIndex][leftI.colIndex];
            for (register size_t i = leftI.rowIndex + 1, j = leftI.colIndex + 1; i < m.nRows && j < m.nCols; ++i, ++j)
                if (m.values[i][j] > maxElemLeft)
                    maxElemLeft = m.values[i][j];
            append(arrayMaxElemsPseudoDiagonal, &sizeArrayMaxElemsPseudoDiagonal, maxElemLeft);
            leftI.rowIndex++;
        }

        // Поиск справа
        if (rightI.colIndex < m.nCols && rightI.rowIndex < 1) {
            int maxElemRight = m.values[rightI.rowIndex][rightI.colIndex];
            for (register size_t i = rightI.rowIndex + 1, j = rightI.colIndex + 1; i < m.nRows && j < m.nCols; ++i, ++j)
                if (m.values[i][j] > maxElemRight)
                    maxElemRight = m.values[i][j];
            append(arrayMaxElemsPseudoDiagonal, &sizeArrayMaxElemsPseudoDiagonal, maxElemRight);
            rightI.colIndex++;
        }
    }

    long long sum = getSumArrayLL(arrayMaxElemsPseudoDiagonal, sizeArrayMaxElemsPseudoDiagonal);

    free(arrayMaxElemsPseudoDiagonal);

    return sum;
}

int getMinInArea(const matrix m) {
    position maxElemPos = getMaxValuePos(m);
    int minElem = m.values[maxElemPos.rowIndex][maxElemPos.colIndex];

    int left = maxElemPos.colIndex;
    int right = left;
    for (register int i = maxElemPos.rowIndex; i >= 0; --i) {
        for (register size_t j = left; j <= right; ++j)
            if (m.values[i][j] < minElem)
                minElem = m.values[i][j];
        left = left > 0 ? left - 1 : left;
        right = right < m.nRows ? right + 1 : right;
    }

    return minElem;
}

void sortByDistancesByNonDecreasing(matrix m) {
    insertionSortRowsMatrixByRowCriteriaD(m, getDistance);
}

unsigned countEqClassesByRowsSum(const matrix m) {
    assert(m.nRows > 0 && m.nCols > 0);

    long long *arraySumsRows = (long long *) malloc(m.nRows * sizeof(long long));
    assert(arraySumsRows != NULL);

    for (register size_t i = 0; i < m.nRows; ++i)
        arraySumsRows[i] = getSumArrayLL(m.values[i], m.nCols);

    insertionSort(arraySumsRows, m.nRows, isIncreasing);

    unsigned counterEqual = 0;
    long long lastNumber = arraySumsRows[0];
    bool isLowTwo = true;
    for (register size_t i = 1; i < m.nRows; ++i) {
        long long currentNumber = arraySumsRows[i];
        if (currentNumber == lastNumber && isLowTwo) {
            counterEqual++;
            isLowTwo = false;
        } else if (currentNumber != lastNumber)
            isLowTwo = true;

        lastNumber = currentNumber;
    }

    free(arraySumsRows);

    return counterEqual;
}

unsigned getCounterSpecialElement(const matrix m) {
    assert(m.nRows > 0 && m.nCols > 0);

    // Массив для хранения столбца
    long long *arraySumColumn = (long long *) malloc(m.nCols * sizeof(long long));
    assert(arraySumColumn != NULL);

    // Массив для хранения суммы стобца
    int *arrayColumn = (int *) (malloc(m.nRows * sizeof(int)));
    assert(arrayColumn != NULL);

    unsigned counterSpecial = 0;
    for (register size_t i = 0; i < m.nCols; ++i) {
        for (register size_t j = 0; j < m.nRows; ++j)
            arrayColumn[j] = m.values[j][i];

        arraySumColumn[i] = getSumArrayLL(arrayColumn, m.nRows);
        int maxElementColumn = getMaxElemArray(arrayColumn, m.nRows);
        if (arraySumColumn[i] - maxElementColumn < maxElementColumn)
            counterSpecial++;
    }
    free(arrayColumn);
    free(arraySumColumn);

    return counterSpecial;
}

void swapPenultimateRow(matrix m, const size_t indexColumn) {
    assert(m.nRows > 1 && m.nCols > 0);

    size_t RowIndexMin = m.nRows - 1;
    const size_t swapRowIndex = m.nRows - 2;
    size_t swapColIndex = m.nCols - 1;
    for (size_t i = 0; i < m.nRows; ++i) {
        m.values[swapRowIndex][swapColIndex] = m.values[RowIndexMin][indexColumn];
        if (RowIndexMin > 0)
            RowIndexMin--;
        if (swapColIndex > 0)
            swapColIndex--;
    }
}

unsigned getCountNonDescendingRowsMatrices(const matrix *ms, const size_t nMatrix) {
    unsigned counterMatrix = 0;
    for (size_t i = 0; i < nMatrix; ++i)
        if (hasAllSortByRows(ms[i], isNonDecreasing))
            counterMatrix++;
    return counterMatrix;
}

void printMatrixWithMaxZeroRows(const matrix *ms, const size_t nMatrix) {
    int *arrayCounterZeroRows = (int *) malloc(nMatrix * sizeof(int));
    for (size_t i = 0; i < nMatrix; ++i)
        arrayCounterZeroRows[i] = getCounterZeroRows(ms[i]);
    int maxCounterZeroRows = getMaxElemArray(arrayCounterZeroRows, nMatrix);

    for (size_t i = 0; i < nMatrix; ++i)
        if (arrayCounterZeroRows[i] == maxCounterZeroRows)
            outputMatrix(ms[i]);

    free(arrayCounterZeroRows);
}

void printMinMatrixWithMaxAbsElement(const matrixD *ms, const size_t nMatrix) {
    double *arrayMaxAbsElemMatrix = (double *) malloc(nMatrix * sizeof(double));
    for (size_t i = 0; i < nMatrix; ++i)
        arrayMaxAbsElemMatrix[i] = getMaxElementMatrixByAbsD(ms[i]);
    double minAbsElement = getMinElementD(arrayMaxAbsElemMatrix, nMatrix);

    for (size_t i = 0; i < nMatrix; ++i)
        if ((arrayMaxAbsElemMatrix[i] - minAbsElement) < DBL_EPSILON)
            outputMatrixD(ms[i]);

    free(arrayMaxAbsElemMatrix);
}


