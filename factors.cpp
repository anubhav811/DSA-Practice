// C++ program to find number of distinct
// permutations of a string.
#include<bits/stdc++.h>
using namespace std;
const int MAX_CHAR = 26;
 
// Utility function to find factorial of n.
int factorial(int n)
{
    int fact = 1;
    for (int i = 2; i <= n; i++)
        fact = fact * i;
    return fact;
}
 
// Returns count of distinct permutations
// of str.
int countDistinctPermutations(string str)
{
    int length = str.length();
 
    int freq[MAX_CHAR];
    memset(freq, 0, sizeof(freq));
 
    // finding frequency of all the lower case
    // alphabet and storing them in array of
    // integer
    for (int i = 0; i < length; i++)
        if (str[i] >= 'a')
            freq[str[i] - 'a']++;
 
    // finding factorial of number of appearances
    // and multiplying them since they are
    // repeating alphabets
    int fact = 1;
    for (int i = 0; i < MAX_CHAR; i++)
        fact = fact * factorial(freq[i]);
 
    // finding factorial of size of string and
    // dividing it by factorial found after
    // multiplying
    return factorial(length) / fact;
}
 
// Driver code
int main()
{
    int n ;
    cin >> n;
    for(int i=0;i<n;i++){
            string s;  
            cin >> s;
            cout << countDistinctPermutations(s) << endl; 
    }

    return 0;
}

