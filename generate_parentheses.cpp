#include<bits/stdc++.h>
using namespace std;

void findPermutations(int o, int c, string op, vector<string> &permutations){
    if(o == 0 && c == 0){
        permutations.push_back(op);
        return;
    }
    if(o != 0) findPermutations(o - 1, c, op + '(', permutations);
    if(c > o) findPermutations(o, c - 1, op + ')', permutations);
}

vector<string> generateParenthesis(int A){
    vector<string> permutations;
    findPermutations(A, A, "", permutations);
    return permutations;
}

int main(){
    int A;
    cout << "Enter the number of pairs of parantheses = ";
    cin >> A;
    vector<string> permutations;
    permutations = generateParenthesis(A);
    for(auto i : permutations) cout << i << endl;
}