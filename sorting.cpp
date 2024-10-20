#include <iostream>
#include <queue>
#include <climits>

using namespace std;

// Function to sort a queue in ascending order using selection sort-like approach
void sortQueue(queue<int>& q) {
    int n = q.size(); // Get the size of the queue
    for (int i = 0; i < n; i++) {
        int minIndex = -1; // Initialize the index of the minimum element
        int minValue = INT_MAX; // Initialize the minimum value to the maximum possible integer
        int size = q.size(); // Get the current size of the queue

        // Find the minimum element in the unsorted part of the queue
        for (int j = 0; j < size; j++) {
            int curr = q.front(); // Get the front element of the queue
            q.pop(); // Remove the front element from the queue

            // Keep track of the minimum element and its index
            if (curr < minValue && j <= n - i - 1) {
                minValue = curr; // Update the minimum value
                minIndex = j; // Update the index of the minimum value
            }

            q.push(curr); // Push the current element back into the queue
        }

        // Move the minimum element to the end of the sorted part of the queue
        for (int j = 0; j < size; j++) {
            int curr = q.front(); // Get the front element of the queue
            q.pop(); // Remove the front element from the queue

            if (j != minIndex) {
                q.push(curr); // Push the current element back into the queue if it's not the minimum element
            }
        }

        // Push the minimum element to the back of the queue
        q.push(minValue);
    }
}

// Function to display the elements of the queue
void displayQueue(queue<int> q) {
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main() {
    queue<int> q;

    // Enqueue elements into the queue
    q.push(30);
    q.push(10);
    q.push(50);
    q.push(20);
    q.push(40);

    cout << "Original Queue: ";
    displayQueue(q);

    // Sort the queue
    sortQueue(q);

    cout << "Sorted Queue: ";
    displayQueue(q);

    return 0;
}