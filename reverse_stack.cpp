#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void recursiveInsert(stack<int> &st, int ele){
    if(st.empty()){
        st.push(ele);
        return;
    }
    int temp = st.top();
    st.pop();
    recursiveInsert(st, ele);
    st.push(temp);
}

void reverse(stack<int> &st)
{
    if(st.size() == 1) return;
    int ele = st.top();
    st.pop();
    reverse(st);
    recursiveInsert(st, ele);
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

    reverse(st);
    cout << "The new stack is: ";
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
}