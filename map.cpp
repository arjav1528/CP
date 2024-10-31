#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> arr = {100,4,200,1,3,2};
    map<int,int> mpp;
    for(int i=0;i<arr.size();i++){
        mpp[arr[i]]++;
    }
    for(auto it : mpp){
        cout<<it.first<<"-"<<it.second<<endl;
    }
    
}