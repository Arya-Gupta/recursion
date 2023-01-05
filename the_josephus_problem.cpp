//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int findSafePlace(vector<int> &people, int idx, int k)
{
    if (people.size() == 1)
    {
        return people[0];
    }
    idx = (idx + k) % people.size();
    people.erase(people.begin() + idx);
    findSafePlace(people, idx, k);
}

int josephus(int n, int k)
{
    vector<int> people;
    for (int i = 1; i <= n; i++)
        people.push_back(i);
    int place = findSafePlace(people, 0, k - 1);
    return place;
}

int main()
{
    int n, k;
    cin >> n >> k;
    cout << josephus(n, k);
    return 0;
}
