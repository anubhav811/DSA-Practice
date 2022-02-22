
#include <array>
#include <bits/stdc++.h>
#include <iterator>
using namespace std;

// array<int,100> arr ; // container to define an array of 100 size

// main function
int main()
{

    // array<int,6> arr = {1,2,3,4,5,6}; // array of size 100

    array<int, 5> arr = {1, 3, 4, 5, 6};
    // for (auto it = arr.rbegin(); it != arr.rend(); it--)
    // {
    //     cout << *it << " ";
    // }

    
    for(int i=0 ; i<arr.size();i++){
        cout<<arr[i];
    }
    // cout << *(ar.rbegin()) << endl;

    return 0;
}

// arr1 will have all zeroes  (because its declared globally)
// arr2 will have garbage values  (declared inside main())

// for (auto it : arr)
// {
//     cout << it << " ";
// }
// for (auto it : arr.begin())
// {
//     cout << *it << " ";
// }
