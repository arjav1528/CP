#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    string str = "the sky is blue";
    str += ' ';
    vector<string> vec;
    int i=0;
    string s = "";
    while(i<str.size()){
        if(str[i]==' ' && (s.size() != 0)){
            vec.push_back(s);
            s = "";
            i++;
        }
        else if(str[i] == ' ' && (s.size() == 0)){
            i++;
        }
        else{
            s = s + str[i];
            i++;
        }
    }
    for(int i=0;i<vec.size();i++){
        cout<<vec[i]<<" ";
    }
}
