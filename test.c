#include <stdio.h>
#include <stdbool.h>
#include "includes/algorithms/matrix.h"

void test_swapRows1() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    3, 5, 6,
            },
            2, 3
    );

    swapRows(m, 0, 1);

    assert(
            isEqualArray((int[]) {1, 2, 3}, 3, m.values[1], 3)
            &&
            isEqualArray((int[]) {3, 5, 6}, 3, m.values[0], 3)
    );

    freeMemMatrix(m);
}

void test_swapRows2() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    4, 5, 6,
                    7, 8, 9,
                    10, 11, 12,
                    13, 14, 15,
            },
            5, 3
    );

    swapRows(m, 0, 4);

    assert(
            isEqualArray((int[]) {1, 2, 3}, 3, m.values[4], 3)
            &&
            isEqualArray((int[]) {13, 14, 15}, 3, m.values[0], 3)
    );

    freeMemMatrix(m);
}


void test_swapRows3() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 2,
                    3, 4,
                    5, 6,
            },
            3, 2
    );

    swapRows(m, 0, 0);

    assert(isEqualArray((int[]) {1, 2}, 2, m.values[0], 2));

    freeMemMatrix(m);
}

void test_swapRows4() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 2,
                    3, 4,
                    5, 6,
                    7, 8,
            },
            4, 2
    );

    swapRows(m, 1, 2);

    assert(
            isEqualArray((int[]) {3, 4}, 2, m.values[2], 2)
            &&
            isEqualArray((int[]) {5, 6}, 2, m.values[1], 2)
    );

    freeMemMatrix(m);
}

void test_swapColumns1() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 2,
                    3, 4,
            },
            2, 2
    );

    swapColumns(m, 0, 1);

    assert(
            isEqualArray((int[]) {2, 1}, 2, m.values[0], 2)
            &&
            isEqualArray((int[]) {4, 3}, 2, m.values[1], 2)
    );

    freeMemMatrix(m);
}

void test_swapColumns2() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
            },
            1, 3
    );

    swapColumns(m, 0, 2);

    assert(
            isEqualArray((int[]) {3, 2, 1}, 3, m.values[0], 3));

    swapColumns(m, 1, 2);

    assert(isEqualArray((int[]) {3, 1, 2}, 3, m.values[0], 3));

    freeMemMatrix(m);
}

void test_swapColumns3() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    2, 4, 6,
            },
            2, 3
    );

    swapColumns(m, 1, 2);

    assert(
            isEqualArray((int[]) {1, 3, 2}, 3, m.values[0], 3)
            &&
            isEqualArray((int[]) {2, 6, 4}, 3, m.values[1], 3)
    );

    swapColumns(m, 0, 2);

    assert(
            isEqualArray((int[]) {2, 3, 1}, 3, m.values[0], 3)
            &&
            isEqualArray((int[]) {4, 6, 2}, 3, m.values[1], 3)
    );

    freeMemMatrix(m);
}

void test_swapColumns4() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    2, 4, 6,
                    4, 8, 12,
                    8, 16, 24,
            },
            4, 3
    );

    swapColumns(m, 0, 1);

    assert(
            isEqualArray((int[]) {2, 1, 3}, 3, m.values[0], 3)
            &&
            isEqualArray((int[]) {4, 2, 6}, 3, m.values[1], 3)
            &&
            isEqualArray((int[]) {8, 4, 12}, 3, m.values[2], 3)
            &&
            isEqualArray((int[]) {16, 8, 24}, 3, m.values[3], 3)
    );

    swapColumns(m, 1, 2);

    assert(
            isEqualArray((int[]) {2, 3, 1}, 3, m.values[0], 3)
            &&
            isEqualArray((int[]) {4, 6, 2}, 3, m.values[1], 3)
            &&
            isEqualArray((int[]) {8, 12, 4}, 3, m.values[2], 3)
            &&
            isEqualArray((int[]) {16, 24, 8}, 3, m.values[3], 3)
    );

    swapColumns(m, 0, 2);

    assert(
            isEqualArray((int[]) {1, 3, 2}, 3, m.values[0], 3)
            &&
            isEqualArray((int[]) {2, 6, 4}, 3, m.values[1], 3)
            &&
            isEqualArray((int[]) {4, 12, 8}, 3, m.values[2], 3)
            &&
            isEqualArray((int[]) {8, 24, 16}, 3, m.values[3], 3)
    );

    swapColumns(m, 1, 2);

    assert(
            isEqualArray((int[]) {1, 2, 3}, 3, m.values[0], 3)
            &&
            isEqualArray((int[]) {2, 4, 6}, 3, m.values[1], 3)
            &&
            isEqualArray((int[]) {4, 8, 12}, 3, m.values[2], 3)
            &&
            isEqualArray((int[]) {8, 16, 24}, 3, m.values[3], 3)
    );

    freeMemMatrix(m);
}

