#ifndef INC_5B_ARRAY_H
#define INC_5B_ARRAY_H

#include <stdio.h>
#include <stdbool.h>
#include <memory.h>
#include <math.h>
#include <stdlib.h>

void printExitCodeIfPtrIsNull(void *a);

bool isDecreasing(int a, int b);

bool isNonDecreasing(int a, int b);

bool isIncreasing(int a, int b);

bool isNoneIncreasing(int a, int b);

int max(int a, int b);

int min(int a, int b);

void swap(int *a, int *b);

void inputArray(int *a, size_t n);

void outputArray(int *a, size_t n);

void append(int *a, size_t *n, int x);

int getMinElemArray(const int *a, size_t n);

int getMaxElemArray(const int *a, size_t n);

size_t getMaxIndexArrayD(const double *a, size_t n);

bool isEqualArray(const int *a, size_t sizeA, const int *b, size_t sizeB);

int getSumArrayLL(const int *a, size_t n);

int getMaxElement(const int *a, size_t n);

double getMinElementD(const double *a, size_t n);

bool isUniqueArrayElements(const int *a, size_t n);

double getVectorLength(const int *a, size_t n);

unsigned getCounterEqualElementsArray(const int *a, size_t n);

bool isSortBy(const int *a, size_t n, bool(*condition)(int, int));

void insertionSort(int *a, size_t n, bool(*condition)(int, int));

unsigned getCounterElemXInArray(const int *a, size_t n, int x);

#endif //INC_5B_ARRAY_H
