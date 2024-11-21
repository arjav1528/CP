#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    for(int w=0;w<t;w++){
        int k;
        cin>>k;
        vector<int> arr(k);
        unordered_map<int,int> mpp;
        for(int i=0;i<k;i++){
            cin>>arr[i];
        }
        for(int i=0;i<k;i++){     
            if((mpp.find(((k-2)/arr[i])) != mpp.end())  &&  ((k-2)%arr[i])==0){
                cout<<min(arr[i],((k-2)/arr[i]))<<" "<<max(arr[i],((k-2)/arr[i]))<<endl;
                break;
            }
            mpp[arr[i]] = i;  
        }
        // cout<<"TP"<<endl;
        

    }
}