void test_insertionSortRowsMatrixByRowCriteria1() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    9, 8, 7,
                    6, 5, 4,
                    3, 2, 1,
            },
            3, 3
    );

    insertionSortRowsMatrixByRowCriteria(m, getSumArray);

    assert(
            isEqualArray((int[]) {3, 2, 1}, 3, m.values[0], 3)
            &&
            isEqualArray((int[]) {6, 5, 4}, 3, m.values[1], 3)
            &&
            isEqualArray((int[]) {9, 8, 7}, 3, m.values[2], 3)
    );

    freeMemMatrix(m);
}

void test_insertionSortRowsMatrixByRowCriteria2() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
            },
            1, 3
    );

    insertionSortRowsMatrixByRowCriteria(m, getSumArray);

    assert(isEqualArray((int[]) {1, 2, 3}, 3, m.values[0], 3));

    freeMemMatrix(m);
}


void test_insertionSortRowsMatrixByRowCriteria3() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    11, 11, 11,
                    20, 20, 20,
                    1, 1, 1,
            },
            3, 3
    );

    insertionSortRowsMatrixByRowCriteria(m, getSumArray);

    assert(
            isEqualArray((int[]) {1, 1, 1}, 3, m.values[0], 3)
            &&
            isEqualArray((int[]) {11, 11, 11}, 3, m.values[1], 3)
            &&
            isEqualArray((int[]) {20, 20, 20}, 3, m.values[2], 3)
    );

    freeMemMatrix(m);
}

void test_insertionSortRowsMatrixByRowCriteria4() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    3, 3, 3,
                    2, 2, 2,
                    4, 4, 4,
                    1, 1, 1,
            },
            4, 3
    );

    insertionSortRowsMatrixByRowCriteria(m, getSumArray);

    assert(
            isEqualArray((int[]) {1, 1, 1}, 3, m.values[0], 3)
            &&
            isEqualArray((int[]) {2, 2, 2}, 3, m.values[1], 3)
            &&
            isEqualArray((int[]) {3, 3, 3}, 3, m.values[2], 3)
            &&
            isEqualArray((int[]) {4, 4, 4}, 3, m.values[3], 3)
    );

    freeMemMatrix(m);
}

void test_insertionSortColsMatrixByColCriteria1() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    1, 2, 3,
                    1, 2, 3,
            },
            3, 3
    );

    insertionSortColsMatrixByColCriteria(m, getSumArray);

    assert(
            isEqualArray((int[]) {1, 2, 3}, 3, m.values[0], 3)
            &&
            isEqualArray((int[]) {1, 2, 3}, 3, m.values[1], 3)
            &&
            isEqualArray((int[]) {1, 2, 3}, 3, m.values[2], 3)
    );

    freeMemMatrix(m);
}

void test_insertionSortColsMatrixByColCriteria2() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    2, 1, 3,
                    2, 1, 3,
                    2, 1, 3,
            },
            3, 3
    );

    insertionSortColsMatrixByColCriteria(m, getSumArray);

    assert(
            isEqualArray((int[]) {1, 2, 3}, 3, m.values[0], 3)
            &&
            isEqualArray((int[]) {1, 2, 3}, 3, m.values[1], 3)
            &&
            isEqualArray((int[]) {1, 2, 3}, 3, m.values[2], 3)
    );

    freeMemMatrix(m);
}

