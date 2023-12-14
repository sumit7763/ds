#include <iostream>
using namespace std;
int linearsearch(int arr[], int x, int target){
    for (int i = 0; i < x; i++){
        if (arr[i] == target){
            return i;
        }
    }
    return -1;
}

// // Recursive Call
// int linearsearch(int arr[], int size, int target){
//     size--;
//     if(size<0){
//         return -1;
//     }
//     if(arr[size]==target){
//         return size;
//     }
//     return linearsearch(arr,size,target);
// }

int main(){
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    int *array = new int[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++){
        cin >> array[i];
    }
    cout<<"Given array: ";
    for (int i = 0; i < n; i++){
        cout<<array[i]<<",";
    }
    cout<<endl;

    int target;
    cout << "Enter the target: ";
    cin >> target;
    cout<<linearsearch(array, n, target)<<endl;
    // int result = linearsearch(array, n, target);
    // if (result == -1){
    //     cout << "Element is not present";
    // }
    // else{
    //     cout << "Target element is found at index: " << result << endl;
    // }
}