#include<bits/stdc++.h>
using namespace std;
long long coins(long long n){
    if(n < 4){
        return 1;
    }
    else{
        return 2*coins(n/4);
    }
}

int main(){
    int w;
    cin>>w;
    for(int t=0;t<w;t++){
        long long n;
        cin>>n;
        cout<<coins(n)<<endl;

    }
    
}