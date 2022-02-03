#include "array.h"

int max(const int a, const int b) {
    return a > b ? a : b;
}

void swap(int *const a, int *const b) {
    const int t = *a;
    *a = *b;
    *b = t;
}

bool isDecreasing(const long long a, const long long b) {
    return a > b;
}

bool isNonDecreasing(const long long a, const long long b) {
    return a <= b;
}

bool isIncreasing(const long long a, const long long b) {
    return a < b;
}

bool isNoneIncreasing(const long long a, const long long b) {
    return a >= b;
}

bool isSortBy(const int *a, const size_t n, bool(*condition)(long long, long long)) {
    for (size_t i = 1; i < n; ++i)
        if (!condition(a[i - 1], a[i]))
            return false;
    return true;
}

void inputArray(int *const a, const size_t n) {
    for (size_t i = 0; i < n; ++i)
        scanf("%d", &a[i]);
}

void outputArray(int *const a, const size_t n) {
    for (size_t i = 0; i < n; ++i)
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

int getMaxElemArray(const int *const a, const size_t n) {
    int elemMax = a[0];
    for (size_t i = 1; i < n; ++i)
        if (a[i] > elemMax)
            elemMax = a[i];

    return elemMax;
}

bool isEqualArray(const int *a, const size_t sizeA, const int *b, const size_t sizeB) {
    if (sizeA == sizeB) {
        return memcmp(a, b, sizeof(int) * sizeA) == 0;
    } else
        return false;
}

long long getSumArray(const int *a, size_t n) {
    long long sum = 0;
    for (size_t i = 0; i < n; ++i)
        sum += a[i];
    return sum;
}

int getMaxElement(const int *a, const size_t n) {
    int maxElement = a[0];
    for (size_t i = 1; i < n; ++i)
        if (a[i] > maxElement)
            maxElement = a[i];

    return maxElement;
}

int getMinElement(const int *a, const size_t n) {
    int minElement = a[0];
    for (size_t i = 1; i < n; ++i)
        if (a[i] < minElement)
            minElement = a[i];

    return minElement;
}

bool isUniqueArrayElements(const long long *a, const size_t n) {
    for (size_t i = 0; i < n - 1; ++i)
        for (size_t j = i + 1; j < n; ++j)
            if (a[i] == a[j])
                return false;
    return true;
}

double getDistance(const int *a, const size_t n) {
    long long sum = 0;
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

void insertionSort(long long *a, const size_t n, bool(*condition)(long long, long long)) {
    for (size_t i = 1; i < n; ++i) {
        long long t = a[i];
        long long j = i;
        while (j > 0 && condition(a[j - 1], t)) {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = t;
    }
}

unsigned getCounterElemXInArray(const int *a, const size_t n, const int x) {
    unsigned counterElemX = 0;
    for (size_t i = 0; i < n; ++i)
        if (a[i] == x)
            counterElemX++;

    return counterElemX;
}

double getMinElementD(const double *a, const size_t n) {
    double minElement = a[0];
    for (size_t i = 1; i < n; ++i)
        if (a[i] < minElement)
            minElement = a[i];

    return minElement;
}
