#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> vec = {3,2,3};
    map<int,int> mpp;
    for(int i=0;i<vec.size();i++){
        mpp[vec[i]]++;
    }
    for(auto it : mpp){
        if(it.second > (vec.size()/2)){
            cout<<it.first<<endl;
        }
    }
    
}