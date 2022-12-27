#include <iostream>
#include <chrono>
#define LEN 7
using namespace std;

int partation(int *array, int lb, int ub) {
  int up, down, pivot, hold;
  pivot = array[lb];
  up = ub;
  down = lb;
  while (down < up) {
    while (array[down] <= pivot && down < ub) {
      down++;
    }
    while (array[up] > pivot) {
      up--;
    }
    if (up > down) {
      hold = array[up];
      array[up] = array[down];
      array[down] = hold;
    }
  }
  array[lb] = array[up];
  array[up] = pivot;
  return up;
}

// taking
void quickSort(int array[], int lb, int ub) {

  if (lb < ub) {
    int pi = partation(array, lb, ub);
    quickSort(array, lb, pi - 1);
    quickSort(array, pi + 1, ub);
  }
}

auto Ctime() { return chrono::high_resolution_clock::now(); }

int main() {
  int array[LEN] = {31, 34, 65, 22, 165, 32, 7};
  cout << "Unsorted Array:" << endl;
  for (int i = 0; i< LEN; i++) {
    cout << array[i] << "\t";
  }
  cout<<endl;
  auto start = Ctime();
  quickSort(array, 0, LEN-1);
  auto finish = Ctime();
  cout <<"Time taken:"<<chrono::duration_cast<chrono::nanoseconds>(finish - start).count()<<"ns"<<endl;
  cout << "Sorted Array:" << endl;
  for (int i = 0; i<LEN; i++) {
    cout << array[i] << "\t";
  }
  cout << endl;
}