#include<iostream>
using namespace std;

    void moveZero(int arr[],int n) {

        int i=0;
        for(int j=0;j<n;j++) {

            if(arr[j] !=0) {
                swap(arr[j],arr[i]);
                i++;
            }
        }

        
    }

    void print(int arr[],int n) {
        for(int i=0;i<n;i++) {
            cout<<arr[i]<<" ";

        }
    }


int main() {
    int arr[6]={0,1,0,3,12,0};
    moveZero(arr,6);
    print(arr,6);
}