#include<iostream>
using namespace std;

    void sum(int arr[][3],int n,int m) {
        
        // for(int j=0;j<m;j++) {
        //     if(j&1) {
        //         for(int i=n-1;i>0;i--) {
        //             cout<<arr[i][j]<<" ";
        //         }
        //     }

        //     else {
        //         for(int i=0;i<n;i++) {
        //             cout<<arr[i][j]<<" ";
        //         }
        //     }
        // }
    }
int main() {
    int arr[2][3];
    cout<<"Enter the element : ";
    for(int i=0;i<2;i++) {
        for(int j=0;j<3;j++) {
            cin>>arr[i][j];


        }
        cout << endl;
    }
    for(int j=0;j<3;j++) {
            if(j&1) {
                for(int i=1;i>0;i--) {
                    cout<<arr[i][j]<<" ";
                }
            }

            else {
                for(int i=0;i<2;i++) {
                    cout<<arr[i][j]<<" ";
                }
            }
        }

    // sum(arr,2,3);

}