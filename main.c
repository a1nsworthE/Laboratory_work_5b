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
// 1 задача>>>
/*  size_t n;
    scanf("%zd", &n);

    matrix m = getMemMatrix(n, n);
    inputMatrix(m);
    size_t indexMin = getMinValuePos(m).rowIndex;
    size_t indexMax = getMaxValuePos(m).rowIndex;
    swapRows(m, indexMin, indexMax);

    outputMatrix(m);
    freeMemMatrix(matrix1);

    return 0;
*/

// 2 задача>>>
/*  size_t n, m;
    scanf("%zd %zd", &n, &m);
    matrix matrix1 = getMemMatrix(n, m);
    inputMatrix(matrix1);
    sortRowsByMinElement(matrix1);

    outputMatrix(matrix1);
    freeMemMatrix(matrix1);

    return 0;
*/

// 3 задача>>>
/*  size_t n, m;
    scanf("%zd %zd", &n, &m);
    matrix matrix1 = getMemMatrix(n, m);
    inputMatrix(matrix1);
    sortColsByMinElement(matrix1);

    outputMatrix(matrix1);
    freeMemMatrix(matrix1);

    return 0;
*/

// 4 задача>>>
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
/**/
int main() {
    size_t n, m;
    scanf("%zd %zd", &n, &m);
    matrix matrix1 = getMemMatrix(n, m);
    inputMatrix(matrix1);

    outputMatrix(matrix1);
    freeMemMatrix(matrix1);

    return 0;
}