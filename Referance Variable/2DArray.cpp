#include<iostream>
using namespace std;
int main() {
    int n;
    cout<<"Enter n :"<<endl;
    cin>>n;
    // creating 2D array
    int** arr=new int*[n];
    for(int i=0;i<n;i++) {
        arr[i]=new int[n];

    }
    // taking input
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin>>arr[i][j];

        }
    }

    // Output

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cout<<arr[i][j]<<" ";

        }
        cout<<endl;
    }

    // Relesing Memory
    for(int i=0;i<n;i++) {
        delete [] arr[i];

    }
    delete []arr;

    }