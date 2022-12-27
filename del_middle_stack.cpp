#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solve(stack<int> &st, int k)
{
    if (k == 1)
    {
        st.pop();
        return;
    }
    int ele = st.top();
    st.pop();
    solve(st, k - 1);
    st.push(ele);
}

void delMiddle(stack<int> &st)
{
    if (st.size() == 0)
        return;
    int k = st.size() / 2 + 1;
    solve(st, k);
}

int main()
{
    int sz;
    cout << "Enter the size of the stack: ";
    cin >> sz;

    stack<int> st;
    cout << "Enter the elements in the stack:\n";
    for (int i = 0; i < sz; i++)
    {
        int a;
        cin >> a;
        st.push(a);
    }

    delMiddle(st);
    cout << "The new stack is: ";
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
}