#ifndef INC_5B_MATRIX_H
#define INC_5B_MATRIX_H

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <math.h>
#include <float.h>
#include <limits.h>

#include "../structs/matrix.c"
#include "array.h"

matrix getMemMatrix(int nRows, int nCols);

matrix *getMemArrayOfMatrices(int nMatrices, int nRows, int nCols);

void freeMemMatrix(matrix m);

void freeMemMatrices(matrix *ms, int nMatrices);

void inputMatrix(matrix m);

void inputMatrices(matrix *ms, int nMatrices);

void outputMatrix(matrix m);

void outputMatrices(matrix *ms, int nMatrices);

matrixD getMemMatrixD(int nRows, int nCols);

matrixD *getMemArrayOfMatricesD(int nMatrices, int nRows, int nCols);

void freeMemMatrixD(matrixD m);

void freeMemMatricesD(matrixD *ms, int nMatrices);

void inputMatrixD(matrixD m);

void inputMatricesD(matrixD *ms, int nMatrices);

void outputMatrixD(matrixD m);

void outputMatricesD(matrixD *ms, int nMatrices);

void swapRows(matrix m, int i1, int i2);

void swapColumns(matrix m, int j1, int j2);

void insertionSortRowsMatrixByRowCriteria(matrix m, int (*criteria)(const int *, size_t));

void insertionSortRowsMatrixByRowCriteriaD(matrix m, double (*criteria)(const int *, size_t));

void insertionSortColsMatrixByColCriteria(matrix m, int (*criteria)(const int *, size_t));

bool isSquareMatrix(matrix m);

bool twoMatricesEqual(matrix m1, matrix m2);

bool isEMatrix(matrix m);

bool isSymmetricMatrix(matrix m);

void transposeSquareMatrix(matrix m);

position getMinValuePos(matrix m);

position getMaxValuePos(matrix m);

position getMinValuePosD(matrixD m);

position getMaxValuePosD(matrixD m);

double getMaxElementMatrixByAbsD(matrixD m);

matrixD createMatrixFromArrayD(const double *a, int nRows, int nCols);

matrix createMatrixFromArray(const int *a, int nRows, int nCols);

matrix *createArrayOfMatrixFromArray(const int *values, size_t nMatrices, size_t nRows, size_t nCols);

matrix mulMatrices(matrix m1, matrix m2);

position getLeftMinPositionElement(matrix m);

bool hasAllSortByRows(matrix m, bool(*condition)(int, int));

unsigned getCounterZeroRows(matrix m);

#endif //INC_5B_MATRIX_H
