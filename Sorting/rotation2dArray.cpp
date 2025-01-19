#include<iostream>
#include<vector>
using namespace std;
void transpose(int m[3][3])
    {
        int n=3;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(j>i)
                {
                    swap(m[i][j],m[j][i]);
                }
            }
        }
    }
    // void rotate(int  matrix[3][3]) {
    //     transpose(matrix);
    //     int n=3;
    //     int i=0,j=n-1;
    //     while(i<j)
    //     {
    //         for(int k=0;k<n;k++)
    //         {
    //             swap(matrix[k][i],matrix[k][j]);
    //         }
    //         i++;
    //         j--;
    //     }
    // }

    // void print(int arr[],int n ,int m) {
    //     for(int j=0;j<n;j++) {

    //     for(int i=0;i<m;i++) {
    //         cout << arr[j][i]<<" ";
    //     }
    //     cout<<endl;
    //     }
    // }
            
    int main() {
        int arr[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
        transpose(arr);
        int n=3;
        int i=0,j=n-1;
        while(i<j)
        {
            for(int k=0;k<n;k++)
            {
                swap(arr[k][i],arr[k][j]);
            }
            i++;
            j--;
        }
        
        for(int i=0;i<3;i++) {
            for(int j=0;j<3;j++) {
                cout<<arr[i][j];
            }
            cout<<endl;

            
        }

    }