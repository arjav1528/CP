#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    string num = "52";
    string s;
    for(int i=num.size()-1;i>=0;i--){
        char t = num[i];

            // string s = "";
        if(t == 49 || t == 51 || t == 53 || t == 55 || t == 57){
            s = num.substr(0,i);
            break;
            // return s;

        }
            
    }
    cout<<s;
    // return num;
}
