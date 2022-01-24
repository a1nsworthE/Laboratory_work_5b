#include "sorts.h"

// Сортировка Выбором >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void selectionSort(int *const a, const size_t n, int (*conditionForSort)(int, int)) {
    for (size_t i = 0; i < n; ++i) {
        size_t indexSwap = i;
        for (size_t j = i + 1; j < n; ++j)
            if (a[j] < a[indexSwap])
                indexSwap = j;
        swap(&a[i], &a[indexSwap]);
    }
}
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

// Сортировка Вставками >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void insertionSort(int *const a, const size_t n, int (*conditionForSort)(int, int)) {
    for (size_t i = 1; i < n; ++i) {
        int t = a[i];
        size_t j = i;
        while (j > 0 && a[j - 1] > t) {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = t;
    }
}
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

// Соритровка Пузырьком >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void bubbleSort(int *const a, const size_t n, int (*conditionForSort)(int, int)) {
    for (size_t i = 0; i < n - 1; ++i)
        for (size_t j = n - 1; j > i; j--)
            if (a[j] < a[j - 1])
                swap(&a[j - 1], &a[j]);
}
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

void combSort(int *const a, const size_t n, int (*conditionForSort)(int, int)) {
    size_t step = n;
    bool swapped = true;
    while (step > 1 || swapped) {
        if (step > 1)
            step /= 1.24733;
        swapped = false;
        for (size_t i = 0, j = i + step; j < n; ++i, ++j) {
            if (a[i] > a[j]) {
                swap(&a[i], &a[j]);
                swapped = true;
            }
        }
    }
}
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

// Быстрая сортировка >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void qSort(int *const a, const size_t n) {
    assert(n > 0);

    int leftBorder = 0;
    int rightBorder = n - 1;
    int middle = leftBorder + (rightBorder - leftBorder) / 2;
    int t = a[middle];

    do {
        // часть , где числа меньше t
        while (a[leftBorder] < t)
            leftBorder++;
        // часть , где числа больше t
        while (a[rightBorder] > t)
            rightBorder--;
        if (leftBorder <= rightBorder) {
            swap(&a[rightBorder], &a[leftBorder]);
            leftBorder++;
            rightBorder--;
        }
    } while (leftBorder <= rightBorder);

    if (leftBorder < n)
        qSort(a + leftBorder, n - leftBorder);
    if (rightBorder > 0)
        qSort(a, rightBorder + 1);
}
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

// Сортировка Подсчетом >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void countSort(int *const a, const size_t n) {
    assert(n > 0);

    int elemMin = getMinElemArray(a, n);
    int elemMax = getMaxElemArray(a, n);
    size_t sizeArrayCountNumbers = elemMax - elemMin + 1;
    int *arrayCountNumbers = (int *) calloc(sizeArrayCountNumbers, sizeof(int));
    for (size_t i = 0; i < n; ++i)
        arrayCountNumbers[a[i] - elemMin]++;

    size_t k = 0;
    for (int i = 0; i < sizeArrayCountNumbers; ++i) {
        int x = arrayCountNumbers[i];
        for (size_t j = 0; j < x; ++j)
            a[k++] = elemMin + i;
    }

    free(arrayCountNumbers);
}
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

// Сортировка Слиянием >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

void merge(const int *const a, const size_t sizeA, const int *const b, const size_t sizeB, int *const c) {
    size_t iReadA = 0;
    size_t iReadB = 0;
    while (iReadA < sizeA || iReadB < sizeB) {
        if (iReadB == sizeB || iReadA < sizeA && a[iReadA] < b[iReadB]) {
            c[iReadA + iReadB] = a[iReadA];
            iReadA++;
        } else {
            c[iReadA + iReadB] = b[iReadB];
            iReadB++;
        }
    }
}

static void
mergeSort_(int *source, const size_t leftBorder, const size_t rightBorder, int *buffer) {
    int sizeSource = (int) rightBorder - leftBorder;
    if (sizeSource <= 1)
        return;

    size_t middle = (leftBorder + rightBorder) / 2;
    mergeSort_(source, leftBorder, middle, buffer);
    mergeSort_(source, middle, rightBorder, buffer);

    merge(source + leftBorder, middle - leftBorder, source + middle, rightBorder - middle, buffer);

    if (memcmp(source + leftBorder, buffer, sizeSource * sizeof(int)) != 0)
        memcpy(source + leftBorder, buffer, sizeSource * sizeof(int));
}

void mergeSort(int *a, const size_t n) {
    int *buffer = (int *) malloc(n * sizeof(int));
    mergeSort_(a, 0, n, buffer);

    free(buffer);
}
