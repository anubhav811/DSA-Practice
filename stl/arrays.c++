
#include <bits/stdc++.h>
using namespace std;


// my own namespace
namespace anubhav{
    int val = 40;
}

struct myOwnDataType{
    string str;
    int num;
    double doub;
    
    // constructor
    myOwnDataType(strC,numC,doubC){
        str = strC;
        num = numC;
        doub = doubC;
    }
};


//main function
int main(){
    double val = 10.0;
    cout << val << endl;           // prints val
    cout << anubhav::val << endl;  // prints val from anubhav namespace

    myOwnDataType details =  new myOwnDataType("anubhav",08,96.2)
    cout<< details << endl;
    return 0;
}
