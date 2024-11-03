#include<bits/stdc++.h>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        vector<int> arr;
        for(int j=0;j<a;j++){
            string s;
            cin>>s;
            size_t index = s.find('#');
            arr.push_back(index);
        }
        for(int i=(arr.size()-1);i>=0;i--){
            cout<<(arr[i]+1)<<" ";
        }
        cout<<endl;
    
    }
    // string s = "....#";
    // size_t index = s.find('#');
    // cout<<index;
}