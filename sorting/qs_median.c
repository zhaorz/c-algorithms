// qs_median.c

// Find the median of an array using modified quicksort

#include <stdio.h>
#include <stdlib.h>

int median(int *arr, int n);

int partition(int *arr, int lo, int hi);
int kth_smallest(int *arr, int n, int k);
void swap(int *arr, int i, int j);

int median(int *arr, int n)
{
  return kth_smallest(arr, n, (n - 1) / 2);
}


void swap(int *arr, int i, int j)
{
  int tmp = arr[i];
  arr[i] = arr[j];
  arr[j] = tmp;
}

int partition(int *arr, int lo, int hi)
{
  int pivot, left, right;

  pivot = arr[lo];
  left  = lo;
  right = hi;

  while (left < right) {
    while (arr[left] <= pivot) left++;
    while (arr[right] > pivot) right--;

    if (left < right) {
      swap(arr, left, right);
    }
  }

  swap(arr, lo, right);
  return right;
}

/* kth_smallest(arr, n, k) => S[k] where S is a sorted version of arr */
int kth_smallest(int *arr, int n, int k)
{
  int pivot_idx, offset;

  if (n < 1)  return -1;
  if (n == 1) return arr[0];

  pivot_idx = partition(arr, 0, n - 1);

  if (pivot_idx == k) {
    return arr[k];
  }

  if (pivot_idx < k) {
    offset = pivot_idx + 1;
    return kth_smallest((arr + offset), n - offset, k - offset);
  } else {
    return kth_smallest(arr, pivot_idx, k);
  }
}

int main(int argc, char *argv[])
{
  int size;
  int *arr;

  scanf("%d", &size);

  arr = calloc(size, sizeof(int));

  for (int i = 0; i < size; i++) {
    scanf("%d", &arr[i]);
  }

  printf("%d\n", median(arr, size));

  return 0;
}