void test_insertionSortColsMatrixByColCriteria3() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    3, 2, 1,
                    3, 2, 1,
                    3, 2, 1,
            },
            3, 3
    );

    insertionSortColsMatrixByColCriteria(m, getSumArray);

    assert(
            isEqualArray((int[]) {1, 2, 3}, 3, m.values[0], 3)
            &&
            isEqualArray((int[]) {1, 2, 3}, 3, m.values[1], 3)
            &&
            isEqualArray((int[]) {1, 2, 3}, 3, m.values[2], 3)
    );

    freeMemMatrix(m);
}

void test_insertionSortColsMatrixByColCriteria4() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    3, 2, 4, 5, 1,
                    3, 2, 4, 5, 1,
                    3, 2, 4, 5, 1,
                    3, 2, 4, 5, 1,
            },
            4, 5
    );

    insertionSortColsMatrixByColCriteria(m, getSumArray);

    assert(
            isEqualArray((int[]) {1, 2, 3, 4, 5}, 5, m.values[0], 5)
            &&
            isEqualArray((int[]) {1, 2, 3, 4, 5}, 5, m.values[1], 5)
            &&
            isEqualArray((int[]) {1, 2, 3, 4, 5}, 5, m.values[2], 5)
            &&
            isEqualArray((int[]) {1, 2, 3, 4, 5}, 5, m.values[3], 5)
    );

    freeMemMatrix(m);
}

void test_insertionSortColsMatrixByColCriteria5() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    4, 2, 3, 5, 1, 6,

            },
            1, 6
    );

    insertionSortColsMatrixByColCriteria(m, getSumArray);

    assert(isEqualArray((int[]) {1, 2, 3, 4, 5, 6}, 6, m.values[0], 6));

    freeMemMatrix(m);
}

void test_isSquareMatrix1() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 2,
                    3, 4,
            },
            2, 2
    );

    assert(isSquareMatrix(m));

    freeMemMatrix(m);
}

void test_isSquareMatrix2() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    3, 4, 4,
            },
            2, 3
    );

    assert(!isSquareMatrix(m));

    freeMemMatrix(m);
}

void test_twoMatricesEqual1() {
    matrix matrix1 = createMatrixFromArray(
            (int[]) {
                    1, 2,
                    3, 4,
            },
            2, 2
    );

    matrix matrix2 = createMatrixFromArray(
            (int[]) {
                    1, 2,
                    3, 4,
            },
            2, 2
    );

    assert(twoMatricesEqual(matrix1, matrix2));

    freeMemMatrix(matrix1);
    freeMemMatrix(matrix2);
}

void test_twoMatricesEqual2() {
    matrix matrix1 = createMatrixFromArray(
            (int[]) {
                    1, 2,
                    3, 3,
            },
            2, 2
    );

    matrix matrix2 = createMatrixFromArray(
            (int[]) {
                    1, 2,
                    3, 4,
            },
            2, 2
    );

    assert(!twoMatricesEqual(matrix1, matrix2));

    freeMemMatrix(matrix1);
    freeMemMatrix(matrix2);
}

void test_twoMatricesEqual3() {
    matrix matrix1 = createMatrixFromArray(
            (int[]) {
                    1, 2,
            },
            1, 2
    );

    matrix matrix2 = createMatrixFromArray(
            (int[]) {
                    1, 2,
                    3, 4,
            },
            2, 2
    );

    assert(!twoMatricesEqual(matrix1, matrix2));

    freeMemMatrix(matrix1);
    freeMemMatrix(matrix2);
}

void test_isEMatrix1() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 0,
                    0, 1,
            },
            2, 2
    );

    assert(isEMatrix(m));

    freeMemMatrix(m);
}

