#include<iostream>
#include<stdlib.h>
using namespace std;

    bool check(int arr[],int n) {
        int count =0;
        for(int i=1;i<n;i++) {
            if(arr[i-1]>arr[i]) {

                count++;

            }
        }

        if(arr[n-1]>arr[0]) {
            count++;
        }

        return count <=1;
    }

    void print(int arr[],int n) {
        for(int i=0;i<n;i++) {
            cout<<arr[i]<<" ";

        }
    }


int main() {

    int arr[5]={3,4,5,1,2};

    check(arr,5);
 

}