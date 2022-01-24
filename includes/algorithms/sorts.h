#ifndef INC_5B_SORTS_H
#define INC_5B_SORTS_H

#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <stdbool.h>
#include <memory.h>

#include "array.h"

void selectionSort(int *a, size_t n, int (*conditionForSort)(int, int));

void insertionSort(int *a, size_t n, int (*conditionForSort)(int, int));

void bubbleSort(int *a, size_t n, int (*conditionForSort)(int, int));

void combSort(int *a, size_t n, int (*conditionForSort)(int, int));

void qSort(int *a, size_t n);

void countSort(int *a, size_t n);

void merge(const int *a, const size_t sizeA, const int *b, size_t sizeB, int *c);

static void
mergeSort_(int *source, size_t leftBorder, size_t rightBorder, int *buffer);

void mergeSort(int *a, size_t n);


#endif //INC_5B_SORTS_H
