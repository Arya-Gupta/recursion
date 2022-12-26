#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void recursiveInsert(stack<int> &st, int ele){
    if(st.empty() || ele >= st.top()){
        st.push(ele);
        return;
    }
    int greatest = st.top();
    st.pop();
    recursiveInsert(st, ele);
    st.push(greatest);
}

void recursiveSort(stack<int> &st){
    if(st.size() == 1) return;
    int ele = st.top();
    st.pop();
    recursiveSort(st);
    recursiveInsert(st, ele);
}

int main()
{
    int sz;
    cout << "Enter the size of the stack: ";
    cin >> sz;

    stack<int> st;
    cout << "Enter the elements in the stack:\n";
    for (int i = 0; i < sz; i++){
        int a;
        cin >> a;
        st.push(a);
    }

    recursiveSort(st);
    cout << "The sorted stack is: ";
    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
}