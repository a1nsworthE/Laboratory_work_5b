#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include "includes/algorithms/matrix.h"

/*  size_t n;
    scanf("%zd", &n);

    matrix m = getMemMatrix(n, n);
    inputMatrix(m);

    size_t indexMin = getMinValuePos(m).rowIndex;
    size_t indexMax = getMaxValuePos(m).rowIndex;
    swapRows(m, indexMin, indexMax);

    outputMatrix(m);
    freeMemMatrix(matrix1);
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
/**/
/**/
/**/
int main() {
    size_t n, m;
    scanf("%zd %zd", &n, &m);
    matrix matrix1 = getMemMatrix(n, m);
    inputMatrix(matrix1);
    insertionSortRowsMatrixByRowCriteria(matrix1, getMaxElemArray);

    outputMatrix(matrix1);
    freeMemMatrix(matrix1);

    return 0;
}