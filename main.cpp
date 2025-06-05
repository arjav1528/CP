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

bool recurse(int index, int target, vector<int> arr){

    if(target == 0) return true;
    if(index == 0) return (arr[0] == target);

    bool notTake = recurse(index-1,target,arr);

    bool take = false;

    if(arr[index] <= target) take = recurse(index-1,target-arr[index],arr);

    return take | notTake;
    
    
}



bool subsetSumtoX(int n, int k, vector<int> &arr){

    // return recurse(n-1,k,arr);
    vector<bool> dp(k+1,false), cur(k+1,false);
    dp[arr[0]] = true;
    dp[0] = true;
    cur[0] = true;

    for(int index = 1;index<n;index++){
        for(int target = 1;target<=k;target++){

            bool take = false;
            bool notTake = dp[target];
            if(arr[index] <= target) take = dp[target-arr[index]];

            cur[target] = take | notTake;


        }

        dp = cur;
    }

    return dp[k];



}








int main(){

    vector<int> q = {4,3,2,1};
    int target = 8;
    vector<vector<int>> que = {{2,1,3},{6,5,4},{7,8,9}};
    // vector<vector<int>> que = {{-10}};
    cout<<subsetSumtoX(4,11,q);
    

}

