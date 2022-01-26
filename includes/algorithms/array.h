#ifndef INC_5B_ARRAY_H
#define INC_5B_ARRAY_H

#include <stdio.h>
#include <stdbool.h>
#include <memory.h>

void swap(int *a, int *b);

void inputArray(int *a, size_t n);

void outputArray(int *a, size_t n);

void append(int *a, size_t *n, int x);

int getMinElemArray(const int *a, size_t n);

int getMaxElemArray(const int *a, size_t n);

bool isEqualArray(const int *a, size_t sizeA, const int *b, size_t sizeB);

int getSumArray(const int *a, size_t n);

int getMaxElement(const int *a, size_t n);

int getMinElement(const int *a, size_t n);

#endif //INC_5B_ARRAY_H
