#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class saad_lab7
{
private:
    vector<int> heap;
    bool isMinHeap; // true for MinHeap, false for MaxHeap

    void heapifyUp(int index)
    {
        if (index == 0)
            return;
        int parent = (index - 1) / 2;
        if ((isMinHeap && heap[parent] > heap[index]) || (!isMinHeap && heap[parent] < heap[index]))
        {
            swap(heap[parent], heap[index]);
            heapifyUp(parent);
        }
    }

    void heapifyDown(int index)
    {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int chosenChild = index;

        if (isMinHeap)
        {
            if (leftChild < heap.size() && heap[leftChild] < heap[chosenChild])
                chosenChild = leftChild;
            if (rightChild < heap.size() && heap[rightChild] < heap[chosenChild])
                chosenChild = rightChild;
        }
        else
        {
            if (leftChild < heap.size() && heap[leftChild] > heap[chosenChild])
                chosenChild = leftChild;
            if (rightChild < heap.size() && heap[rightChild] > heap[chosenChild])
                chosenChild = rightChild;
        }

        if (chosenChild != index)
        {
            swap(heap[index], heap[chosenChild]);
            heapifyDown(chosenChild);
        }
    }

public:
    saad_lab7(bool isMinHeap) : isMinHeap(isMinHeap) {}

    void insert(int val)
    {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }

    int getTop()
    {
        if (heap.size() == 0)
            throw out_of_range("Heap is empty.");
        return heap[0];
    }

    void removeTop()
    {
        if (heap.size() == 0)
            throw out_of_range("Heap is empty.");
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    void display()
    {
        for (int i : heap)
            cout << i << " ";
        cout << endl;
    }
};

int main()
{
    cout << "Min Heap Operations" << endl;
    saad_lab7 minHeap(true); // MinHeap
    minHeap.insert(5);
    minHeap.insert(3);
    minHeap.insert(8);
    minHeap.insert(1);
    minHeap.display();
    cout << "Minimum element: " << minHeap.getTop() << endl;
    minHeap.removeTop();
    minHeap.display();

    cout << "\nMax Heap Operations" << endl;
    saad_lab7 maxHeap(false); // MaxHeap
    maxHeap.insert(5);
    maxHeap.insert(3);
    maxHeap.insert(8);
    maxHeap.insert(1);
    maxHeap.display();
    cout << "Maximum element: " << maxHeap.getTop() << endl;
    maxHeap.removeTop();
    maxHeap.display();

    return 0;
}
