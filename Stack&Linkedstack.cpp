#include <iostream>
using namespace std;

//!=================================================================================================================
//*                                            stack array
// const int max_size = 100;
// template <class a>
// class stack
// {
//     int top;
//     a item[max_size];

// public:
//     stack()
//     {
//         top = -1;
//     }
//     void push(a element)
//     {
//         if (top >= max_size)
//             cout << "stack is full !! " << endl;
//         else
//         {
//             top++;
//             item[top] = element;
//         }
//     }
//     bool isEmpty()
//     {
//         return top == -1;
//     }
//     void pop()
//     {
//         if (isEmpty())
//             cout << "stack is empty ";
//         else
//             top--;
//     }
//     void get(int x)
//     {
//         if (x > top)
//             cout << "element dosen't exist " << endl;
//         else
//             cout<<item[x]<<endl;
//     }
//     void print()
//     {
//         for(int i=top;i>=0;i--)
//         {
//             cout<<item[i]<<"\t";
//         }
//         cout<<"\n";
//     }
// };
// int main()
// {
//     stack<int>arr;
//     arr.push(2);
//     arr.push(2);
//     arr.push(3);
//     arr.push(4);
//     arr.print();
//     arr.pop();
//     arr.print();
//     arr.get(0);
//     stack<string>arr1;
//     arr1.push("yousef1");
//     arr1.push("yousef2");
//     arr1.push("yousef3");
//     arr1.push("yousef4");
//     arr1.print();
// }



//!===============================================================================================================
//*                                                  linked list
template <class t>
class stack
{
private:
    struct node
    {
        t Item;
        node *next;
    };
    node *top;
public:
    stack()
    {
        top = NULL;
    }
    void push(t Element)
    {
        node *elementPtr =new node;                      //! look out (don't forget ^ new ^ )
        elementPtr->next = top;
        elementPtr->Item = Element;
        top = elementPtr;
    }
    bool isEmpty()
    {
        return top==NULL;
    }

    void pop()
    {
        node *temp = top;
        top = top->next;
        temp->next = NULL;
    }
    t getTop()
    {
        return top->Item;
    }
    void display()
    {
        node *temp=top;
        while (temp != NULL)
        {
            cout << temp->Item << endl;
            temp = temp->next;
        }
    }
};
// int main()
// {
//     stack<int> s;
//     s.push(15);
//     s.push(10);
//     s.push(12);
//     s.push(11);
//     // s.getTop();
//     s.pop();
//     s.display();
//     s.getTop();
// }