void test_isEMatrix2() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 1,
                    0, 1,
            },
            2, 2
    );

    assert(!isEMatrix(m));

    freeMemMatrix(m);
}

void test_isEMatrix3() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 0, 1,
                    0, 1, 0,
                    0, 0, 1,
            },
            3, 3
    );

    assert(!isEMatrix(m));

    freeMemMatrix(m);
}

void test_isEMatrix4() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 0, 0,
                    0, 1, 0,
                    0, 0, 1,
            },
            3, 3
    );

    assert(isEMatrix(m));

    freeMemMatrix(m);
}

void test_isEMatrix5() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 0, 1, 0, 0,
                    0, 1, 0, 2, 0,
                    0, 0, 1, 0, 1
            },
            5, 5
    );

    assert(!isEMatrix(m));

    freeMemMatrix(m);
}

void test_isSymmetricMatrix1() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 2,
                    3, 4,
            },
            2, 2
    );

    assert(!isSymmetricMatrix(m));

    freeMemMatrix(m);
}

void test_isSymmetricMatrix2() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 5,
                    5, 4,
            },
            2, 2
    );

    assert(isSymmetricMatrix(m));

    freeMemMatrix(m);
}

void test_isSymmetricMatrix3() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1,
            },
            1, 1
    );

    assert(isSymmetricMatrix(m));

    freeMemMatrix(m);
}

void test_isSymmetricMatrix4() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 6, 7,
                    6, 2, 5,
                    7, 5, 3,
            },
            3, 3
    );

    assert(isSymmetricMatrix(m));

    freeMemMatrix(m);
}

void test_isSymmetricMatrix5() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 6, 7,
                    6, 2, 5,
            },
            3, 2
    );

    assert(!isSymmetricMatrix(m));

    freeMemMatrix(m);
}

void test_transposeSquareMatrix1() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 3,
                    6, 2,
            },
            2, 2
    );

    transposeSquareMatrix(m);

    assert(
            isEqualArray((int[]) {1, 6}, 2, m.values[0], 2)
            &&
            isEqualArray((int[]) {3, 2}, 2, m.values[1], 2)

    );

    freeMemMatrix(m);
}

void test_transposeSquareMatrix2() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1,
            },
            1, 1
    );

    transposeSquareMatrix(m);

    assert(isEqualArray((int[]) {1}, 1, m.values[0], 1));

    freeMemMatrix(m);
}

void test_transposeSquareMatrix3() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    4, 1, 1,
                    6, 2, 1,
            },
            3, 3
    );

    transposeSquareMatrix(m);

    assert(
            isEqualArray((int[]) {1, 4, 6}, 3, m.values[0], 3)
            &&
            isEqualArray((int[]) {2, 1, 1}, 3, m.values[1], 3)
            &&
            isEqualArray((int[]) {3, 2, 1}, 3, m.values[2], 3)

    );

    freeMemMatrix(m);
}

void test_getMinValuePos1() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 2,
                    3, -1,
            },
            2, 2
    );

    position minPos = getMinValuePos(m);
    assert(minPos.rowIndex == 1 && minPos.colIndex == 1);

    freeMemMatrix(m);
}

void test_getMinValuePos2() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    -1, 2,
                    3, 1,
            },
            2, 2
    );

    position minPos = getMinValuePos(m);
    assert(minPos.rowIndex == 0 && minPos.colIndex == 0);

    freeMemMatrix(m);
}

void test_getMinValuePos3() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 2, 5,
                    1, -5, 6,
                    3, -1, 7,
            },
            3, 3
    );

    position minPos = getMinValuePos(m);
    assert(minPos.rowIndex == 1 && minPos.colIndex == 1);

    freeMemMatrix(m);
}

void test_getMinValuePos4() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 2, 1, 4,
                    1, 2, 3, 7,
                    1, 2, 6, -65,
                    3, -1, 21, 54,
            },
            4, 4
    );

    position minPos = getMinValuePos(m);
    assert(minPos.rowIndex == 2 && minPos.colIndex == 3);

    freeMemMatrix(m);
}

