#include<bits/stdc++.h>
using namespace std;
bool isComposite(int k){
    int temp = 2;
    while(temp<=(k/2)){
        if(k%temp==0){
            return true;
        }
    }
    return false;
}
int main(){
    int t;
    cin>>t;
    for(int w = 0;w<t;w++){
        int num;
        cin>>num;
        if((num == 2) || (num == 3) || (num == 4)){
            cout<<-1;
            continue;
        }
        else{
            vector<int> vec;
            for(int i=1;i<num;i++){
                if(i%2){
                    vec.push_back(i);
                }
            }
            for(int i=1;i<num;i++){
                if(i%2==0){
                    vec.push_back(i);
                }
            }
            int mid = (vec.size()-1)/2;
            if(isComposite(vec[mid] + vec[mid+1])){
                for(int i=0;i<vec.size();i++){
                    cout<<vec[i]<<" ";
                }
                cout<<endl;
                continue;
            }
            else{
                for(int i=mid+1;i<vec.size();i++){
                    if(isComposite(vec[i] + vec[mid])){
                        swap(vec[i],vec[mid+1]);
                        break;
                    }
                }
                for(int i=0;i<vec.size();i++){
                    cout<<vec[i]<<" ";
                }
                cout<<endl;
                continue;
            }
        }
    }
    
}