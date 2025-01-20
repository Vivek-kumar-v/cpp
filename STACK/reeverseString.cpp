#include<iostream>
#include<stack>
using namespace std;


int main() {

    string str = "vivek";

    stack<char> s;


    // Insert in stack
    for(int i=0; i<str.length(); i++) {
        char ch = str[i];
        s.push(ch);
    }

    // push Back from stack
    string ans = "";
    while(!s.empty()) {
        char ch = s.top();
        ans.push_back(ch);

        s.pop();
    }

    cout<<"answer is : "<<ans<<endl;
}