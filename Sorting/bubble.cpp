#include<iostream>
using namespace std;
int main() {
    int arr[6]={10,1,7,6,14,9};
    for(int i=1;i<6;i++) {
        for(int j=0;j<6-i;j++) {
            if(arr[j]>arr[j+1]) {
                swap(arr[j],arr[j+1]);
            }
        }
    }
    for(int i=0;i<6;i++) {
        cout<<arr[i]<<" ";
    }

}