#include<iostream>
using namespace std;
int binarySearch(int arr[],int size,int key) {
    int start = 0;
    int end = size-1;
    int mid =  (start + end)/2;

    while(start<=end) {
        if(arr[mid]==key) {
            return mid;
        }
        if(key>arr[mid]) {
            start=mid+1;
        }
        else {
            end=mid-1;
        }
        mid=(start+end)/2;

    }
    return -1;
}
int main() {
    int even[6]={2,4,6,12,18};
    int odd[5]={3,8,11,14,16};
    // cout<<"Enter the key in even : ";
    // cin>>l;
    // cout<<"Enter the key in odd: ";
    // cin>>m;
    int x=binarySearch(even,6,6);
    cout<<"The index of key : "<<x<<endl;
    int y=binarySearch(odd,5,14);
    cout<<"The index of key in odd one : "<<y<<endl;
    



}