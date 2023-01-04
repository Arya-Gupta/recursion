
#include <bits/stdc++.h>
using namespace std;

void findPermutations(int ip, int one, int zero, string op, vector<string> &permutations)
{
    if (ip == 0)
    {
        permutations.push_back(op);
        return;
    }
    findPermutations(ip - 1, one + 1, zero, op + '1', permutations);
    if (one > zero)
        findPermutations(ip - 1, one, zero + 1, op + '0', permutations);
}

vector<string> NBitBinary(int N)
{
    vector<string> permutations;
    findPermutations(N, 0, 0, "", permutations);
    return permutations;
}

int main()
{
    int N;
    cout << "Enter the value of N = ";
    cin >> N;
    vector<string> permutations = NBitBinary(N);
    for(auto i : permutations) cout << i << endl;
}
