#include <iostream>
#include <stack>
#include <queue>


using namespace std;


void reverse(queue <int >&q){
    stack <int > s;

    //dequeue all elements and push them to stack
    while(!q.empty()){
        s.push(q.front());
        q.pop(); //remove the elemets from the queue
    }

    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
}

void display(queue <int >q){
    while(!q.empty()){
        cout<<q.front()<<"";
        q.pop();
    }
    cout<<endl;
}
int main() {
    queue<int> q;

    // Enqueue elements into the queue
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    cout << "Original Queue: ";
    display(q);

    // Reverse the queue
    reverse(q);

    cout << "Reversed Queue: ";
    display(q);

    return 0;
}