void test_getMaxValuePos1() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 2,
                    3, 8,
            },
            2, 2
    );

    position maxPos = getMaxValuePos(m);
    assert(maxPos.rowIndex == 1 && maxPos.colIndex == 1);

    freeMemMatrix(m);
}

void test_getMaxValuePos2() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    65, 2,
                    3, 1,
            },
            2, 2
    );

    position maxPos = getMaxValuePos(m);
    assert(maxPos.rowIndex == 0 && maxPos.colIndex == 0);

    freeMemMatrix(m);
}

void test_getMaxValuePos3() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 2, 5,
                    1, 65, 6,
                    3, -1, 7,
            },
            3, 3
    );

    position maxPos = getMaxValuePos(m);
    assert(maxPos.rowIndex == 1 && maxPos.colIndex == 1);

    freeMemMatrix(m);
}

void test_getMaxValuePos4() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 2, 1, 4,
                    1, 2, 3, 7,
                    1, 2, 6, 65,
                    3, -1, 21, 54,
            },
            4, 4
    );

    position maxPos = getMaxValuePos(m);
    assert(maxPos.rowIndex == 2 && maxPos.colIndex == 3);

    freeMemMatrix(m);
}

void test_getMaxValuePos() {
    test_getMaxValuePos1();
    test_getMaxValuePos2();
    test_getMaxValuePos3();
    test_getMaxValuePos4();
}

void test_getMinValuePos() {
    test_getMinValuePos1();
    test_getMinValuePos2();
    test_getMinValuePos3();
    test_getMinValuePos4();
}

void test_transposeSquareMatrix() {
    test_transposeSquareMatrix1();
    test_transposeSquareMatrix2();
    test_transposeSquareMatrix3();
}

void test_isSymmetricMatrix() {
    test_isSymmetricMatrix1();
    test_isSymmetricMatrix2();
    test_isSymmetricMatrix3();
    test_isSymmetricMatrix4();
    test_isSymmetricMatrix5();

}

void test_isEMatrix() {
    test_isEMatrix1();
    test_isEMatrix2();
    test_isEMatrix3();
    test_isEMatrix4();
    test_isEMatrix5();
}

void test_twoMatricesEqual() {
    test_twoMatricesEqual1();
    test_twoMatricesEqual2();
    test_twoMatricesEqual3();
}

void test_isSquareMatrix() {
    test_isSquareMatrix1();
    test_isSquareMatrix2();
}

void test_insertionSortRowsMatrixByRowCriteria() {
    test_insertionSortColsMatrixByColCriteria1();
    test_insertionSortColsMatrixByColCriteria2();
    test_insertionSortColsMatrixByColCriteria3();
    test_insertionSortColsMatrixByColCriteria4();
    test_insertionSortColsMatrixByColCriteria5();
}

void test_insertionSortColsMatrixByColCriteria() {
    test_insertionSortRowsMatrixByRowCriteria1();
    test_insertionSortRowsMatrixByRowCriteria2();
    test_insertionSortRowsMatrixByRowCriteria3();
    test_insertionSortRowsMatrixByRowCriteria4();
}


void test_swapColumns() {
    test_swapColumns1();
    test_swapColumns2();
    test_swapColumns3();
    test_swapColumns4();
}


void test_swapRows() {
    test_swapRows1();
    test_swapRows2();
    test_swapRows3();
    test_swapRows4();
}

void test_matrix_function() {
    test_swapRows();
    test_swapColumns();
    test_insertionSortRowsMatrixByRowCriteria();
    test_insertionSortColsMatrixByColCriteria();
    test_isSquareMatrix();
    test_twoMatricesEqual();
    test_isEMatrix();
    test_isSymmetricMatrix();
    test_transposeSquareMatrix();
    test_getMinValuePos();
    test_getMaxValuePos();
}

int main() {
    test_matrix_function();

    return 0;
}