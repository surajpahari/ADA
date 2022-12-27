### Lab 6

#### **OBJECTIVE:** TO IMPLEMENT MONTE CARLO RANDOMIZED ALGORITHM

**THEORY:** Monte Carlo algorithm is a randomized algorithm whose output may be incorrect with a certain (typically small) probability. This algorithm have deterministic running time and it is generally easier to find out worst case time complexity.

**SOURCE CODE:**

```c++
#include <cstdlib>
#include <iostream>
#include <time.h>
using namespace std;

bool monte_carlo(int arr[], int n, int a, int x) {
  srand(time(0));
  int i = 0;
  bool tag = false;

  while (i <= x) {
    int b = rand() % 5;
    b = arr[b];
    i += 1;
    if (b == a) {
      tag = true;
    }
  }

  return tag;
}

int main() {
  int arr[5] = {10, 25, 13, 16, 2};
  if (monte_carlo(arr, sizeof(arr) / sizeof(arr[0]), 25, 10)) {
    cout << "YES" << endl;
    return 0;
  }

  cout << "NO" << endl;
}
```
 
**CONCLUSION:** We finally uderstood the Monte Carlo alogrithm and implemented it.


