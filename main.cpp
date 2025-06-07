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

int recurse(int index, int target, vector<int>& nums, vector<vector<int>> &dp, int offset) {
     
    if(dp[index][target + offset] != INT_MIN){
        return dp[index][target + offset];
    }
    if(index == 0){
        return (target == nums[0]) + (target == -nums[0]);
    }

    int l = recurse(index-1, target+nums[index], nums, dp, offset);
    int r = recurse(index-1, target-nums[index], nums, dp, offset);

    return dp[index][target + offset] = l+r;
}


int findTargetSumWays(vector<int>& nums, int target) {
    int totalSum = 0;
    for(int i = 0; i < nums.size(); i++) {
        totalSum += nums[i];
    }
    
    if(abs(target) > totalSum) return 0;
    
    if((totalSum - target) % 2 != 0) return 0;
    
    int sum = (totalSum + target) / 2;
    if(sum < 0) return 0;
    
    int n = nums.size();
    vector<int> prev(sum + 1, 0), curr(sum + 1, 0);
    
    prev[0] = 1;
    
    if(nums[0] <= sum) {
        prev[nums[0]] = 1;
    }
    
    for(int i = 1; i < n; i++) {
        for(int j = 0; j <= sum; j++) {
            int notTake = prev[j];
            int take = 0;
            if(nums[i] <= j) {
                take = prev[j - nums[i]];
            }
            curr[j] = notTake + take;
        }
        prev = curr;
    }
    
    return prev[sum];
}

int main(){

    vector<int> q = {1,1,1,1,1};
    int target = 3;
    vector<vector<int>> que = {{2,1,3},{6,5,4},{7,8,9}};

    cout<<findTargetSumWays(q,target);
    

}

