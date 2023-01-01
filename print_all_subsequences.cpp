#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void printAllSubsequences(string ip, string op = ""){
    if(ip == ""){
        cout << op << endl;
        return;
    }
    string op1 = op, op2 = op;
    op1.push_back(ip.front());
    ip.erase(ip.begin());
    printAllSubsequences(ip, op1);
    printAllSubsequences(ip, op2); 
}

int main(){
    string s;
    cout << "Enter the string: ";
    cin >> s;
    printAllSubsequences(s);
}