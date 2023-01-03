#include <bits/stdc++.h>
using namespace std;

void findPermutations(string ip, string op, vector<string> &permutations)
{
    if (ip == "")
    {
        permutations.push_back(op);
        return;
    }

    char ch = ip.front();

    if (isalpha(ch))
    {
        string op1 = op, op2 = op;
        op1.push_back(toupper(ch));
        op2.push_back(tolower(ch));
        ip.erase(ip.begin());
        findPermutations(ip, op1, permutations);
        findPermutations(ip, op2, permutations);
    }

    else if (isdigit(ch))
    {
        string op1 = op;
        op1.push_back(ch);
        ip.erase(ip.begin());
        findPermutations(ip, op1, permutations);
    }
}

int main()
{
    string s;
    cout << "Enter the string = ";
    cin >> s;
    vector<string> permutations;
    findPermutations(s, "", permutations);
    for (auto i : permutations)
        cout << i << endl;
}