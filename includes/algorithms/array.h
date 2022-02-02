#ifndef INC_5B_ARRAY_H
#define INC_5B_ARRAY_H

#include <stdio.h>
#include <stdbool.h>
#include <memory.h>
#include <math.h>

bool isDecreasing(long long a, long long b);

bool isIncreasing(long long a, long long b);

int max(int a, int b);

void swap(int *a, int *b);

void inputArray(int *a, size_t n);

void outputArray(int *a, size_t n);

void append(int *a, size_t *n, int x);

int getMinElemArray(const int *a, size_t n);

int getMaxElemArray(const int *a, size_t n);

bool isEqualArray(const int *a, size_t sizeA, const int *b, size_t sizeB);

long long getSumArray(const int *a, size_t n);

int getMaxElement(const int *a, size_t n);

int getMinElement(const int *a, size_t n);

bool isUniqueArrayElements(const long long *a, size_t n);

double getDistance(const int *a, size_t n);

unsigned getCounterEqualElementsArray(const int *a, size_t n);

void insertionSort(long long *a, size_t n, bool(*condition)(long long, long long));

#endif //INC_5B_ARRAY_H
