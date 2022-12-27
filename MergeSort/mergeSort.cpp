#include <chrono>
#include <iostream>
using namespace std;

void merge(int *arr, int left, int mid, int right) {
  int leftn = mid - left + 1;
  int rightn = right - mid;
  int leftarr[leftn];
  int rightarr[rightn];
  int i, j, k;
  for (int i = 0; i < leftn; i++) {
    leftarr[i] = arr[left + i];
  }
  for (int i = 0; i < leftn; i++) {
    rightarr[i] = arr[mid + 1 + i];
  }
  i = 0;
  j = 0;
  k = left;
  while (i < leftn && j < rightn) {
    if (leftarr[i] <= rightarr[j]) {
      arr[k] = leftarr[i];
      i++;
    } else {
      arr[k] = rightarr[j];
      j++;
    }
    k++;
  }
  while (i < leftn) {
    arr[k] = leftarr[i];
    i++;
    k++;
  }
  while (i < rightn) {
    arr[k] = rightarr[j];
    j++;
    k++;
  }
}

void mergeSort(int arr[], int left, int right) {

  if (left < right) {
    int mid = (left + right) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
  }
}
void display(int *arr, int n) {
  for (int i = 0; i < n; i++) {
    cout << arr[i] << "\t";
  }
  cout << endl;
}
auto Ctime() { return chrono::high_resolution_clock::now(); }

int main() {
  int arr[5] = {12, 60, 9, 122, 43};
  display(arr, 5);
  auto start = Ctime();
  mergeSort(arr, 0, 4);
  auto finish = Ctime();
  cout << "Time taken:"
       << chrono::duration_cast<chrono::nanoseconds>(finish - start).count()
       << "ns" << endl;

  display(arr, 5);
  return 0;
}