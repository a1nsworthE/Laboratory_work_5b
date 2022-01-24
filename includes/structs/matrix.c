typedef struct matrix {
    int **values; // элементы матриц
    int nRows;    // кол - во строк
    int nCols;    // кол - во столбцов
} matrix;

typedef struct position {
    int rowIndex;
    int colIndex;
} position;