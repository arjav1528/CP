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

int recurse(int m,int n){

    int top = 0;
    int left = 0;
    if(m==0 || n==0){
        return 1;
    }

    if(m>0){
        top = recurse(m-1,n);
    }
    if(n>0){
        left = recurse(m,n-1);
    }
    return top+left;


    
    

}
int uniquePaths(int m, int n) {
    

    vector<int> dp(n,0);
    int up;
    int left;

    for(int i=0;i<m;i++){
        vector<int> temp(n,0);

        for(int j=0;j<n;j++){
            if(i==0 && j==0){
                temp[j] = 1;
            }else{
                up = i>0 ? dp[j] : 0;
                left = j>0 ? temp[j-1] : 0;
                temp[j] = up+left;
            }
            
        }
        dp = temp;
    }
    

    
    return dp[n-1];
    

}








int main(){

    vector<int> q = {2,7,9,3,1};
    int target = 8;
    vector<vector<int>> que = {{1,2,5}, {3 ,1 ,1} ,{3,3,3}};

    cout<<uniquePaths(3,7);
    

}

