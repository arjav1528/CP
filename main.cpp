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

int recurse(int m, int n, vector<vector<int>> obstacleGrid){
    if (m < 0 || n < 0 || obstacleGrid[m][n] == 1) {
        return 0;
    }
    if(m==0 && n==0){
        return 1;
    }

    
    int up = recurse(m-1,n,obstacleGrid);
    int right = recurse(m,n-1,obstacleGrid);


    return up+right;

}


int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

    return recurse(obstacleGrid.size()-1,obstacleGrid[0].size()-1,obstacleGrid);

        
}








int main(){

    vector<int> q = {2,7,9,3,1};
    int target = 8;
    vector<vector<int>> que = {{0,0,0},{0,1,0},{0,0,0}};

    cout<<uniquePathsWithObstacles(que);
    

}

