#include <iostream>
using namespace std;

class Queue {
    private:
    int front;
    int rear;
    int size;
    int* queue;

    public:
    Queue(int s) {
        front = -1;   // -1 is the initial value of front and rear to indicate the array is empty
        rear = -1;
        size = s;
        queue = new int[s];
    }

    ~Queue() {
        delete[] queue;
    }

    bool Isempty() {
        return front == -1 && rear == -1;
    }

    bool Isfull() {
        return (rear + 1) % size == front;
    }

    void Enqueue(int val) {
        if (Isfull()) {
            cout << "Queue is full" << endl;
            return;
        } else if (Isempty()) {
            front = rear = 0; // Move the front and rear to the zero index
            queue[rear] = val; // Insert the value at the rear
        } else {
            rear = (rear + 1) % size; // Move the rear to the next cell, % size for circular representation
            queue[rear] = val;
        }
    }

    int Dequeue() {
        if (Isempty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        int x = queue[front];
        if (front == rear) { // If both are at the same index, reset to initial values
            front = rear = -1;
        } else {
            front = (front + 1) % size; // Move the front one step up
        }
        return x;
    }

    void display() {
        if (Isempty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        int i = front;
        while (true) {
            cout << queue[i] << " ";
            if (i == rear) break;
            i = (i + 1) % size;
        }
        cout << endl;
    }
};

int main() {
    Queue q(5); // Create a queue of size 5
    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);
    q.Enqueue(40);
    q.Enqueue(50);
    q.display();
    q.Dequeue();
    q.display();
    q.Enqueue(60);
    q.display();
    return 0;
}