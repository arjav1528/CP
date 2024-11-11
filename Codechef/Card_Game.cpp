#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n,x;
        cin>>n>>x;
        int count = 0;
        for(int i=1;i<=n;i++){
            if(i!=x && ((i+x)%2==0)){
                count++;
            }
        }
        cout<<count<<endl;
    }
}