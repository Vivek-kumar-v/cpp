#include<iostream>
using namespace std;
void update2(int& n) {
    n++;
    
}
void update(int n) {
    n++;
    
}
int main() {
    int n=5;
    cout<<"Before "<<n<<endl;
    update(n);
    cout<<"After "<<n<<endl;
    update2(n);
    cout<<"After "<<n<<endl;

}