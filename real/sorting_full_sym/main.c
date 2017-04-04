#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <klee/klee.h>
#include "C-Sorting-Algorithms/selectionSort.h"

#ifdef DOUBLES
static void check(double* arr, size_t length) {
  for (size_t i = 1; i < length; ++i) {
    klee_assert(arr[i] >= arr[i - 1]);
  }
}

int main(int argc, char** argv) {
	double arr[] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
	klee_make_symbolic(&arr, sizeof(arr), "arr");
  for (size_t i=0; i < sizeof(arr)/sizeof(arr[0]); ++i) {
    klee_assume(!isnan(arr[i]));
  }
	selectionSortDouble(arr, sizeof(arr) / sizeof(arr[0]));

	check(arr, sizeof(arr) / sizeof(arr[0]));
}
#endif

#ifdef FLOATS
static void check(float* arr, size_t length) {
  for (size_t i = 1; i < length; ++i) {
    klee_assert(arr[i] >= arr[i - 1]);
  }
}

int main(int argc, char** argv) {
	float arr[] = {0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f};
	klee_make_symbolic(&arr, sizeof(arr), "arr");
  for (size_t i=0; i < sizeof(arr)/sizeof(arr[0]); ++i) {
    klee_assume(!isnan(arr[i]));
  }

	selectionSortFloat(arr, sizeof(arr) / sizeof(arr[0]));

	check(arr, sizeof(arr) / sizeof(arr[0]));
}
#endif
