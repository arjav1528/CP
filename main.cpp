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

int recurse(int index, int target, vector<int>& coins) {
    if (target == 0) return 0;
    
    if(index == 0){
        if(target%coins[0]==0){
            return target/coins[0];
        }
        return INT_MAX-1;
    }
    
    int notTake = recurse(index - 1, target, coins);
    
    int take = INT_MAX - 1;
    if (coins[index] <= target) 
        take = 1 + recurse(index, target - coins[index], coins);
    
    return min(take, notTake);  
}

int coinChange(vector<int>& coins, int amount) {
    // int result = recurse(coins.size() - 1, amount, coins);
    // return result == INT_MAX - 1 ? -1 : result;

    vector<int> dp(amount+1,0),cur(amount+1,0);

    if(amount == 0) return 0;

    for(int T=0;T<=amount;T++){
        if(T%coins[0] == 0){
            dp[T] = T/coins[0];
        }else{
            dp[T] = INT_MAX-1;
        }
    }


    for(int i=1;i<coins.size();i++){
        for(int T=0;T<=amount;T++){
            int notTake = dp[T];

            int take = INT_MAX-1;

            if(coins[i] <= T){
                take = 1 + cur[T-coins[i]];
            }

            cur[T] = min(take,notTake);
        }

        dp = cur;
    }

    return dp[amount];
    
}









int main(){

    vector<int> q = {1,2,5};
    int target = 8;
    vector<vector<int>> que = {{2,1,3},{6,5,4},{7,8,9}};
    // vector<vector<int>> que = {{-10}};
    cout<<coinChange(q,11);
    

}

