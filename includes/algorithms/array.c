#include "array.h"

void swap(int *const a, int *const b) {
    const int t = *a;
    *a = *b;
    *b = t;
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

int getSumArray(const int *a, size_t n) {
    int sum = 0;
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

long long getMinElement(const int *a, const size_t n) {
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