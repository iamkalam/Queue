//through linkmemory or linklist
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class Queue
{
private:
    Node *head;
    Node *current;

public:
    Queue()
    {
        head = NULL;
        current = NULL;
    }

    // funtion to add node in back of list
    void Enqueue(int val)
    {
        Node *newnode = new Node(val);
        if (head == NULL)
        {
            head = current = newnode;
        }
        else
        {
            current->next = newnode;
            current = newnode;
        }
    }

    // remove funtion  from front of list


    // Remove function from front of list
    int Dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1; // Ensure a value is returned
        } else {
            int x = head->data;
            Node* temp = head;
            head = head->next;
            if (head == NULL) {
                current = NULL;
            }
            delete temp;
            return x;
        }
    }

    bool isEmpty()
    {
        return head == NULL;
    }

    void display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    };


};

    int main()
    {
        Queue q;
        int poppedvalue;
        q.Enqueue(10);
        q.Enqueue(20);
        q.Enqueue(30);
        q.display();
        poppedvalue = q.Dequeue();
        cout << "popped value is " << poppedvalue << endl;
        q.display();
        return 0;
    }
