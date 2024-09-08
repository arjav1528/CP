#include<bits/stdc++.h>
using namespace std;
int main(){
    map<string,int> map;
    map["apple"]=1;
    map["banana"]=2;
    map["cherry"]=3;
    map["date"]=4;
    map["elderberry"]=5;
    for(const auto& pair : map){
        cout<<pair.first<<" "<<pair.second<<endl;
    }
    return 0;
    
}