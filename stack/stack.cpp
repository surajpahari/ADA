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