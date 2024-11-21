#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    for(int w = 0;w<t;w++){
        int len;
        cin>>len;
        vector<int> arr(len);
        int count = 0;
        unordered_map<int,int> mpp;
        for(int i=0;i<len;i++){
            cin>>arr[i];
            mpp[arr[i]]++;
            
        }
        for(auto it : mpp){
            if(it.second >=2){
                count+= ((it.second)/2);
            }
        }
        // while()
        cout<<count<<endl;

        
    }
}