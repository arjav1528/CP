#include<bits/stdc++.h>
using namespace std;
int factorial(int n)
{
    int res = 1;
    for (int i = 2; i <= n; i++)
        res *= i;
    return res;
}
bool divBy7(int n,int d){
    if(n>=7 || (d%7==0)){
        return true;
    }
    else{
        int num = 0;
        int factn = factorial(n);
        for(int i=0;i<factn;i++){
            num = 10*num + d;
        }
        if(((num-2)%7)==0){
            return true;
        }
        else{
            return false;
        }


    }

}
int main(){
    int t;
    cin>>t;
    for(int w=0;w<t;w++){
        int n,d;
        cin>>n>>d;
        vector<int> vec(5,0);
        vec[0] = 1;
        if((d%3==0) || (n>=3)){
            vec[1] = 1;
            
        }
        if((((d%10)%5)==0)){
            vec[2] = 1;
        }
        if(divBy7(n,d)){
            vec[3] = 1;
        }
        if(n>=6 || (d%9==0)){
            vec[4] = 1;
        }
        for(int i=0;i<5;i++){
            if(vec[i]==1){
                cout<<((2*i)+1)<<" ";
            }
        }
        cout<<endl;
        



        
    }
}