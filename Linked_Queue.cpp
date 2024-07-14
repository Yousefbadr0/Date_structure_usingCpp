#include <iostream>
#include <string>
using namespace std;
template <class t>
class linkedQueue
{
private:
    struct node
    {
        t item;
        node *next;
    };
    node *front, *rear;
    int length;

public:
    linkedQueue()
    {
        rear = NULL;
        front = NULL;
        length = 0;
    }
    bool isEmpty()
    {
        return length == 0;
    }
    void enqueue(t element)
    {
        node *elementPtr = new node;
        elementPtr->item = element;
        elementPtr->next = NULL;
        if (isEmpty())
        {
            front = elementPtr;
            rear = elementPtr;
        }
        else
        {
            rear->next = elementPtr;
            rear = elementPtr;
        }
        length++;
    }
    void dequeue()
    {
        if (isEmpty())
            cout << "queue is empty.\n";
        else
        {
            node *temp = front;
            front = front->next;
            temp->next = NULL;
            delete temp;
            length--;
        }
    }
    void print()
    {
        node *temp = front;
        while (temp != NULL)
        {
            cout << temp->item << endl;
            temp = temp->next;
        }
    }
};
int main()
{
    linkedQueue<int> first;
    first.enqueue(1);
    first.enqueue(2);
    first.enqueue(3);
    first.enqueue(4);
    first.enqueue(5);
    first.print();
}