#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    string s = "tree";
    unordered_map<char,int> m1;
    for(int i=0;i<s.size();i++){
        m1[s[i]]++;
    }
    map<int,string>mpp;
    for(auto it : m1){
        mpp[it.second] = it.first;
    }
    for(auto it : m1){
        cout<<it.first<<" "<<it.second<<endl;
    }
    // string final = "";
    // for(auto it: mpp){
    //     final = it.second + final;
    // }
    // cout<<final;
}
