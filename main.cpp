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

int recurse(int index,int j, vector<vector<int>> triangle){

    if(triangle.size() == 1){
        return triangle[0][0];
    }
    if(index == 0){
        return triangle[0][0];
    }else{
        int l = recurse(index-1,j-1,triangle);
        int r = recurse(index-1,j,triangle);
        return (triangle[index][j] + min(l,r));
    }
    
    
    
}




int minimumTotal(vector<vector<int>>& triangle) {
    
    vector<int> dp = {triangle[0][0]};

    for(int i=1;i<triangle.size();i++){
        vector<int> temp(i+1,0);

        for(int j=0;j<i+1;j++){
            if(j == 0){
                temp[j] = triangle[i][j] + dp[j];
            }else if(j==i){
                temp[j] = triangle[i][j] + dp[j-1];
            }else{
                temp[j] = triangle[i][j] + min(dp[j],dp[j-1]);
            }
        }

        dp = temp;
    }

    return *min_element(dp.begin(),dp.end());
        
}








int main(){

    vector<int> q = {2,7,9,3,1};
    int target = 8;
    vector<vector<int>> que = {{2},{3,4},{6,5,7},{4,1,8,3}};
    // vector<vector<int>> que = {{-10}};
    cout<<minimumTotal(que);
    

}

