#include "10_algorithm_basics.h"

int linear_search(const int arr[], int size, int value) {
  for (int i = 0; i < size; i++) {
    if (arr[i] == value) {
      return i;
    }
  }
  return -1;
}

// Binary search - return index of value or -1 if not found
// Assume array is sorted
int binary_search(const int arr[], int size, int value) {
  int left = 0;
  int right = size - 1;

  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (arr[mid] == value) {
      return mid;
    } else if (arr[mid] > value) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }
  return -1;
}

// Count occurrences of value in array - linear approach
int count_occurrences_linear(const int arr[], int size, int value) {
  int count = 0;
  for (int i = 0; i < size; i++) {
    if (arr[i] == value) {
      count++;
    }
  }
  return count;
}

// Count occurrences in a sorted array - more efficient approach
int count_occurrences_efficient(const int sorted_arr[], int size, int value) {
  int first = -1;
  int left = 0;
  int right = size - 1;

  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (sorted_arr[mid] == value) {
      first = mid;
      right = mid - 1;
    } else if (sorted_arr[mid] > value) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }

  if (first == -1) {
    return 0;
  }

  int last = -1;
  left = 0;
  right = size - 1;

  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (sorted_arr[mid] == value) {
      last = mid;
      left = mid + 1;
    } else if (sorted_arr[mid] > value) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }

  return last - first + 1;
}
