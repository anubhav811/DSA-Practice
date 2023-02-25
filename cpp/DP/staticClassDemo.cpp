#include <bits/stdc++.h>
using namespace std;

class Krina
{

public:
    static int age;
    int age2 = 20;

    static void printName()
    {
        age = age + 2;
        cout << "Krina " << age;
    }

    void printN()
    {
        age = age + 2;
        cout << "Anubhav " << age2 << endl;
    }
};

int Krina::age = 21;
int main()
{
    Krina k = Krina();
    k.printN();
    k.printN();
    Krina::printName();
    cout << endl;
    k.printName();
    return 0;
}