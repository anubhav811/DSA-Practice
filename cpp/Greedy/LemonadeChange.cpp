#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool lemonadeChange(vector<int> &bills)
    {
        int five = 0;
        int ten = 0;

        for (auto it : bills)
        {

            if (it == 5)
            {
                five++;
                // we have to give back zero
            }
            else if (it == 10)
            {
                ten++;
                // we have to give back five
                five--;
            }
            else if (it == 20)
            {
                if (ten > 0)
                {
                    // we have to give back 15
                    ten--;
                    five--;
                }
                else
                {
                    // we have to give back 15
                    five -= 3;
                }
            }

            if (five < 0)
                return false;
            // its negative coz we gave out nonexistent fives  :)
        }
        return true;
    }
};