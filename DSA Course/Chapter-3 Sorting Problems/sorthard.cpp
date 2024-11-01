#include<bits/stdc++.h>
using namespace std;
// void fourSum(){
//     vector<int> arr = {-2,-1,0,0,1,2};
//     int target  = 0;
//     map<vector<int>,int> mpp;
//     for(int i=0;i<n;i++){
//         for(int j=(i+1);j<n;j++){
//             for(int k=(j+1);k<n;k++){
//                 mpp[{i,j,k}] = arr[i]+arr[j]+arr[k];

//             }
//         }
//     }
//     for(int i=0;i<n;i++){
//         for(auto it : mpp){
//             if((it.first[0] != i) && (it.first[1] != i) && (it.first[2] != i) && ((arr[i]+it.second) == target)){
//                 set<int> temp ={}
//             }
//         }
//     }

// }  
    
    
    

// }
int main(){
    // threeSum();
    vector<vector<int>> temp = {{1,4},{0,0}};
    sort(temp.begin(),temp.end());
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            cout<<temp[i][j]<<" ";
        }
        cout<<endl;
    }

}