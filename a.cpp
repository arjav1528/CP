#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    string s = "-13+8";
    int j=0;
        while(j<s.size()){
            if(s[j]==' '){
                s.erase(s.begin());
            }
            else{
                break;
            }
        }
        long long int final = 0;
        int count = 0;
        if(s[0]=='-'){
            if(s[1] == '+' || s[1]=='-'){
                return 0;
            }
            else{
                count++;
                s.erase(s.begin());
            }
        }  
        for(int i=0;i<s.size();i++){
            // if(s[i]=='+'){
            //     continue;
            // }
            
            if((48 <= s[i]) && (s[i] <= 57)){
                final = (final*10) + (s[i]-48);
                if(count){
                    final = final*-1;
                    if(final<INT_MIN){
                        cout<<INT_MIN;
                        return 0;

                    }
                    final = final*-1;
                }
                else{
                    if(final>INT_MAX){
                        cout<<INT_MAX;
                        return 0;
                    }
                }

            }
            else{
                break;
            }
        }
        if(count){
            cout<<(final*(-1));
        }
        else{
            cout<<final;
        }
}
