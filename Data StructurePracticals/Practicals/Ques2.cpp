#include<iostream>
using namespace std;
int binarySearch(int arr[],int x, int low, int high){
    if(high>=low){
        int mid= (low + high)/2;
        if(arr[mid]==x){
            return mid;
        }
        if(arr[mid]>x){
            return binarySearch(arr,x,low, mid-1);
        }
        if(arr[mid]<x){
            return binarySearch(arr,x,mid+1, high);
        }
    }
    return -1;
}
int main(){
    int arr[]={2,4,6,8,10,12};
    cout<<"Given array: {2,4,6,8,10,12}"<<endl;
    int x; 
    cout<<"Enter a number which you find: ";
    cin>>x;
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<binarySearch(arr,x,0,n-1)<<endl;
    // int result=binarySearch(arr,x,0,n-1);
    // if (result == -1){
    //     cout << "Element is not present";
    // }
    // else{
    //     cout << "Target element is found at index: " << result << endl;
    // }
    return 0;
}