#include <iostream>
using namespace std;
template <class t>
class linkedList
{
private:
    struct node
    {
        t item;
        node *next;
    };
    node *first, *last;
    int length;

public:
    linkedList()
    {
        first = last = NULL;
        length = 0;
    }
    bool isEmpty()
    {
        return length == 0;
    }
    void insertFirst(t element)
    {
        node *newNode = new node;
        newNode->item = element;
        if (isEmpty())
        {
            newNode->next = NULL;
            first = last = newNode;
        }
        else
        {
            newNode->next = first;
            first = newNode;
        }
        length++;
    }
    void insertEnd(t element)
    {
        node *newNode = new node;
        newNode->item = element;
        newNode->next = NULL;
        if (isEmpty())
        {
            newNode->next = NULL;
            first = last = newNode;
        }
        else
        {
            last->next = newNode;
            last = newNode;
        }
        length++;
    }
    void display()
    {
        node *temp = first;
        while (temp != NULL)
        {
            cout << temp->item << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void insertAtPos(int pos, t element)
    {
        if (pos == 0)
            insertFirst(element);
        else if (pos == length)
            insertEnd(element);
        else if (pos > length || pos < 0)
            cout << "Out of range..!\n";
        else
        {
            node *temp = first;
            node *posPtr = new node;
            posPtr->item = element;
            for (int i = 0; i < pos - 1; i++)
            {
                temp = temp->next;
            }
            posPtr->next = temp->next;
            temp->next = posPtr;
        }
        length++;
    }
    void deleteFirst()
    {
        if (isEmpty())
            cout << "List is empty.\n";
        else if (length == 1)
        {
            delete first;
            first = last = NULL;
            length--;
        }
        else
        {
            node *temp = new node;
            temp = first;
            first = first->next;
            delete temp;
            length--;
        }
    }
    void deleteLast()
    {
        if (isEmpty())
            cout << "List is empty.\n";
        else if (length == 1)
        {
            delete last;
            first = last = NULL;
            length--;
        }
        else
        {
            node *temp = new node;
            temp = first;
            for (int i = 1; i < (length - 1); i++)
            {
                temp = temp->next;
            }
            last = temp;
            last->next = NULL;
            temp = temp->next;
            delete temp;
            length--;
        }
    }
    void deleteAtPos(int pos)
    {
        if (pos == 0)
            deleteFirst();
        else if (pos == (length - 1))
            deleteLast();
        else if (pos >= length || pos < 0)
            cout << "Out of range..!\n";
        else
        {
            node *cur = new node;
            node *temp;
            temp = cur = first;
            for (int i = 0; i < pos; i++)
            {
                cur = cur->next;
            }
            for (int i = 1; i < pos; i++)
            {
                temp = temp->next;
            }
            temp->next = cur->next;
            cur->next = NULL;
            delete cur;
            length--;
        }
    }
    void remove(t element)
    {
        node *temp = first;
        for (int i = 0; i < length; i++)
        {
            if (temp->item == element)
            {
                deleteAtPos(i);
            }
            temp = temp->next;
        }
    }
    int getLength()
    {
        return length;
    }
};
int main()
{
    linkedList<int> one;
    // one.insertFirst(1);
    // one.insertFirst(2);
    // one.insertFirst(3);
    // one.insertFirst(4);
    // one.insertEnd(2);
    // one.insertEnd(3);
    one.insertEnd(1);
    one.insertEnd(4);
    one.insertEnd(2);
    one.insertEnd(4);
    // one.display();
    // one.insertAtPos(3, 9);
    // one.display();
    // one.deleteLast();
    // one.deleteLast();
    // one.display();
    // one.deleteAtPos(2);
    one.display();
    one.remove(4);
    one.remove(4);
    one.display();
    cout << one.getLength();
}