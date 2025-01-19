#include<iostream>
using namespace std;
int main() {
    int arr[6]={8,4,3,2,1,5};
    int minIndex=0;
    for(int i=0;i<6;i++) {
        int minIndex=i;
        for(int j=i+1;j<6;j++) {
            if(arr[j]<arr[minIndex]) {

                minIndex=j;

            }
        }
        
        swap(arr[minIndex],arr[i]);

    }
    for(int i=0;i<5;i++) {
        cout<<arr[i];
    }
}