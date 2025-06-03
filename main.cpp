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

int recurse(int i, int j, vector<vector<int>> matrix){
    
    if(j<0 || j>=matrix.size()){
        return INT_MAX;
    }

    if(i == 0){
        return matrix[i][j];
    }

    return matrix[i][j] + min(recurse(i-1,j-1,matrix),min(recurse(i-1,j,matrix),recurse(i-1,j+1,matrix)));
}




int minFallingPathSum(vector<vector<int>>& matrix) {
    int n = matrix.size();

    vector<int> dp(n,0), cur(n,0);

    dp = matrix[0];

    for(int i=1;i<matrix.size();i++){
        for(int j=0;j<matrix.size();j++){
            int s = matrix[i][j] + dp[j];
            int r = (j<=matrix.size()-2) ? matrix[i][j] + dp[j+1] : INT_MAX;
            int l = (j>=1) ? matrix[i][j] + dp[j-1] : INT_MAX;

            cur[j] = min(s,min(l,r));

        }
        dp = cur;
    }

    return *min_element(dp.begin(),dp.end());


}








int main(){

    vector<int> q = {2,7,9,3,1};
    int target = 8;
    vector<vector<int>> que = {{2,1,3},{6,5,4},{7,8,9}};
    // vector<vector<int>> que = {{-10}};
    cout<<minFallingPathSum(que);
    

}

