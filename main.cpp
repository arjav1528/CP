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

int recurse(int index, vector<int> heights){

    if(index <= 0) return 0;

    int step1 = recurse(index-1,heights) + abs(heights[index] - heights[index-1]);
    int step2 = INT_MAX;

    if(index > 1){
        step2 = recurse(index-2,heights) + abs(heights[index] - heights[index-2]); 
    }
    return min(step1,step2);


}

int frogJump(vector<int>& heights) {

    int prev1 = 0;
    int prev2 = 0;
    int cur = 0;

    int step1 = INT_MAX;
    int step2 = INT_MAX;

    for(int i = 1;i<heights.size();i++){

        step1 = prev1 + abs(heights[i] - heights[i-1]);
        if(i > 1){
            step2 = prev2 + abs(heights[i] - heights[i-2]);
        }else{
            step2 = INT_MAX;
        }

        cur = min(step1,step2);

        prev2 = prev1;
        prev1 = cur;
        
        


    }
    return prev1;

}

int frogJump(vector<int>& heights, int k) {
    int n = heights.size();
    if (n == 1) return 0;
    
    vector<int> dp(k, INT_MAX);
    dp[0] = 0;     
    for(int i = 1; i < n; i++) {
        int currentCost = INT_MAX;
        
        for(int j = 1; j <= k && j <= i; j++) {
            int jumpCost = dp[(i-j) % k] + abs(heights[i] - heights[i-j]);
            currentCost = min(currentCost, jumpCost);
        }
        dp[i % k] = currentCost;
    }
    
    return dp[(n-1) % k];
}









int main(){

    vector<int> q = {7, 5, 1, 2, 6};
    int target = 8;

    cout<<frogJump(q,2);
    

}

