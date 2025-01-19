#include<iostream>
using namespace std;

    

    void merge(int arr1[],int n,int arr2[],int m) {

        int i=0,j=0;
        
        int temp[n];
        
        while(i<n && j<m) {

            if(arr1[i]==0) {
                temp[i]=arr2[j];
                i++;
                j++;
            }

            if(arr1[i]<=arr2[j]) {
                temp[i]=arr1[i];
                
                
                i++;
            }

            if(arr1[i]>arr2[j]) 
            {
               temp[i]=arr2[j];
                
                j++;
            }
        }
        
        for(int i=0;i<n;i++) {
            arr1[i]=temp[i];
        }

        while(i<n) {
            arr1[i++]=arr2[j++];
        }
        
    }
    

    void print(int arr[],int n) {
        for(int i=0;i<n;i++) {
            cout << arr[i]<<" ";
        }
        cout<<endl;

        
    }
int main() {

    int arr1[6] ={1,2,3};
    int arr2[3]={2,5,6};

    merge(arr1,6,arr2,3);

    print(arr1,6);


}