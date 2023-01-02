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
    char ch = ip.front();
    op1.push_back(ch);
    op2.push_back(toupper(ch));
    ip.erase(ip.begin());
    findPermutations(ip, op1, permutations);
    findPermutations(ip, op2, permutations);
}

int main()
{
    string s;
    cout << "Enter the string in lowercase = ";
    cin >> s;
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    vector<string> permutations;
    findPermutations(s, "", permutations);
    for (auto i : permutations)
        cout << i << endl;
}