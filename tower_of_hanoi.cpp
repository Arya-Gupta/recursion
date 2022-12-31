#include <bits/stdc++.h>
using namespace std;

long long toh(int N, string sourceRod, string destinationRod, string helperRod)
{
    long long noOfMoves = 0;
    if (N == 1)
    {
        cout << "move disk " << N << " from rod " << sourceRod << " to rod " << destinationRod << endl;
        return 1;
    }
    // Move N - 1 disks from sourceRod to helperRod using destinationRod
    noOfMoves += toh(N - 1, sourceRod, helperRod, destinationRod);
    // Move disk N directly from sourceRod to destinationRod
    cout << "move disk " << N << " from rod " << sourceRod << " to rod " << destinationRod << endl;
    noOfMoves++;
    // Move N - 1 disks from helperRod to destinationRod using sourceRod
    noOfMoves += toh(N - 1, helperRod, destinationRod, sourceRod);
    return noOfMoves;
}

int main()
{
    int N;
    cout << "No of disks = ";
    cin >> N;
    string sourceRod = "1", destinationRod = "3", helperRod = "2";
    int noOfMoves = toh(N, sourceRod, destinationRod, helperRod);
    cout << "No of moves = " << noOfMoves;
}
