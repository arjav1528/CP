#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    for(int j=0;j<t;j++){
        int n,x;
        cin>>n>>x;
        vector<int> A(n),B(n);
        for(int i=0;i<n;i++) cin>>A[i];
        for(int i=0;i<n;i++) cin>>B[i];
        int count = 0;
        int req = ((n/2)+1);
        vector<int> diff;
        for(int i=0;i<n;i++){
            if(B[i]-A[i] < 0){
                count++;
            }
            else{
                diff.push_back((B[i] - A[i] + 1));
            }
        }
        if(count>=req){
            cout<<"YES"<<endl;
            continue;
        }
        sort(diff.begin(),diff.end());
        for(int i=0;(i<diff.size()) && (x>=diff[i]) && (count<req);i++){
            x-=diff[i];
            count++;
        }
        if(count >= req){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }

        
        
    }
}