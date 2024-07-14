#include "Stack&Linkedstack.cpp"
bool balanced(string data)
{
    stack<char> s;
    for (int i = 0; i < data.size(); i++)
    {
        char x = data[i];
        if (x == '{' || x == '[' || x == '(')
            s.push(x);
        else if (x == '}')
        {
            if (s.getTop() == '{')
                s.pop();
        }
        else if (x == ']')
        {
            if (s.getTop() == '[')
                s.pop();
        }
        else if (x == ')')
        {
            if (s.getTop() == '(')
                s.pop();
        }
    }
    return s.isEmpty();
}
int main()
{
    string item;
    cout << "enter segmantation\n";
    cin >> item;
    if (balanced(item))
        cout << "balanced" << endl;
    else
        cout << "not balanced " << endl;
}