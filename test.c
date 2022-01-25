#include <stdio.h>
#include <stdbool.h>
#include "includes/algorithms/matrix.h"

/* void test_matrix_swapRows_() {
    matrix m = createMatrixFromArray(
            (int[]) {

            },


    );

    swapRows(m, ,);

    assert(
            isEqualArray((int[]) {}, , m.values[],)
            &&
            isEqualArray((int[]) {}, , m.values[],)
    );
} */

/* void test_matrix_swapColumns_() {
    matrix m = createMatrixFromArray(
            (int[]) {

            },


    );

    swapColumns(m, ,);

    assert(
            isEqualArray((int[]) {}, , m.values[],)
            &&
            isEqualArray((int[]) {}, , m.values[],)
    );
} */

/* void test_insertionSortRowsMatrixByRowCriteria() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    , , ,
                    , , ,
                    , , ,
            }, ,
    );

    insertionSortRowsMatrixByRowCriteria(m, getSumArray);

    assert(
            isEqualArray((int[]) {, ,}, 3, m.values[0], 3)
            &&
            isEqualArray((int[]) {, ,}, 3, m.values[1], 3)
            &&
            isEqualArray((int[]) {, ,}, 3, m.values[2], 3)
    );

    freeMemMatrix(m);
} */

void test_matrix_swapRows1() {
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

void test_matrix_swapRows2() {
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


void test_matrix_swapRows3() {
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

void test_matrix_swapRows4() {
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

void test_matrix_swapColumns1() {
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

void test_matrix_swapColumns2() {
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

void test_matrix_swapColumns3() {
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

void test_matrix_swapColumns4() {
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

void test_insertionSortRowsMatrixByRowCriteria() {
    test_insertionSortRowsMatrixByRowCriteria1();
}

void test_matrix_swapColumns() {
    test_matrix_swapColumns1();
    test_matrix_swapColumns2();
    test_matrix_swapColumns3();
    test_matrix_swapColumns4();
}


void test_matrix_swapRows() {
    test_matrix_swapRows1();
    test_matrix_swapRows2();
    test_matrix_swapRows3();
    test_matrix_swapRows4();
}

void test_matrix() {
    test_matrix_swapRows();
    test_matrix_swapColumns();
    test_insertionSortRowsMatrixByRowCriteria();
}

int main() {
    test_matrix();

    return 0;
}