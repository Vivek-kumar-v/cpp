#include<iostream>
#include<map>


using namespace std;

int main() {

    // Creation of map
    map<string,int> m;

    // Insertion

    // 1
    pair<string,int> p = make_pair("vivek", 3);
    m.insert(p);

    // 2
    pair<string,int> p2("Patel", 2);
    m.insert(p2);

    // 3
    m["kya"] = 1;

    // what will happen
    m["kya"] = 2;

    // search
    cout<<m["kya"]<<endl;
    cout<<m.at("vivek")<<endl;

    cout<<m["knownkey"]<<endl;
    cout<<m.at("knownkey")<<endl;

    // size 
    cout<<m.size()<<endl;

    // to check presence
    cout<<m.count("Patel")<<endl;

    // erase
    m.erase("Patel");
    cout<<m.size()<<endl;

    // for(auto i : m) {
    //     cout<<i.first<<" "<<i.second<<endl;
    // }

    // iterator 
    map<string,int> :: iterator it = m.begin();

    while(it != m.end()) {
        cout<<it->first<<" "<<it->second<<endl;
        it++;
    }

    return 0;
}