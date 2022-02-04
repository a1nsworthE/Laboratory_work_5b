#include "includes/algorithms/matrix.h"
#include "function_for_tasks.c"

void test_swapRows_oneRowAtBorder1() {
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

void test_swapRows_atBorders() {
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

void test_swapRows_equalRowsForSwap() {
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

void test_swapRows_atCenter() {
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

void test_swapColumns_neighboursCols() {
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

void test_swapColumns_colsAtBorders() {
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

void test_swapColumns_oneColAtBorder() {
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

void test_swapColumns_largeCounterRows() {
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

void test_insertionSortRowsMatrixByRowCriteria_allRowsDescending() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    9, 8, 7,
                    6, 5, 4,
                    3, 2, 1,
            },
            3, 3
    );

    insertionSortRowsMatrixByRowCriteria(m, getSumArrayLL);

    assert(
            isEqualArray((int[]) {3, 2, 1}, 3, m.values[0], 3)
            &&
            isEqualArray((int[]) {6, 5, 4}, 3, m.values[1], 3)
            &&
            isEqualArray((int[]) {9, 8, 7}, 3, m.values[2], 3)
    );

    freeMemMatrix(m);
}

void test_insertionSortRowsMatrixByRowCriteria_oneRows() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
            },
            1, 3
    );

    insertionSortRowsMatrixByRowCriteria(m, getSumArrayLL);

    assert(isEqualArray((int[]) {1, 2, 3}, 3, m.values[0], 3));

    freeMemMatrix(m);
}

void test_insertionSortRowsMatrixByRowCriteria_randomPositionRows() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    11, 11, 11,
                    20, 20, 20,
                    1, 1, 1,
            },
            3, 3
    );

    insertionSortRowsMatrixByRowCriteria(m, getSumArrayLL);

    assert(
            isEqualArray((int[]) {1, 1, 1}, 3, m.values[0], 3)
            &&
            isEqualArray((int[]) {11, 11, 11}, 3, m.values[1], 3)
            &&
            isEqualArray((int[]) {20, 20, 20}, 3, m.values[2], 3)
    );

    freeMemMatrix(m);
}

void test_insertionSortRowsMatrixByRowCriteria_maxRowsInBottom() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    3, 3, 3,
                    2, 2, 2,
                    4, 4, 4,
                    1, 1, 1,
            },
            4, 3
    );

    insertionSortRowsMatrixByRowCriteria(m, getSumArrayLL);

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

void test_insertionSortColsMatrixByColCriteria_withoutMistakes() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    1, 2, 3,
                    1, 2, 3,
            },
            3, 3
    );

    insertionSortColsMatrixByColCriteria(m, getSumArrayLL);

    assert(
            isEqualArray((int[]) {1, 2, 3}, 3, m.values[0], 3)
            &&
            isEqualArray((int[]) {1, 2, 3}, 3, m.values[1], 3)
            &&
            isEqualArray((int[]) {1, 2, 3}, 3, m.values[2], 3)
    );

    freeMemMatrix(m);
}

void test_insertionSortColsMatrixByColCriteria_maxColsAtBorder() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    2, 1, 3,
                    2, 1, 3,
                    2, 1, 3,
            },
            3, 3
    );

    insertionSortColsMatrixByColCriteria(m, getSumArrayLL);

    assert(
            isEqualArray((int[]) {1, 2, 3}, 3, m.values[0], 3)
            &&
            isEqualArray((int[]) {1, 2, 3}, 3, m.values[1], 3)
            &&
            isEqualArray((int[]) {1, 2, 3}, 3, m.values[2], 3)
    );

    freeMemMatrix(m);
}

void test_insertionSortColsMatrixByColCriteria_NonIncreasing() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    3, 2, 1,
                    3, 2, 1,
                    3, 2, 1,
            },
            3, 3
    );

    insertionSortColsMatrixByColCriteria(m, getSumArrayLL);

    assert(
            isEqualArray((int[]) {1, 2, 3}, 3, m.values[0], 3)
            &&
            isEqualArray((int[]) {1, 2, 3}, 3, m.values[1], 3)
            &&
            isEqualArray((int[]) {1, 2, 3}, 3, m.values[2], 3)
    );

    freeMemMatrix(m);
}

void test_insertionSortColsMatrixByColCriteria_minColAtBorder() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    3, 2, 4, 5, 1,
                    3, 2, 4, 5, 1,
                    3, 2, 4, 5, 1,
                    3, 2, 4, 5, 1,
            },
            4, 5
    );

    insertionSortColsMatrixByColCriteria(m, getSumArrayLL);

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

void test_insertionSortColsMatrixByColCriteria_oneRow() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    4, 2, 3, 5, 1, 6,

            },
            1, 6
    );

    insertionSortColsMatrixByColCriteria(m, getSumArrayLL);

    assert(isEqualArray((int[]) {1, 2, 3, 4, 5, 6}, 6, m.values[0], 6));

    freeMemMatrix(m);
}

