#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int len;
        cin>>len;
        string s;
        cin>>s;
        int n0 = 0;
        int n1 = 0;
        for(int i=0;i<s.size();i++){
            if(s[i] == '0'){
                n0++;
            }else{
                n1++;
            }
        }

        int finalAns = ((n0)*(n1+1))  +  ((n1)*(n1-1));

        cout<<finalAns<<endl;
    }
}