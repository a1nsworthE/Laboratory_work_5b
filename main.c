#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include "includes/algorithms/matrix.h"

void sortRowsByMinElement(matrix m) {
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
    for (size_t i = 0; i < m.nRows; ++i)
        arraySum[i] += getSumArray(m.values[i], m.nCols);

    if (isUniqueArrayElements(arraySum, m.nRows))
        transposeSquareMatrix(m);

    free(arraySum);
}

// 1 задача>>>
/*
int main() {
    size_t n;
    scanf("%zd", &n);

    matrix m = getMemMatrix(n, n);
    inputMatrix(m);
    size_t indexMin = getMinValuePos(m).rowIndex;
    size_t indexMax = getMaxValuePos(m).rowIndex;
    swapRows(m, indexMin, indexMax);

    outputMatrix(m);
    freeMemMatrix(matrix1);

    return 0;
}
*/

// 2 задача>>>
/*
int main() {
    size_t n, m;
    scanf("%zd %zd", &n, &m);
    matrix matrix1 = getMemMatrix(n, m);
    inputMatrix(matrix1);
    sortRowsByMinElement(matrix1);

    outputMatrix(matrix1);
    freeMemMatrix(matrix1);

    return 0;
}
*/

// 3 задача>>>
/*
int maint() {
    size_t n, m;
    scanf("%zd %zd", &n, &m);
    matrix matrix1 = getMemMatrix(n, m);
    inputMatrix(matrix1);
    sortColsByMinElement(matrix1);

    outputMatrix(matrix1);
    freeMemMatrix(matrix1);

    return 0;
}
*/

// 4 задача>>>
/*
int main() {
    size_t n;
    scanf("%zd", &n);
    matrix matrix1 = getMemMatrix(n, n);
    inputMatrix(matrix1);
    getSquareOfMatrixIfSymmetric(&matrix1);

    outputMatrix(matrix1);
    freeMemMatrix(matrix1);

    return 0;
}
*/
/**/
/**/
/**/
/**/
/**/
/**/
/**/
/**/
/**/
/**/
/**/


int main() {
    size_t n;
    scanf("%zd", &n);
    matrix matrix1 = getMemMatrix(n, n);
    inputMatrix(matrix1);
    transposeIfMatrixHasEqualSumOfRows(matrix1);

    outputMatrix(matrix1);
    freeMemMatrix(matrix1);

    return 0;
}