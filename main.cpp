#include<bits/stdc++.h>
using namespace std;
class ListNode{
    public:
    int val;
    ListNode* next;
    // public :
    ListNode(int val1, ListNode* next1){
        val = val1;
        next = next1;
    }
    // public:
    ListNode(int val1){
        val = val1;
        next = nullptr;
    }
};
class Node{
    public:
        int val;
        Node* next;
        Node* random;
        
        Node(int val){
            val = val;
            next = nullptr;
            random = nullptr;
        };
        Node(int val,Node* random){
            val = val;
            random = random;

        }
};

bool customSort(vector<int> a, vector<int> b){
    if(a[1] == b[1]){
        return a[2]<b[2];
    }else{
        return a[1]<b[1];
    }
}
vector<int> JobScheduling(vector<vector<int>>& Jobs) {

    sort(Jobs.begin(),Jobs.end(),customSort);

    for(int i=0;i<Jobs.size();i++){
        for(int j=0;j<3;j++){
            cout<<Jobs[i][j]<<" ";
        }
        cout<<endl;
    }
    map<int,int> mpp;

    for(int i=0;i<Jobs.size();i++){
        mpp[Jobs[i][1]] = Jobs[i][2];
    }
    int sum = 0;

    for(auto it : mpp){
        sum += it.second;
    }

    int size = mpp.size();

    return {size,sum};

        
}








int main(){
    
    // vector<vector<int>> jobs =  { {1, 4, 20} , {2, 1, 10} , {3, 1, 40} , {4, 1, 30} };
    vector<vector<int>> jobs = { {1, 2, 100} , {2, 1, 19} , {3, 2, 27} , {4, 1, 25} , {5, 1, 15} };

    vector<int> ans = JobScheduling(jobs);

    cout<<ans[0]<<" "<<ans[1];







    
    // cout<<nums.size();

    
    


}

