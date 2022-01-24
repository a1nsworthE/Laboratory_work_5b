#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include "includes/algorithms/matrix.h"

int main() {
    matrix array = getMemMatrix(2, 2);
    inputMatrix(array);

    swapRows(array, 0, 1);

    outputMatrix(array);

    freeMemMatrix(array);

    return 0;
}