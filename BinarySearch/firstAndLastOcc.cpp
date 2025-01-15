#include<iostream>
using namespace std;
int firstOccurance(int arr[],int size,int key) {
    int s=0;
    int e=size-1;
    int mid=s+(e-s)/2;
    int ans=-1;
    while(s<=e) {
        if(key==arr[mid]) {
            ans=mid;
            e=mid-1;


        }
        if(key>arr[mid]) {
            s=mid+1;

        }
        else {
            e=mid-1;
        }
        mid=s+(e-s)/2;
    }
    return ans;
}
int lastOccurance(int arr[],int size,int key) {
    int s=0;
    int e=size-1;
    int mid=s+(e-s)/2;
    int ans=-1;
    while(s<=e) {
        if(key==arr[mid]) {
            ans=mid;
            s=mid+1;


        }
        if(key>arr[mid]) {
            s=mid+1;

        }
        else {
            e=mid-1;
        }
        mid=s+(e-s)/2;
    }
    return ans;
}
int main() {
    int arr[8]={1,2,3,3,3,4,3,5};
    int x=firstOccurance(arr,8,3);
    cout<<"The first occurance of 3 is at index : "<<x<<endl;
    int y=lastOccurance(arr,8,3);
    cout<<"The last occurance of 3 is at index : "<<y;
}