#include <iostream>
#include <stack>
#include <queue>
using namespace std;


bool palindrome(queue <int>&q){
    stack <int> s;
    queue <int> original_queue= q;

    while(!q.empty()){
        s.push(q.front());  //push the front element of the queue to the stack
        q.pop(); //remove the front element from the queue
    }

    //compare teh elements of the original queue and the stack
    while(!original_queue.empty()){
        if(original_queue.front() !=s.top()){
            return false;
        }
        original_queue.pop();
        s.pop();
    }
    return true;
}

void display(queue <int>    q){
    while(!q.empty()){
        cout<<q.front()<<""<<endl;
        q.pop();
    }
    cout<<endl;
}

int main() {
    queue<int> q;

    // Enqueue elements into the queue
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(2);
    q.push(1);

    cout << "Queue: ";
    display(q);

    // Check if the queue is a palindrome
    if (palindrome(q)) {
        cout << "The queue is a palindrome." << endl;
    } else {
        cout << "The queue is not a palindrome." << endl;
    }

    return 0;
}