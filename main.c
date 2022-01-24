#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include "includes/algorithms/matrix.h"

int main() {
    matrix a = getMemMatrix(2, 2);
    inputMatrix(a);

    swapRows(a, 0, 1);

    outputMatrix(a);

    freeMemMatrix(a);

    return 0;
}