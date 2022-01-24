#ifndef INC_5B_MATRIX_H
#define INC_5B_MATRIX_H

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <assert.h>

#include "../structs/matrix.c"

void swap(int *a, int *b);

matrix getMemMatrix(int nRows, int nCols);

matrix *getMemArrayOfMatrices(int nMatrices, int nRows, int nCols);

void freeMemMatrix(matrix m);

void freeMemMatrices(matrix *ms, int nMatrices);

void inputMatrix(matrix m);

void inputMatrices(matrix *ms, size_t nMatrices);

void outputMatrix(matrix m);

void outputMatrices(matrix *ms, size_t nMatrices);

void swapRows(matrix m, int i1, int i2);

#endif //INC_5B_MATRIX_H
