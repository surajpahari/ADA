#include <iostream>
#include <chrono>
using namespace std;
#define MAX 5

class Queue {

private:
  int front;
  int rear;
  int queue[MAX];

public:
  Queue() {

    front = -1;
    rear = -1;

    for (int i = 0; i < MAX; i++) {
      queue[i] = 0;
    }
  }

  bool isFull() {
    if (front == rear + 1) {
      return true;
    }
    if (front == 0 && rear == MAX - 1) {
      return true;
    }
    return false;
  }

  bool isEmpty() {
    if (rear == -1 && front == -1) {
      return true;
    }

    else {
      return false;
    }
  }

  void enqueue(int value) {
    if (!isFull()) {
      if (isEmpty()) {
        rear = 0;
        front = 0;
      } else {
        rear = (rear + 1) % MAX;
      }
      queue[rear] = value;
      // cout<<rear<<endl;
    }
  }

  void dequeue() {
    if (!isEmpty()) {
      int temp = queue[front];
      if (rear == front) {
        rear = -1;
        front = -1;
      }
      else {
        front = (front + 1) % MAX;
      }
    }
  }

  void display() {
    if (!isEmpty()) {
      int i;
      for (i = front; i != rear; i = (i + 1) % 5) {
        cout << queue[i] << "\t";
      }
      cout << queue[i];
      cout << endl;
    }
  }
};
auto Ctime() { 
    return chrono::high_resolution_clock::now(); 
}


int main(){
  Queue q1;  
  auto start = Ctime();
  q1.enqueue(17);
  auto finish = Ctime();
  cout<<"Enqueued"<<endl;
  cout <<"Time taken:"<<chrono::duration_cast<chrono::nanoseconds>(finish - start).count()<<"ns"<<endl;


  start = Ctime();
  q1.dequeue();
  finish = Ctime();
  cout<<"Dequeued"<<endl;
  cout <<"Time taken:"<<chrono::duration_cast<chrono::nanoseconds>(finish - start).count()<<"ns"<<endl;
  return 0;
 }