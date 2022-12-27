#include <cstdlib>
#include <iostream>
using namespace std;

bool las_vegas(int arr[], int n, int a) {
  int i = 0;
  bool tag = false;

  while (true) {
    int b = rand() % n;
    b = arr[b];
    i += 1;

    if (b == a) {
      tag = true;
      break;
    }
  }
  return tag;
}

int main() {
  int arr[5] = {10, 14, 36, 64, 29};
  if (las_vegas(arr, sizeof(arr) / sizeof(arr[0]), 14)) {
    cout << "YES" << endl;
    return 0;
  }
  cout << "NO" << endl;
}