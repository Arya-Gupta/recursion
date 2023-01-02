#include <bits/stdc++.h>
using namespace std;

void findPermutations(string ip, string op, vector<string> &permutations)
{
    if (ip == "")
    {
        permutations.push_back(op);
        return;
    }

    string op1 = op, op2 = op;
    op1.push_back(' ');
    op1.push_back(ip.front());
    op2.push_back(ip.front());
    ip.erase(ip.begin());

    findPermutations(ip, op1, permutations);
    findPermutations(ip, op2, permutations);
}

vector<string> permutation(string S)
{
    vector<string> permutations;
    string op;

    op.push_back(S.front());
    S.erase(S.begin());

    findPermutations(S, op, permutations);
    return permutations;
}

int main()
{
    string S;
    cout << "Enter the string = ";
    cin >> S;
    vector<string> ans;
    ans = permutation(S);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << "(" << ans[i] << ")";
    }
    cout << endl;
}
