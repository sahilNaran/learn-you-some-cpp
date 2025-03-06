#include "07_pointers_and_references.h"

// Swap two integers using pointers
void swap_ptr(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

// Swap two integers using references
void swap_ref(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

// Reverse array elements in-place
void reverse_array(int arr[], int size) {
  int *start = arr;
  int *end = arr + size - 1;

  while (start < end) {
    int temp = *start;
    *start = *end;
    *end = temp;
    start++;
    end--;
  }
}

// Find the minimum and maximum values in an array
// Store results in the provided min and max pointers
void find_min_max(const int arr[], int size, int *min, int *max) {
  *min = arr[0];
  for (int i = 0; i < size; i++) {
    if (arr[i] < *min) {
      *min = arr[i];
    }

    if (arr[i] > *max) {
      *max = arr[i];
    }
  }
}
