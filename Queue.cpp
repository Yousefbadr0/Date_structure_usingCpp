#include <iostream>
#include <cstring>
using namespace std;
template <class t>
class Queue
{
    int front, rear, length, MAX;
    t data[100];

public:
    Queue(int x)
    {
        MAX = x;
        data[MAX];
        front = 0;
        rear = -1;
        length = 0;
    }
    bool isEmpty()
    {
        return length == 0;
    }
    bool isFull()
    {
        return length == MAX;
    }
    void enqueue(t element)
    {
        if (isFull())
            cout << "queue is full.\n";
        else
        {
            rear++;
            length++;
            rear = rear % MAX;
            data[rear] = element;
        }
    }
    void dequeue()
    {
        if (isEmpty())
            cout << "queue is empty.\n";
        else
        {
            front++;
            length--;
            front = front % MAX;
        }
    }
    void getFront()
    {
        if (isEmpty())
            cout << "queue is empty.\n";
        else
            cout << data[front] << endl;
    }
    void getRear()
    {
        if (isEmpty())
            cout << "queue is empty.\n";
        else
            cout << data[rear] << endl;
    }
    int getSize()
    {
        return length;
    }
    void clear()
    {
        front = 0;
        rear = -1;
        length = 0;
    }
    void print()
    {
        int temp=front;
        for (int i = 0; i < length; i++)
        {
            cout << data[temp] << endl;
            temp++;
            temp = temp % MAX;
        }
    }
    int search(t x)
    {
        int temp=front,count;
        for (int i = 1; i <= length; i++)
        {
            if (x == data[temp]){
                count=i;
                break;
            }
            else
            {
                temp++;
                temp = temp % MAX;
            }
        }
        return count;
    }
};
int main()
{
    Queue<int> one(6);
    one.enqueue(1);
    one.enqueue(2);
    one.enqueue(3);
    one.enqueue(4);
    one.enqueue(5);
    one.enqueue(6);
    one.dequeue();
    one.dequeue();
    one.getFront();
    one.getRear();
    cout << one.getSize() << endl;
    cout << one.search(6) << endl;

}