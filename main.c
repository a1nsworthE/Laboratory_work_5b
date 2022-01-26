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

bool isMutuallyInverseMatrices(const matrix m1, const matrix m2) {
    if (m1.nCols != m2.nRows)
        return false;

    const matrix m3 = mulMatrices(m1, m2);

    if (isEMatrix(m3))
        return true;
    else
        return false;
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

    size_t n2;
    scanf("%zd", &n2);
    matrix matrix2 = getMemMatrix(n2, n2);
    inputMatrix(matrix2);

    isMutuallyInverseMatrices(matrix1, matrix2);

    outputMatrix(matrix1);
    outputMatrix(matrix2);
    freeMemMatrix(matrix1);
    freeMemMatrix(matrix2);

    return 0;
}