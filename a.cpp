#include<bits/stdc++.h>
using namespace std;
bool isBalanced(string num) {
        int even = 0;
        int odd = 0;
        for(int i=0;i<(num.size());i++){
            if(i%2){
                even+=int(num[i]);
                cout<<even<<endl;
            }
            else{
                odd+=int(num[i]);
                cout<<odd<<endl;
            }
        }
        // if(odd==even){
        //     return true;
        // }
        // else{
        //     return false;
        // }
        
    }
int main(){
    // cout<<isBalanced("12345");
    string a = "23456";
    cout<<int(a[0]);
}