#include<iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    int pre1 = 0;
    int pre2 = 1;
    if(n == 0 ) cout<< pre1<<endl;
    if(n == 1) cout<< pre2<<endl;
    for(int i=2;i<=n;i++) {
        int curr = pre1 + pre2;
        pre1 = pre2;
        pre2 = curr;
        
    }
    cout<<pre2<<endl;
}