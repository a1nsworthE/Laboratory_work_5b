#include "array.h"

void printExitCodeIfPtrIsNull(void *a) {
    if (a == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }
}

int max(const int a, const int b) {
    return a > b ? a : b;
}

int min(const int a, const int b) {
    return a > b ? b : a;
}

void swap(int *const a, int *const b) {
    const int t = *a;
    *a = *b;
    *b = t;
}

bool isDecreasing(const int a, const int b) {
    return a > b;
}

bool isNonDecreasing(const int a, const int b) {
    return a <= b;
}

bool isIncreasing(const int a, const int b) {
    return a < b;
}

bool isNoneIncreasing(const int a, const int b) {
    return a >= b;
}

bool isSortBy(const int *a, const size_t n, bool(*condition)(int, int)) {
    for (register size_t i = 1; i < n; ++i)
        if (!condition(a[i - 1], a[i]))
            return false;
    return true;
}

void inputArray(int *const a, const size_t n) {
    for (register size_t i = 0; i < n; ++i)
        scanf("%d", &a[i]);
}

void outputArray(int *const a, const size_t n) {
    for (register size_t i = 0; i < n; ++i)
        printf("%d ", a[i]);
    printf("\n");
}

void append(int *const a, size_t *n, const int x) {
    a[*n] = x;
    (*n)++;
}

int getMinElemArray(const int *const a, const size_t n) {
    int elemMin = a[0];
    for (size_t i = 1; i < n; ++i)
        if (a[i] < elemMin)
            elemMin = a[i];

    return elemMin;
}

int getMaxElemArray(const int *a, const size_t n) {
    int elemMax = a[0];
    for (register size_t i = 1; i < n; ++i)
        if (a[i] > elemMax)
            elemMax = a[i];

    return elemMax;
}

size_t getMaxIndexArrayD(const double *a, size_t n) {
    double elemMax = a[0];
    size_t indexMax = 0;
    for (register size_t i = 1; i < n; ++i)
        if (a[i] > elemMax) {
            elemMax = a[i];
            indexMax = i;
        }

    return indexMax;
}

size_t getMinIndexElemArrayD(const double *a, const size_t n) {
    double elemMin = a[0];
    size_t indexMin = 0;
    for (register size_t i = 1; i < n; ++i)
        if (a[i] < elemMin) {
            elemMin = a[i];
            indexMin = i;
        }

    return indexMin;
}

bool isEqualArray(const int *a, const size_t sizeA, const int *b, const size_t sizeB) {
    if (sizeA == sizeB) {
        return memcmp(a, b, sizeof(int) * sizeA) == 0;
    } else
        return false;
}

int getSumArrayLL(const int *a, size_t n) {
    int sum = 0;
    for (size_t i = 0; i < n; ++i)
        sum += a[i];
    return sum;
}

int getMaxElement(const int *a, const size_t n) {
    int maxElement = a[0];
    for (register size_t i = 1; i < n; ++i)
        if (a[i] > maxElement)
            maxElement = a[i];

    return maxElement;
}

int getMinElement(const int *a, const size_t n) {
    int minElement = a[0];
    for (register size_t i = 1; i < n; ++i)
        if (a[i] < minElement)
            minElement = a[i];

    return minElement;
}

bool isUniqueArrayElements(const int *a, const size_t n) {
    for (register size_t i = 0; i < n - 1; ++i)
        for (register size_t j = i + 1; j < n; ++j)
            if (a[i] == a[j])
                return false;
    return true;
}

double getVectorLength(const int *a, size_t n) {
    int sum = 0;
    for (register size_t i = 0; i < n; ++i)
        sum += (a[i] * a[i]);
    return sqrt(sum);
}

unsigned getCounterEqualElementsArray(const int *a, const size_t n) {
    unsigned counterEquals = 0;
    for (register size_t i = 0; i < n - 1; ++i)
        for (register size_t j = i + 1; j < n; ++j)
            if (a[i] == a[j])
                counterEquals++;
    return counterEquals;
}

void insertionSort(int *a, const size_t n, bool(*condition)(int, int)) {
    for (register size_t i = 1; i < n; ++i) {
        int t = a[i];
        register int j = i;
        while (j > 0 && condition(a[j - 1], t)) {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = t;
    }
}

unsigned getCounterElemXInArray(const int *a, const size_t n, const int x) {
    unsigned counterElemX = 0;
    for (register size_t i = 0; i < n; ++i)
        if (a[i] == x)
            counterElemX++;

    return counterElemX;
}

double getMinElementD(const double *a, const size_t n) {
    double minElement = a[0];
    for (register size_t i = 1; i < n; ++i)
        if (a[i] < minElement)
            minElement = a[i];

    return minElement;
}
