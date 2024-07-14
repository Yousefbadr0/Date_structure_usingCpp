#include <iostream>
using namespace std;
template <class t>
class Array
{
private:
    t *arr;
    int maxSize, length;

public:
    Array(int x)
    {
        maxSize = x;
        arr = new t[maxSize];
        length = 0;
    }
    bool isEmpty()
    {
        return length == 0;
    }
    bool isFull()
    {
        return length == maxSize;
    }
    int getSize()
    {
        return length;
    }
    void display()
    {
        t *ptr = arr;
        for (int i = 0; i < length; i++)
        {
            cout << *ptr++ << " ";
        }
        cout << endl;
    }
    void insertAt(int pos, t element)
    {
        if (isFull())
            cout << "Array is full\n";
        else if (pos < 0 || pos > length)
            cout << "out of range\n";
        else
        {
            for (int i = length; i > pos; i--)
            {
                arr[i] = arr[i - 1];
            }
            arr[pos] = element;
            length++;
        }
    }
    void removeAt(int pos)
    {
        if (isEmpty())
            cout << "Array is empty\n";
        else if (pos < 0 || pos > length)
            cout << "out of range\n";
        else
        {
            for (int i = pos; i < length; i++)
            {
                arr[i] = arr[i + 1];
            }
            length--;
        }
    }
    void push(t element)
    {
        if (isFull())
            cout << "Array is full\n";
        else
        {
            arr[length] = element;
            length++;
        }
    }
    void pop()
    {
        if (isEmpty())
            cout << "Array is empty\n";
        else
        {
            length--;
        }
    }
    int search(t element)
    {
        for (int i = 0; i < length; i++)
        {
            if (arr[i] == element)
                return i;
            return -1;
        }
    }
    void insertNoDuplicate(t element)
    {
        if (search(element) == -1)
            insertAtEnd(element);
        else
            cout << "the element is there\n";
    }
    void update(t element, t update)
    {
        if (search(element) == -1)
            cout << "element not found\n";
        else
            arr[search(element)] = update;
    }
    void updateAt(int pos, t element)
    {
        if (pos < 0 || pos > length)
            cout << "out of range\n";
        else
            arr[pos] = element;
    }
    int numberOfDuplicate(t element)
    {
        int count = 0;
        for (int i = 0; i < length; i++)
        {
            if (arr[i] == element)
                count++;
        }
        return count;
    }
    t getElement(int pos)
    {
        if (pos < 0 || pos > length)
            cout << "out of range\n";
        else
            return arr[pos];
    }
    void clear()
    {
        length = 0;
    }
    ~Array()
    {
        delete[] arr;
    }
};
int main()
{
    Array<int> first(8);
    first.push(1);
    first.push(2);
    first.push(1);
    first.push(1);
    first.push(3);
    first.push(6);
    first.push(7);
    first.push(8);
    first.push(9);
    first.pop();
    first.insertAt(1, 1);
    first.insertAt(1, 1);
    cout << first.numberOfDuplicate(1) << endl;
    first.display();
}