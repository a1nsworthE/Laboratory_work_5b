#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include "includes/algorithms/matrix.h"

int main() {
    size_t n;
    scanf("%zd", &n);

    matrix m = getMemMatrix(n, n);
    inputMatrix(m);

    size_t indexMin = getMinValuePos(m).rowIndex;
    size_t indexMax = getMaxValuePos(m).rowIndex;
    swapRows(m, indexMin, indexMax);

    outputMatrix(m);

    return 0;
}