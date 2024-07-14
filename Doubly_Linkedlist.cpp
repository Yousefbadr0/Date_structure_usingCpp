#include <iostream>
using namespace std;
template <class t>
class doublyLinkedList
{
private:
    struct node
    {
        t item;
        node *next;
        node *back;
    };
    node *last, *first;
    int length;

public:
    doublyLinkedList()
    {
        last = first = NULL;
        length = 0;
    }
    bool isEmpty()
    {
        return length == 0;
    }
    void insertLast(t element)
    {
        node *newnode = new node;
        newnode->item = element;
        if (isEmpty())
        {
            newnode->back = newnode->next = NULL;
            last = first = newnode;
        }
        else
        {
            newnode->back = last;
            last->next = newnode;
            newnode->next = NULL;
            last = newnode;
        }
        length++;
    }
    void insertFirst(t element)
    {
        node *newnode = new node;
        newnode->item = element;
        if (isEmpty())
        {
            newnode->back = newnode->next = NULL;
            last = first = newnode;
        }
        else
        {
            first->back = newnode;
            newnode->next = first;
            newnode->back = NULL;
            first = newnode;
        }
        length++;
    }
    void insertAt(int pos, t element)
    {
        if (pos < 0 || pos > length)
            cout << "Out of range \n";
        else
        {
            if (pos == 0)
                insertFirst(element);
            else if (pos == length)
                insertLast(element);
            else
            {
                node *newnode = new node, *temp = first;
                newnode->item=element;
                for (int i = 0; i < (pos - 1); i++)
                {
                    temp=temp->next;
                }
                newnode->next=temp->next;
                temp->next->back=newnode;
                newnode->back=temp;
                temp->next=newnode;
                length++;
            }
        }
    }
    void pop()
    {
        if (length == 1)
        {
            first = last = NULL;
        }
        else
        {
            node *temp = new node;
            temp = last;
            last = last->back;
            delete temp;
            last->next = NULL;
        }
        length--;
    }
    void deleteAt(int pos)
    {
        if (pos < 0 || pos >= length)
            cout << "Out of range \n";
        else
        {
            if (pos == (length-1))
                pop();
                else
                {
                node *temp = first;
                for (int i = 0; i < pos ; i++)
                {
                    temp=temp->next;
                }
                temp->next->back=temp->back;
                temp->back->next=temp->next;
                delete temp;
                }
        }
    }
    void displayFor()
    {
        node *temp = first;
        while (temp != NULL)
        {
            cout << temp->item << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void displayBack()
    {
        node *temp = last;
        while (temp != NULL)
        {
            cout << temp->item << " ";
            temp = temp->back;
        }
        cout << endl;
    }
};
int main()
{
    doublyLinkedList<int> first;
    first.insertLast(1);
    first.insertLast(2);
    first.insertLast(3);
    first.insertLast(4);
    first.insertLast(5);
    first.insertAt(1,2);
    // first.insertFirst(0);
    first.displayFor();
    first.deleteAt(4);
    first.deleteAt(1);
    first.displayFor();
    // first.pop();
    // first.displayBack();
}
