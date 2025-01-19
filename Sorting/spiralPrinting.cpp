#include<iostream>
using namespace std;
int main () {
    int n,m;
    int arr[2][3];
    cout<<"Enter Eliment of Array : ";
    
    for(int i=0;i<2;i++) {
        for(int j=0;j<3;j++) {
            cin>>arr[i][j];
        }
        
    }
    cout<<"Array is : "<<endl;
    for(int i=0;i<2;i++) {
        for(int j=0;j<3; j++) {
            cout<<arr[i][j];
        }
        cout<<endl;
    }

    cout<<"SpiralPrint is : ";
    int startingR=0;
    int startingC=0;
    int endingR=1;
    int endingC=2;


    int count=0;
    int total=6;
    while(count<total) {

        for(int i=startingC;i<=endingC && count<=6;i++) {

            cout<<arr[startingR][i]<<" ";
            count++;


        }
        startingR++;

        for(int i=startingR;i<=endingC && count<=6 ; i++) {

            cout<<arr[i][endingC]<<" ";
            count++;
        }
        endingC--;

        for(int i=endingC;i<=startingC && count<=6;i--) {
            cout << arr[endingR][i];
            count++;
        }

        endingR--;

        for(int i=endingR;i<=startingR && count<total;i--) {
            cout<< arr[i][startingC];
            count++;
        }

        startingC++;

    }


}