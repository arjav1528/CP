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

vector<int> bfsOfGraph(int V, vector<int> adj[]){
    
    int vis[V] = {0};
    queue<int> q;
    vector<int> bfs;
    q.push(0);
    vis[0] = 1;

    while(!q.empty()){
        int node = q.front();
        bfs.push_back(node);

        q.pop();

        for(auto it : adj[node]){
            if(!vis[it]){
                // cout<<it<<endl;
                vis[it] = 1;
                q.push(it);

            }
        }
        
    }

    return bfs;
}

void dfs(int node, vector<int> adj[],int vis[], vector<int> &ls){

    vis[node] = 1;

    ls.push_back(node);

    for(auto it : adj[node]){
        if(!vis[it]){
            dfs(it,adj,vis,ls);
        }
    }

}




vector<int> dfsOfGraph(int V, vector<int> adj[]){
    int vis[V] = {0};
    vector<int> ls;
    int start = 0;

    dfs(start,adj,vis,ls);

    return ls;




}

// void recurse(vector<int> nums,int index, vector<int> &ls, vector<vector<int>> &finalList){
//     finalList.push_back(ls);

//     for(int i=index;i<nums.size();i++){
//         if(i!=index && nums[i] == nums[i-1]){
//             continue;
//         }else{
//             ls.push_back(nums[i]);
//             recurse(nums,i+1,ls,finalList);
//             ls.pop_back();
//         }

//     }

// }

// vector<vector<int>> subsets(vector<int>& nums) {

//     vector<vector<int>> finalList;
//     vector<int> ls;

//     recurse(nums,0,ls,finalList);

//     return finalList;
        
// }


void recurse(int target, int index, vector<vector<int>> &finalAns, vector<int> ds,vector<int> arr){
    if(index == arr.size()){
        if(target == 0){
            finalAns.push_back(ds);
        }

        return;
    }

    if(arr[index] <= target){

        ds.push_back(arr[index]);

        recurse(target-arr[index],index,finalAns,ds,arr);

        ds.pop_back();
    }

    recurse(target,index+1,finalAns,ds,arr);

}


vector<vector<int>> climbStairs(int n) {

    vector<vector<int>> finalAns;
    vector<int> arr = {1,2};
    vector<int> ds = {};

    recurse(n,0,finalAns,ds,arr);

    return finalAns;

    
        
        
}



void dp(int n){
    int prev = 1;
    int prev2 = 0;
    int num = -1;

    
}










int main(){

    vector<int> q = {1,2,2};
    int target = 8;

    // vector<vector<int>> ans = subsets(q);

    // for(int i=0;i<ans.size();i++){
    //     for(int j=0;j<ans[i].size();j++){
    //         cout<<ans[i][j]<<",";
    //     }

    //     cout<<endl;
    // }
    vector<vector<int>> ans = climbStairs(3);

    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}

