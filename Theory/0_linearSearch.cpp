#include<iostream>
using namespace std;
int linearSearch(int arr[] , int target){
    for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++){
        if(arr[i]==target){
            return i;
        }
    }
    return -1;
}
int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int target = 10;
    int index = linearSearch(arr,target);
    if(index==-1){
        cout<<"Not found";
    }
    else{
        cout<<"Found at index "<<index;
    }
    return 0;
} 