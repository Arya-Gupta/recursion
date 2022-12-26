#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void recursiveInsert(vector<int> &A, int ele)
{
    if (A.size() == 0 || A.back() <= ele)
    {
        A.push_back(ele);
        return;
    }
    int greatest = A.back();
    A.pop_back();
    recursiveInsert(A, ele);
    A.push_back(greatest);
}

void recursiveSort(vector<int> &A)
{
    if (A.size() == 1)
        return;
    int ele = A.back();
    A.pop_back();
    recursiveSort(A);
    recursiveInsert(A, ele);
}

int main()
{
    int sz;
    cout << "Enter the size of the array: ";
    cin >> sz;

    vector<int> A(sz);
    cout << "Enter the elements in the array:\n";
    for (int i = 0; i < sz; i++)
        cin >> A[i];

    recursiveSort(A);
    cout << "The sorted array is: ";
    for (int i = 0; i < sz; i++)
        cout << A[i] << " ";
}