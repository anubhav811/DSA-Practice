
#include <bits/stdc++.h>
using namespace std;


// my own namespace
namespace anubhav{
    int val = 40;
}

//main function
int main(){
    double val = 10.0;
    cout << val << endl;           // prints val
    cout << anubhav::val << endl;  // prints val from anubhav namespace
    return 0;
}