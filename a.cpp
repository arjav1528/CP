#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    string s = "abcde";
    string goal = "cdeab";
    string str = s+s;
    cout<<str.find(goal);
    // cout<<s;
    // return num;
}
