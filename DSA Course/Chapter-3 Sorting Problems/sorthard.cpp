#include<bits/stdc++.h>
using namespace std;
void threeSum(){
    vector<int> arr = {-1,0,1,2,-1,-4};
    sort(arr.begin(),arr.end());
    int n = arr.size();
    vector<vector<int>> ans;
    map<vector<int>,int> mpp;
    for(int i=0;i<n;i++){
        for(int j=(i+1);j<n;j++){
            mpp[{i,j}] = (arr[i] + arr[j]);
        }
    }
    for(auto it : mpp){
        cout<<arr[it.first[0]]<<"+"<<arr[it.first[1]]<<"="<<it.second<<endl;
    }
    
    
    
    

}
int main(){
    threeSum();

}