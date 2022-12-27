### Lab 1

#### **OBJECTIVE:** TO IMPLEMENT PUSH AND POP OPERATION IN STACK AND ITS TIME EXPENDITURE

**THEORY:**
Stack is a data structure that only operates on the most recent item added, also known as LIFO (last-in, first-out). When a new item is added to the stack, it's called "pushing" that item onto the stack. When the most recent data item is retrieved and removed from the structure, it's called "popping" the item from the stack. These "push" and "pop" operations may apply to an array if the item added or removed is at the end of the array.
**SOURCE CODE:**

```c++
#include <chrono>
#include <iostream>
using namespace std;
#define MAX 4
class stack {
private:
  int top = -1;
  int stack[MAX];

public:
  bool isFull() {
    if (top >= MAX - 1) {
      cout << "Stack Overflow" << endl;
      return true;
    }
    return false;
  }
  bool isEmpty() {
    if (top == -1) {
      cout << "Stack is Empty" << endl;

      return true;
    }
    return false;
  }
  bool push(int item) {
    if (!isFull()) {
      top++;
      this->stack[top] = item;
      cout << "Element pushed" << endl;
      return 1;
    }
    return 0;
  }
  bool pop() {
    if (!isEmpty()) {
      this->stack[top] = 0;
      top--;
      cout << "Element poped" << endl;
      return 1;
    }
    return 0;
  }
  void display() {
    if (!isEmpty()) {
      cout << "The stack looks like:" << endl;
      for (int i = top; i >= 0; i--) {
        cout << stack[i] << endl;
      }
    }
  }
};
auto Ctime() {
    return chrono::high_resolution_clock::now();
}

int main() {
  stack s1;
  auto start = Ctime();
  s1.push(1);
  auto finish = Ctime();
  cout <<"Time taken:"<<chrono::duration_cast<chrono::nanoseconds>(finish - start).count()<<"ns"<<endl;
  start = Ctime();
  s1.pop();
  finish = Ctime();
  cout <<"Time taken:"<<chrono::duration_cast<chrono::nanoseconds>(finish - start).count()<<"ns"<<endl;
  s1.display();
}

int main() {
  stack s1;
  auto start = Ctime();
  s1.push(1);
  auto finish = Ctime();
  cout << chrono::duration_cast<chrono::nanoseconds>(finish - start).count()<<endl;
  start = Ctime();
  s1.pop();
  finish = Ctime();
  cout << chrono::duration_cast<chrono::nanoseconds>(finish - start).count()<<endl;
  s1.display();
}
```

**OUTPUT:**

```bash
Element pushed
Time taken:21940ns
Element poped
Time taken:18256ns
Stack is Empty
```

**OBSERVATION:** From output we can observe that time spent to push an element in the Stack was 21940ns and to pop an element form Stack was 18256ns
