#include "includes/algorithms/matrix.h"
#include "function_for_tasks.c"

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

// 5 задача>>>
/*
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
*/

// 6 задача>>>
/*
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
*/

// 7 задача>>>
/*
int main() {
    size_t n, m;
    scanf("%zd %zd", &n, &m);
    matrix matrix1 = getMemMatrix(n, m);
    inputMatrix(matrix1);
    printf("%d \n", findSumOfMaxesOfPseudoDiagonal(matrix1));

    outputMatrix(matrix1);
    freeMemMatrix(matrix1);

    return 0;
}
*/

// 8 задача>>>
/*
int main() {
    size_t n, m;
    scanf("%zd %zd", &n, &m);
    matrix matrix1 = getMemMatrix(n, m);
    inputMatrix(matrix1);
    printf("%d \n", getMinInArea(matrix1));

    outputMatrix(matrix1);
    freeMemMatrix(matrix1);

    return 0;
}
*/

// 9 задача>>>
/*
int main() {
    size_t n, m;
    scanf("%zd %zd", &n, &m);
    matrix matrix1 = getMemMatrix(n, m);
    inputMatrix(matrix1);
    sortByDistancesByNonDecreasing(matrix1);

    outputMatrix(matrix1);
    freeMemMatrix(matrix1);

    return 0;
}
*/

// 10 задача>>>
/*
int main() {
    size_t n, m;
    scanf("%zd %zd", &n, &m);
    matrix matrix1 = getMemMatrix(n, m);
    inputMatrix(matrix1);
    printf("%u \n", countEqClassesByRowsSum(matrix1));

    freeMemMatrix(matrix1);

    return 0;
}
*/

// 11 задача>>>
/*
int main() {
    size_t n, m;
    scanf("%zd %zd", &n, &m);
    matrix matrix1 = getMemMatrix(n, m);
    inputMatrix(matrix1);
    printf("%u \n", getCounterSpecialElement(matrix1));

    freeMemMatrix(matrix1);

    return 0;
}
*/

// 12 задача>>>
/*
int main() {
    size_t n;
    scanf("%zd", &n);
    matrix matrix1 = getMemMatrix(n, n);
    inputMatrix(matrix1);
    swapPenultimateRow(matrix1, getLeftMinPositionElement(matrix1).colIndex);

    outputMatrix(matrix1);

    freeMemMatrix(matrix1);

    return 0;
}
*/

// 13 задача>>>
/*
int main() {
    size_t nMatrics, n;
    scanf("%zd %zd", &nMatrics, &n);
    matrix *ms = getMemArrayOfMatrices(nMatrics, n, n);
    inputMatrices(ms, nMatrics);

    printf("%u \n", getCountNonDescendingRowsMatrices(ms, nMatrics));

    outputMatrices(ms, nMatrics);

    freeMemMatrices(ms, nMatrics);

    return 0;
}
*/

// 14 задача>>>
/*
int main() {
    size_t nMatrics, n, m;
    scanf("%zd %zd %zd", &nMatrics, &n, &m);
    matrix *ms = getMemArrayOfMatrices(nMatrics, n, m);
    inputMatrices(ms, nMatrics);

    printMatrixWithMaxZeroRows(ms, nMatrics);

    freeMemMatrices(ms, nMatrics);

    return 0;
}
*/

// 15 задача>>>
/*
int main() {
    size_t nMatrics, n, m;
    scanf("%zd %zd %zd", &nMatrics, &n, &m);
    matrixD *ms = getMemArrayOfMatricesD(nMatrics, n, m);
    inputMatricesD(ms, nMatrics);

    printMinMatrixWithMaxAbsElement(ms, nMatrics);

    freeMemMatricesD(ms, nMatrics);

    return 0;
}
*/

//Задачи со звездочкой***
// 16 задача>>>
/*
int main() {
    size_t n, m;
    scanf("%zd %zd", &n, &m);
    matrix matrix1 = getMemMatrix(n, m);
    inputMatrix(matrix1);

    printf("%d", getCountSpecialElementsInMatrixRows(matrix1));

    freeMemMatrix(matrix1);

    return 0;
}
*/

// 17 задача>>>
/*
int main() {
    size_t n, m;
    scanf("%zd %zd", &n, &m);
    matrix matrix1 = getMemMatrix(n, m);
    inputMatrix(matrix1);

    printf("%d", getCountSpecialElementsInMatrixRows(matrix1));

    freeMemMatrix(matrix1);

    return 0;
}
*/

// 18 задача>>>
/*
int main() {
    size_t n, m;
    scanf("%zd %zd", &n, &m);
    matrixD matrix1 = getMemMatrixD(n, m);
    inputMatrixD(matrix1);

    printf("%lf", getSpecialScalarProduct(matrix1));

    freeMemMatrixD(matrix1);

    return 0;
}
*/

int main() {
    size_t n, m;
    scanf("%zd %zd", &n, &m);
    matrixD matrix1 = getMemMatrixD(n, m);
    inputMatrixD(matrix1);

    printf("%lf", getSpecialScalarProduct(matrix1));

    freeMemMatrixD(matrix1);

    return 0;
}