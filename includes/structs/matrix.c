#include <stdio.h>

typedef struct matrix {
    int **values;  // элементы матриц
    int nRows;     // кол - во строк
    int nCols;     // кол - во столбцов
} matrix;

typedef struct matrixD {
    double **values;    // элементы матриц
    int nRows;          // кол - во строк
    int nCols;          // кол - во столбцов
} matrixD;


typedef struct position {
    size_t rowIndex;
    size_t colIndex;
} position;