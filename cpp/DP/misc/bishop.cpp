#include <bits/stdc++.h>
using namespace std;

int solve(int row, int col)
{
    if (row == 1 || row == 8 || col == 1 || col == 8)
        return 7;

    if (row == 2 || row == 7 || col == 2 || col == 7)
        return 9;

    if (row == 3 || row == 6 || col == 3 || col == 6)
        return 11;

    if (row == 4 || row == 5 || col == 4 || col == 5)
        return 13;

    return 0;
}
int main()
{
    cout << solve(4, 4);
    return 0;
}