void test_isSquareMatrix_withoutMistakes() {
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

void test_isSquareMatrix_noSquare() {
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

void test_twoMatricesEqual_withoutMistakes() {
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

void test_twoMatricesEqual_atCorner() {
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

void test_twoMatricesEqual_noEqualRows() {
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

void test_isEMatrix_withoutMistakes1() {
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

void test_isEMatrix_atCorner1() {
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

void test_isEMatrix_atCorner2() {
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

void test_isEMatrix_withoutMistakes2() {
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

void test_isEMatrix_noSquare() {
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

void test_isSymmetricMatrix_atBorders1() {
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

void test_isSymmetricMatrix_atBorders2() {
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

void test_isSymmetricMatrix_matrix1x1() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1,
            },
            1, 1
    );

    assert(isSymmetricMatrix(m));

    freeMemMatrix(m);
}

void test_isSymmetricMatrix_withoutMistakes() {
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

void test_isSymmetricMatrix_noSquare() {
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

void test_transposeSquareMatrix_matrix2x2() {
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

void test_transposeSquareMatrix_matrix1x1() {
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

void test_transposeSquareMatrix_matrix3x3() {
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

void test_getMinValuePos_minAtBorders1() {
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

void test_getMinValuePos_minAtBorders2() {
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

void test_getMinValuePos_minInCenter() {
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

void test_getMinValuePos_minInLargeMatrix() {
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

void test_getMaxValuePos_maxAtBorders1() {
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

void test_getMaxValuePos_maxAtBorders2() {
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

void test_getMaxValuePos_maxAtCenter() {
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

void test_getMaxValuePos_maxInLargeMatrix() {
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
    test_getMaxValuePos_maxAtBorders1();
    test_getMaxValuePos_maxAtBorders2();
    test_getMaxValuePos_maxAtCenter();
    test_getMaxValuePos_maxInLargeMatrix();
}

void test_getMinValuePos() {
    test_getMinValuePos_minAtBorders1();
    test_getMinValuePos_minAtBorders2();
    test_getMinValuePos_minInCenter();
    test_getMinValuePos_minInLargeMatrix();
}

void test_transposeSquareMatrix() {
    test_transposeSquareMatrix_matrix2x2();
    test_transposeSquareMatrix_matrix1x1();
    test_transposeSquareMatrix_matrix3x3();
}

void test_isSymmetricMatrix() {
    test_isSymmetricMatrix_atBorders1();
    test_isSymmetricMatrix_atBorders2();
    test_isSymmetricMatrix_matrix1x1();
    test_isSymmetricMatrix_withoutMistakes();
    test_isSymmetricMatrix_noSquare();

}

void test_isEMatrix() {
    test_isEMatrix_withoutMistakes1();
    test_isEMatrix_atCorner1();
    test_isEMatrix_atCorner2();
    test_isEMatrix_withoutMistakes2();
    test_isEMatrix_noSquare();
}

void test_twoMatricesEqual() {
    test_twoMatricesEqual_withoutMistakes();
    test_twoMatricesEqual_atCorner();
    test_twoMatricesEqual_noEqualRows();
}

void test_isSquareMatrix() {
    test_isSquareMatrix_withoutMistakes();
    test_isSquareMatrix_noSquare();
}

void test_insertionSortColsMatrixByColCriteria() {
    test_insertionSortColsMatrixByColCriteria_withoutMistakes();
    test_insertionSortColsMatrixByColCriteria_maxColsAtBorder();
    test_insertionSortColsMatrixByColCriteria_NonIncreasing();
    test_insertionSortColsMatrixByColCriteria_minColAtBorder();
    test_insertionSortColsMatrixByColCriteria_oneRow();
}

void test_insertionSortRowsMatrixByRowCriteria() {
    test_insertionSortRowsMatrixByRowCriteria_allRowsDescending();
    test_insertionSortRowsMatrixByRowCriteria_oneRows();
    test_insertionSortRowsMatrixByRowCriteria_randomPositionRows();
    test_insertionSortRowsMatrixByRowCriteria_maxRowsInBottom();
}

void test_swapColumns() {
    test_swapColumns_neighboursCols();
    test_swapColumns_colsAtBorders();
    test_swapColumns_oneColAtBorder();
    test_swapColumns_largeCounterRows();
}

void test_swapRows() {
    test_swapRows_oneRowAtBorder1();
    test_swapRows_atBorders();
    test_swapRows_equalRowsForSwap();
    test_swapRows_atCenter();
}

void test_matrixFunctions() {
    test_swapRows();
    test_swapColumns();
    test_insertionSortColsMatrixByColCriteria();
    test_insertionSortRowsMatrixByRowCriteria();
    test_isSquareMatrix();
    test_twoMatricesEqual();
    test_isEMatrix();
    test_isSymmetricMatrix();
    test_transposeSquareMatrix();
    test_getMinValuePos();
    test_getMaxValuePos();
}
// --------------------------------------------------------------------------

void test_sortRowsByMaxElement_maxInCenter() {
    matrix matrix1 = createMatrixFromArray(
            (int[]) {
                    7, 1, 2,
                    1, 8, 1,
                    3, 2, 3
            },
            3, 3
    );
    sortRowsByMaxElement(matrix1);

    matrix matrix2 = createMatrixFromArray(
            (int[]) {
                    3, 2, 3,
                    7, 1, 2,
                    1, 8, 1
            },
            3, 3
    );

    assert(twoMatricesEqual(matrix1, matrix2));

    freeMemMatrix(matrix1);
    freeMemMatrix(matrix2);
}

void test_sortRowsByMaxElement_withoutMistake() {
    matrix matrix1 = createMatrixFromArray(
            (int[]) {
                    1, 1, 2,
                    1, 2, 1,
                    3, 1, 3
            },
            3, 3
    );
    sortRowsByMaxElement(matrix1);

    matrix matrix2 = createMatrixFromArray(
            (int[]) {
                    1, 1, 2,
                    1, 2, 1,
                    3, 1, 3
            },
            3, 3
    );

    assert(twoMatricesEqual(matrix1, matrix2));

    freeMemMatrix(matrix1);
    freeMemMatrix(matrix2);
}

void test_sortRowsByMaxElement_allRowsEqual() {
    matrix matrix1 = createMatrixFromArray(
            (int[]) {
                    1, 1, 1,
                    1, 1, 1,
                    1, 1, 1
            },
            3, 3
    );
    sortRowsByMaxElement(matrix1);

    matrix matrix2 = createMatrixFromArray(
            (int[]) {
                    1, 1, 1,
                    1, 1, 1,
                    1, 1, 1
            },
            3, 3
    );

    assert(twoMatricesEqual(matrix1, matrix2));

    freeMemMatrix(matrix1);
    freeMemMatrix(matrix2);
}

void test_sortRowsByMaxElement_onlyOneElementInMatrix() {
    matrix matrix1 = createMatrixFromArray(
            (int[]) {
                    1
            },
            1, 1
    );
    sortRowsByMaxElement(matrix1);

    matrix matrix2 = createMatrixFromArray(
            (int[]) {
                    1
            },
            1, 1
    );

    assert(twoMatricesEqual(matrix1, matrix2));

    freeMemMatrix(matrix1);
    freeMemMatrix(matrix2);
}

void test_sortRowsByMaxElement_isNonDescending() {
    matrix matrix1 = createMatrixFromArray(
            (int[]) {
                    1, 1, 1, 9,
                    1, 1, 1, 2,
                    1, 1, 1, 1
            },
            3, 4
    );
    sortRowsByMaxElement(matrix1);

    matrix matrix2 = createMatrixFromArray(
            (int[]) {
                    1, 1, 1, 1,
                    1, 1, 1, 2,
                    1, 1, 1, 9
            },
            3, 4
    );

    assert(twoMatricesEqual(matrix1, matrix2));

    freeMemMatrix(matrix1);
    freeMemMatrix(matrix2);
}

void test_sortRowsByMaxElement() {
    test_sortRowsByMaxElement_maxInCenter();
    test_sortRowsByMaxElement_withoutMistake();
    test_sortRowsByMaxElement_allRowsEqual();
    test_sortRowsByMaxElement_onlyOneElementInMatrix();
    test_sortRowsByMaxElement_isNonDescending();
}

void test_sortColsByMinElement_maxInCenter() {
    matrix matrix1 = createMatrixFromArray(
            (int[]) {
                    -7, 1, 2,
                    1, -8, -1,
                    3, 2, 3
            },
            3, 3
    );
    sortColsByMinElement(matrix1);

    matrix matrix2 = createMatrixFromArray(
            (int[]) {
                    1, -7, 2,
                    -8, 1, -1,
                    2, 3, 3
            },
            3, 3
    );

    assert(twoMatricesEqual(matrix1, matrix2));

    freeMemMatrix(matrix1);
    freeMemMatrix(matrix2);
}

void test_sortColsByMinElement_withoutMistake() {
    matrix matrix1 = createMatrixFromArray(
            (int[]) {
                    1, 1, 2,
                    1, 2, 2,
                    3, 1, 3
            },
            3, 3
    );
    sortColsByMinElement(matrix1);

    matrix matrix2 = createMatrixFromArray(
            (int[]) {
                    1, 1, 2,
                    1, 2, 2,
                    3, 1, 3
            },
            3, 3
    );

    assert(twoMatricesEqual(matrix1, matrix2));

    freeMemMatrix(matrix1);
    freeMemMatrix(matrix2);
}

void test_sortColsByMinElement_allRowsEqual() {
    matrix matrix1 = createMatrixFromArray(
            (int[]) {
                    1, 1, 1,
                    1, 1, 1,
                    1, 1, 1
            },
            3, 3
    );
    sortColsByMinElement(matrix1);

    matrix matrix2 = createMatrixFromArray(
            (int[]) {
                    1, 1, 1,
                    1, 1, 1,
                    1, 1, 1
            },
            3, 3
    );

    assert(twoMatricesEqual(matrix1, matrix2));

    freeMemMatrix(matrix1);
    freeMemMatrix(matrix2);

}

void test_sortColsByMinElement_onlyOneElementInMatrix() {
    matrix matrix1 = createMatrixFromArray(
            (int[]) {
                    1
            },
            1, 1
    );
    sortColsByMinElement(matrix1);

    matrix matrix2 = createMatrixFromArray(
            (int[]) {
                    1
            },
            1, 1
    );

    assert(twoMatricesEqual(matrix1, matrix2));

    freeMemMatrix(matrix1);
    freeMemMatrix(matrix2);

}

void test_sortColsByMinElement_isNonDescending() {
    matrix matrix1 = createMatrixFromArray(
            (int[]) {
                    -3, 1, -1, 9,
                    1, -2, 1, 10,
                    1, 1, 1, 11
            },
            3, 4
    );
    sortColsByMinElement(matrix1);

    matrix matrix2 = createMatrixFromArray(
            (int[]) {
                    9, -1, 1, -3,
                    10, 1, -2, 1,
                    11, 1, 1, 1
            },
            3, 4
    );

    assert(!twoMatricesEqual(matrix1, matrix2));

    freeMemMatrix(matrix1);
    freeMemMatrix(matrix2);
}

void test_sortColsByMinElement() {
    test_sortColsByMinElement_maxInCenter();
    test_sortColsByMinElement_withoutMistake();
    test_sortColsByMinElement_allRowsEqual();
    test_sortColsByMinElement_onlyOneElementInMatrix();
    test_sortColsByMinElement_isNonDescending();
}

void test_getSquareOfMatrixIfSymmetric1() {
    matrix matrix1 = createMatrixFromArray(
            (int[]) {
                    1, 3,
                    3, 4
            },
            2, 2
    );
    getSquareOfMatrixIfSymmetric(&matrix1);

    matrix matrix2 = createMatrixFromArray(
            (int[]) {
                    10, 15,
                    15, 25
            },
            2, 2
    );

    assert(twoMatricesEqual(matrix1, matrix2));

    freeMemMatrix(matrix1);
    freeMemMatrix(matrix2);
}

void test_getSquareOfMatrixIfSymmetric2() {
    matrix matrix1 = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    2, 3, 5,
                    3, 5, 3
            },
            3, 3
    );
    getSquareOfMatrixIfSymmetric(&matrix1);

    matrix matrix2 = createMatrixFromArray(
            (int[]) {
                    14, 23, 22,
                    23, 38, 36,
                    22, 36, 43
            },
            3, 3
    );

    assert(twoMatricesEqual(matrix1, matrix2));

    freeMemMatrix(matrix1);
    freeMemMatrix(matrix2);
}

void test_getSquareOfMatrixIfSymmetric3() {
    matrix matrix1 = createMatrixFromArray(
            (int[]) {
                    2
            },
            1, 1
    );
    getSquareOfMatrixIfSymmetric(&matrix1);

    matrix matrix2 = createMatrixFromArray(
            (int[]) {
                    4
            },
            1, 1
    );

    assert(twoMatricesEqual(matrix1, matrix2));

    freeMemMatrix(matrix1);
    freeMemMatrix(matrix2);
}

void test_getSquareOfMatrixIfSymmetric() {
    test_getSquareOfMatrixIfSymmetric1();
    test_getSquareOfMatrixIfSymmetric2();
    test_getSquareOfMatrixIfSymmetric3();
}

void test_transposeIfMatrixHasntEqualSumOfRows_haventEqualSums1() {
    matrix matrix1 = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    4, 5, 6,
                    7, 8, 9
            },
            3, 3
    );
    transposeIfMatrixHasEqualSumOfRows(matrix1);

    matrix matrix2 = createMatrixFromArray(
            (int[]) {
                    1, 4, 7,
                    2, 5, 6,
                    3, 8, 9
            },
            3, 3
    );

    assert(twoMatricesEqual(matrix1, matrix2));

    freeMemMatrix(matrix1);
    freeMemMatrix(matrix2);
}

void test_transposeIfMatrixHasntEqualSumOfRows_haventEqualSums2() {
    matrix matrix1 = createMatrixFromArray(
            (int[]) {
                    1, 2, 0,
                    0, 5, 6,
                    7, 8, 9
            },
            3, 3
    );
    transposeIfMatrixHasEqualSumOfRows(matrix1);

    matrix matrix2 = createMatrixFromArray(
            (int[]) {
                    1, 0, 7,
                    2, 5, 6,
                    0, 8, 9
            },
            3, 3
    );

    assert(twoMatricesEqual(matrix1, matrix2));

    freeMemMatrix(matrix1);
    freeMemMatrix(matrix2);
}

void test_transposeIfMatrixHasntEqualSumOfRows_equalSums() {
    matrix matrix1 = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    0, 0, 6,
                    7, 8, 9
            },
            3, 3
    );
    transposeIfMatrixHasEqualSumOfRows(matrix1);

    matrix matrix2 = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    0, 0, 6,
                    7, 8, 9
            },
            3, 3
    );

    assert(twoMatricesEqual(matrix1, matrix2));

    freeMemMatrix(matrix1);
    freeMemMatrix(matrix2);
}

void test_transposeIfMatrixHasntEqualSumOfRows() {
    test_transposeIfMatrixHasntEqualSumOfRows_haventEqualSums1();
    test_transposeIfMatrixHasntEqualSumOfRows_haventEqualSums2();
    test_transposeIfMatrixHasntEqualSumOfRows_equalSums();
}

void test_isMutuallyInverseMatrices_withoutMistakes() {
    matrix matrix1 = createMatrixFromArray(
            (int[]) {
                    2, 3,
                    3, 4
            },
            2, 2
    );

    matrix matrix2 = createMatrixFromArray(
            (int[]) {
                    -4, 3,
                    3, -2
            },
            2, 2
    );

    assert(isMutuallyInverseMatrices(matrix1, matrix2));

    freeMemMatrix(matrix1);
    freeMemMatrix(matrix2);
}

void test_isMutuallyInverseMatrices1() {
    matrix matrix1 = createMatrixFromArray(
            (int[]) {
                    2, 3,
                    3, 4
            },
            2, 2
    );

    matrix matrix2 = createMatrixFromArray(
            (int[]) {
                    -4, 1,
                    3, -2
            },
            2, 2
    );

    assert(!isMutuallyInverseMatrices(matrix1, matrix2));

    freeMemMatrix(matrix1);
    freeMemMatrix(matrix2);
}

void test_isMutuallyInverseMatrices_matrixE() {
    matrix matrix1 = createMatrixFromArray(
            (int[]) {
                    1, 0,
                    0, 1
            },
            2, 2
    );

    matrix matrix2 = createMatrixFromArray(
            (int[]) {
                    1, 0,
                    0, 1
            },
            2, 2
    );

    assert(isMutuallyInverseMatrices(matrix1, matrix2));

    freeMemMatrix(matrix1);
    freeMemMatrix(matrix2);
}

void test_isMutuallyInverseMatrices_matrixEWith1Mistake() {
    matrix matrix1 = createMatrixFromArray(
            (int[]) {
                    1, 1,
                    0, 1
            },
            2, 2
    );

    matrix matrix2 = createMatrixFromArray(
            (int[]) {
                    1, 0,
                    0, 1
            },
            2, 2
    );

    assert(!isMutuallyInverseMatrices(matrix1, matrix2));

    freeMemMatrix(matrix1);
    freeMemMatrix(matrix2);
}

void test_isMutuallyInverseMatrices_largeMatrix() {
    matrix matrix1 = createMatrixFromArray(
            (int[]) {
                    2, 5, 7,
                    6, 3, 4,
                    5, -2, -3
            },
            3, 3
    );

    matrix matrix2 = createMatrixFromArray(
            (int[]) {
                    1, -1, 1,
                    -38, 41, -34,
                    27, -29, 24
            },
            3, 3
    );

    assert(isMutuallyInverseMatrices(matrix1, matrix2));

    freeMemMatrix(matrix1);
    freeMemMatrix(matrix2);
}

void test_isMutuallyInverseMatrices() {
    test_isMutuallyInverseMatrices1();
    test_isMutuallyInverseMatrices_largeMatrix();
    test_isMutuallyInverseMatrices_matrixE();
    test_isMutuallyInverseMatrices_matrixEWith1Mistake();
    test_isMutuallyInverseMatrices_withoutMistakes();
}

void test_findSumOfMaxesOfPseudoDiagonal_correctnessCheck() {
    matrix matrix1 = createMatrixFromArray(
            (int[]) {
                    3, 2, 5, 4,
                    1, 3, 6, 3,
                    3, 2, 1, 2
            },
            3, 4
    );

    assert(findSumOfMaxesOfPseudoDiagonal(matrix1) == 20);

    freeMemMatrix(matrix1);
}

void test_findSumOfMaxesOfPseudoDiagonal_squareMatrix() {
    matrix matrix1 = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    4, 5, 6,
                    7, 8, 9,
            },
            3, 3
    );

    assert(findSumOfMaxesOfPseudoDiagonal(matrix1) == 24);

    freeMemMatrix(matrix1);
}

void test_findSumOfMaxesOfPseudoDiagonal_matrix1x1() {
    matrix matrix1 = createMatrixFromArray(
            (int[]) {
                    1
            },
            1, 1
    );

    assert(findSumOfMaxesOfPseudoDiagonal(matrix1) == 0);

    freeMemMatrix(matrix1);
}

void test_findSumOfMaxesOfPseudoDiagonal_oneRow() {
    matrix matrix1 = createMatrixFromArray(
            (int[]) {
                    3, 2, 1, 2,

            },
            1, 4
    );

    assert(findSumOfMaxesOfPseudoDiagonal(matrix1) == 5);

    freeMemMatrix(matrix1);
}

void test_findSumOfMaxesOfPseudoDiagonal_oneCol() {
    matrix matrix1 = createMatrixFromArray(
            (int[]) {
                    3,
                    1,
                    4
            },
            3, 1
    );

    assert(findSumOfMaxesOfPseudoDiagonal(matrix1) == 5);

    freeMemMatrix(matrix1);
}

void test_findSumOfMaxesOfPseudoDiagonal() {
    test_findSumOfMaxesOfPseudoDiagonal_correctnessCheck();
    test_findSumOfMaxesOfPseudoDiagonal_matrix1x1();
    test_findSumOfMaxesOfPseudoDiagonal_oneCol();
    test_findSumOfMaxesOfPseudoDiagonal_oneRow();
    test_findSumOfMaxesOfPseudoDiagonal_squareMatrix();
}

void test_getMinInArea_maxAndMinAtBordersBottomUpper() {
    matrix matrix1 = createMatrixFromArray(
            (int[]) {
                    10, 7, 5, 6,
                    3, 11, 8, 9,
                    4, 1, 12, 2
            },
            3, 4
    );

    assert(getMinInArea(matrix1) == 5);

    freeMemMatrix(matrix1);
}

void test_getMinInArea_maxAtMiddleRow() {
    matrix matrix1 = createMatrixFromArray(
            (int[]) {
                    6, 8, 9, 2,
                    7, 12, 3, 4,
                    10, 11, 5, 1
            },
            3, 4
    );

    assert(getMinInArea(matrix1) == 6);

    freeMemMatrix(matrix1);
}

void test_getMinInArea_maxAtLeftCornerBottom() {
    matrix matrix1 = createMatrixFromArray(
            (int[]) {
                    6, 8, 9, 2,
                    7, 12, 3, 4,
                    13, 11, 5, 1
            },
            3, 4
    );

    assert(getMinInArea(matrix1) == 6);

    freeMemMatrix(matrix1);
}

void test_getMinInArea_maxAtLeftCornerUpper() {
    matrix matrix1 = createMatrixFromArray(
            (int[]) {
                    20, 8, 9, 2,
                    7, 12, 3, 4,
                    13, 11, 5, 1
            },
            3, 4
    );

    assert(getMinInArea(matrix1) == 20);

    freeMemMatrix(matrix1);
}

void test_getMinInArea_minAtLeftUpperCorner() {
    matrix matrix1 = createMatrixFromArray(
            (int[]) {
                    -1, 8, 9, 2,
                    7, 12, 3, 4,
                    13, 11, 30, 1
            },
            3, 4
    );

    assert(getMinInArea(matrix1) == -1);

    freeMemMatrix(matrix1);
}

void test_getMinInArea_minAtRightUpperCorner() {
    matrix matrix1 = createMatrixFromArray(
            (int[]) {
                    2, 8, 9, -1,
                    7, 12, 3, 4,
                    13, 11, 30, 1
            },
            3, 4
    );

    assert(getMinInArea(matrix1) == -1);

    freeMemMatrix(matrix1);
}

void test_getMinInArea() {
    test_getMinInArea_maxAndMinAtBordersBottomUpper();
    test_getMinInArea_maxAtLeftCornerBottom();
    test_getMinInArea_maxAtLeftCornerUpper();
    test_getMinInArea_maxAtMiddleRow();
    test_getMinInArea_minAtRightUpperCorner();
    test_getMinInArea_maxAtMiddleRow();
    test_getMinInArea_minAtLeftUpperCorner();
}

void test_sortByDistancesByNonDecreasing_nonIncreasing() {
    matrix matrix1 = createMatrixFromArray(
            (int[]) {
                    10, 10, 10, 10,
                    5, 5, 5, 5,
                    1, 1, 1, 1
            },
            3, 4
    );

    sortByDistancesByNonDecreasing(matrix1);
    matrix matrix2 = createMatrixFromArray(
            (int[]) {
                    1, 1, 1, 1,
                    5, 5, 5, 5,
                    10, 10, 10, 10
            },
            3, 4
    );

    assert(twoMatricesEqual(matrix1, matrix2));

    freeMemMatrix(matrix1);
    freeMemMatrix(matrix2);
}

void test_sortByDistancesByNonDecreasing_randomRows() {
    matrix matrix1 = createMatrixFromArray(
            (int[]) {
                    5, 5, 5, 5,
                    10, 10, 10, 10,
                    1, 1, 1, 1,
            },
            3, 4
    );

    sortByDistancesByNonDecreasing(matrix1);
    matrix matrix2 = createMatrixFromArray(
            (int[]) {
                    1, 1, 1, 1,
                    5, 5, 5, 5,
                    10, 10, 10, 10
            },
            3, 4
    );

    assert(twoMatricesEqual(matrix1, matrix2));

    freeMemMatrix(matrix1);
    freeMemMatrix(matrix2);
}

void test_sortByDistancesByNonDecreasing() {
    test_sortByDistancesByNonDecreasing_nonIncreasing();
    test_sortByDistancesByNonDecreasing_randomRows();
}

void test_countEqClassesByRowsSum_oneRowWithoutEqClasses() {
    matrix matrix1 = createMatrixFromArray(
            (int[]) {
                    1, 1,
                    2, 0,
                    3, 3
            },
            3, 2
    );

    assert(countEqClassesByRowsSum(matrix1) == 1);

    freeMemMatrix(matrix1);
}

void test_countEqClassesByRowsSum_allRowsWithoutEqClasses() {
    matrix matrix1 = createMatrixFromArray(
            (int[]) {
                    1, 0,
                    2, 0,
                    3, 3
            },
            3, 2
    );

    assert(countEqClassesByRowsSum(matrix1) == 0);

    freeMemMatrix(matrix1);
}

void test_countEqClassesByRowsSum_allRowsEqualSum() {
    matrix matrix1 = createMatrixFromArray(
            (int[]) {
                    1, 0,
                    0, 1,
                    -1, 2
            },
            3, 2
    );

    assert(countEqClassesByRowsSum(matrix1) == 1);

    freeMemMatrix(matrix1);
}

void test_countEqClassesByRowsSum_largeRows() {
    matrix matrix1 = createMatrixFromArray(
            (int[]) {
                    1, 0,
                    0, 1,
                    -1, 2,
                    5, 0,
                    0, 5,
                    10, 0,
                    9, 0,
                    2, -1,
                    7, 0,
                    0, 7

            },
            10, 2
    );

    assert(countEqClassesByRowsSum(matrix1) == 3);

    freeMemMatrix(matrix1);
}

void test_countEqClassesByRowsSum() {
    test_countEqClassesByRowsSum_oneRowWithoutEqClasses();
    test_countEqClassesByRowsSum_allRowsWithoutEqClasses();
    test_countEqClassesByRowsSum_allRowsEqualSum();
    test_countEqClassesByRowsSum_largeRows();
}

void test_getCounterSpecialElement_largeCols() {
    matrix matrix1 = createMatrixFromArray(
            (int[]) {
                    1000, 0,
                    0, 1,
                    -1, 2,
                    5, 0,
                    0, 5,
                    10, 0,
                    9, 0,
                    2, -1,
                    7, 300,
                    0, 7

            },
            10, 2
    );

    assert(getCounterSpecialElement(matrix1) == 2);

    freeMemMatrix(matrix1);

}

void test_getCounterSpecialElement_noSpecial() {
    matrix matrix1 = createMatrixFromArray(
            (int[]) {
                    3, 4, 5,
                    6, 7, 8,
                    9, 10, 11

            },
            3, 3
    );

    assert(getCounterSpecialElement(matrix1) == 0);

    freeMemMatrix(matrix1);
}

void test_getCounterSpecialElement_specialAtBorders() {
    matrix matrix1 = createMatrixFromArray(
            (int[]) {
                    100, 2, 5,
                    6, 7, 8,
                    9, 10, 11,
                    3, 5, 100

            },
            4, 3
    );

    assert(getCounterSpecialElement(matrix1) == 2);

    freeMemMatrix(matrix1);
}

void test_getCounterSpecialElement_matrix1x1() {
    matrix matrix1 = createMatrixFromArray(
            (int[]) {
                    1

            },
            1, 1
    );

    assert(getCounterSpecialElement(matrix1) == 0);

    freeMemMatrix(matrix1);
}

void test_getCounterSpecialElement() {
    test_getCounterSpecialElement_largeCols();
    test_getCounterSpecialElement_noSpecial();
    test_getCounterSpecialElement_specialAtBorders();
    test_getCounterSpecialElement_matrix1x1();
}

void test_swapPenultimateRow_minAtLeftBorder() {
    matrix matrix1 = createMatrixFromArray(
            (int[]) {
                    1, 2, 5,
                    6, 7, 8,
                    9, 10, 11,

            },
            3, 3
    );
    swapPenultimateRow(matrix1, 0);

    matrix matrix2 = createMatrixFromArray(
            (int[]) {
                    1, 2, 5,
                    9, 6, 1,
                    9, 10, 11,

            },
            3, 3
    );

    assert(twoMatricesEqual(matrix1, matrix2));

    freeMemMatrix(matrix1);
    freeMemMatrix(matrix2);
}

void test_swapPenultimateRow_minAtCenterCol() {
    matrix matrix1 = createMatrixFromArray(
            (int[]) {
                    5, 2, 5,
                    6, 1, 8,
                    9, 10, 11,

            },
            3, 3
    );
    swapPenultimateRow(matrix1, 1);

    matrix matrix2 = createMatrixFromArray(
            (int[]) {
                    5, 2, 5,
                    2, 1, 10,
                    9, 10, 11,

            },
            3, 3
    );

    assert(twoMatricesEqual(matrix1, matrix2));

    freeMemMatrix(matrix1);
    freeMemMatrix(matrix2);
}

void test_swapPenultimateRow_minAtRightBorder() {
    matrix matrix1 = createMatrixFromArray(
            (int[]) {
                    5, 2, 5,
                    6, 2, 1,
                    9, 10, 11,

            },
            3, 3
    );
    swapPenultimateRow(matrix1, 2);

    matrix matrix2 = createMatrixFromArray(
            (int[]) {
                    5, 2, 5,
                    5, 1, 11,
                    9, 10, 11,

            },
            3, 3
    );

    assert(twoMatricesEqual(matrix1, matrix2));

    freeMemMatrix(matrix1);
    freeMemMatrix(matrix2);
}

void test_swapPenultimateRow() {
    test_swapPenultimateRow_minAtLeftBorder();
    test_swapPenultimateRow_minAtCenterCol();
    test_swapPenultimateRow_minAtRightBorder();
}

void test_getCountNonDescendingRowsMatrices1() {
    int a[] = {7, 9,
               1, 1,
               3, 3,
               1, 6,
            ////
               2, 3,
               4, 5,
               5, 4,
               2, 3,
            ////
               4, 7,
               1, 1,
               6, 7,
               2, 13,
            ////
               3, 1,
               2, 3,
               6, 1,
               2, 2};

    matrix *ms = createArrayOfMatrixFromArray(a, 4, 4, 2);

    assert(getCountNonDescendingRowsMatrices(ms, 4) == 2);

    freeMemMatrices(ms, 4);
}

void test_getCountNonDescendingRowsMatrices_nonDescendingRows() {
    int a[] = {7, 0,
               1, 1,
               3, 3,
               1, 6,
            ////
               2, 3,
               4, 5,
               5, 4,
               2, 3,
            ////
               4, -7,
               1, 1,
               6, 7,
               2, -13,
            ////
               3, 1,
               2, 3,
               6, 1,
               2, 2};

    matrix *ms = createArrayOfMatrixFromArray(a, 4, 4, 2);

    assert(getCountNonDescendingRowsMatrices(ms, 4) == 0);

    freeMemMatrices(ms, 4);
}

void test_getCountNonDescendingRowsMatrices() {
    test_getCountNonDescendingRowsMatrices1();
    test_getCountNonDescendingRowsMatrices_nonDescendingRows();
}

void test_getCountSpecialElementsInMatrixRows_specialElemsLocatedClose() {
    matrix matrix1 = createMatrixFromArray(
            (int[]) {
                    2, 3, 5, 5, 4,
                    6, 2, 3, 8, 12,
                    12, 12, 2, 1, 2

            },
            3, 5
    );
    assert(getCountSpecialElementsInMatrixRows(matrix1) == 4);

    freeMemMatrix(matrix1);
}

void test_getCountSpecialElementsInMatrixRows_noSpecialElems() {
    matrix matrix1 = createMatrixFromArray(
            (int[]) {
                    2, 3, 5, 5, -1,
                    6, 2, 3, 8, -2,
                    12, 12, 2, 1, -5

            },
            3, 5
    );
    assert(getCountSpecialElementsInMatrixRows(matrix1) == 0);

    freeMemMatrix(matrix1);
}

void test_getCountSpecialElementsInMatrixRows_specialElemsAtBorders() {
    matrix matrix1 = createMatrixFromArray(
            (int[]) {
                    2, 5, 5, 5, 9,
                    9, 5, 3, 8, 10,
                    12, 11, 2, 1, 13

            },
            3, 5
    );
    assert(getCountSpecialElementsInMatrixRows(matrix1) == 4);

    freeMemMatrix(matrix1);
}

void test_getCountSpecialElementsInMatrixRows_allElemsIsSpecial() {
    matrix matrix1 = createMatrixFromArray(
            (int[]) {
                    1, 2, 3, 4,
                    5, 6, 7, 8,
                    9, 10, 11, 12

            },
            3, 4
    );
    assert(getCountSpecialElementsInMatrixRows(matrix1) == 12);

    freeMemMatrix(matrix1);
}

void test_getCountSpecialElementsInMatrixRows_equalElems() {
    matrix matrix1 = createMatrixFromArray(
            (int[]) {
                    1, 1, 1, 1,
                    2, 2, 2, 2,
                    2, 2, 2, 2

            },
            3, 4
    );
    assert(getCountSpecialElementsInMatrixRows(matrix1) == 0);

    freeMemMatrix(matrix1);
}

void test_getCountSpecialElementsInMatrixRows() {
    test_getCountSpecialElementsInMatrixRows_specialElemsLocatedClose();
    test_getCountSpecialElementsInMatrixRows_noSpecialElems();
    test_getCountSpecialElementsInMatrixRows_specialElemsAtBorders();
    test_getCountSpecialElementsInMatrixRows_allElemsIsSpecial();
    test_getCountSpecialElementsInMatrixRows_equalElems();
}

void test_getVectorIndexWithMaxAngle_maxAtUpperBorder() {
    matrix matrix1 = createMatrixFromArray(
            (int[]) {
                    2, 2,
                    1, 2,
                    3, 3,
                    4, 4,
                    5, 5

            },
            5, 2
    );
    int a[] = {2, 2};

    assert(getVectorIndexWithMaxAngle(matrix1, a) == 0);

    freeMemMatrix(matrix1);
}

void test_getVectorIndexWithMaxAngle_maxAtLowerBorder() {
    matrix matrix1 = createMatrixFromArray(
            (int[]) {
                    1, 2,
                    3, 3,
                    4, 4,
                    5, 5,
                    2, 2

            },
            5, 2
    );
    int a[] = {2, 2};

    assert(getVectorIndexWithMaxAngle(matrix1, a) == 1);

    freeMemMatrix(matrix1);
}

void test_getVectorIndexWithMaxAngle_maxAtMiddle() {
    matrix matrix1 = createMatrixFromArray(
            (int[]) {
                    1, 1,
                    2, 2,
                    3, 3

            },
            3, 2
    );
    int a[] = {2, 2};

    assert(getVectorIndexWithMaxAngle(matrix1, a) == 1);

    freeMemMatrix(matrix1);
}

void test_getVectorIndexWithMaxAngle() {
    test_getVectorIndexWithMaxAngle_maxAtUpperBorder();
    test_getVectorIndexWithMaxAngle_maxAtLowerBorder();
    test_getVectorIndexWithMaxAngle_maxAtMiddle();
}

void test_functionsTasks() {
    test_sortRowsByMaxElement();
    test_sortColsByMinElement();
    test_getSquareOfMatrixIfSymmetric();
    test_transposeIfMatrixHasntEqualSumOfRows();
    test_isMutuallyInverseMatrices();
    test_findSumOfMaxesOfPseudoDiagonal();
    test_getMinInArea();
    test_sortByDistancesByNonDecreasing();
    test_countEqClassesByRowsSum();
    test_getCounterSpecialElement();
    test_swapPenultimateRow();
    test_getCountNonDescendingRowsMatrices();
    // тесты для задач со звездочкой***
    test_getCountSpecialElementsInMatrixRows();
    test_getVectorIndexWithMaxAngle();
}

int main() {
    test_functionsTasks();
    test_matrixFunctions();

    return 0;
}
