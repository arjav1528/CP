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


int rob(vector<int>& nums) {
    int prev = nums[0];
    int prev2 = 0;
    
    int cur = -1;
    
    for(int i=1;i<nums.size();i++){
        
        cur = max(prev,prev2+nums[i]);
        prev2 = prev;
        prev = cur;
    }
    
    return prev;
    
}
int recurse(int index, int last, vector<vector<int>>& points) {
    if (index == 0) {
        int maxi = INT_MIN;
        for (int i = 0; i < 3; i++) {
            if (i != last) {
                maxi = max(maxi, points[0][i]);
            }
        }
        return maxi;
    }
    
    int maxi = INT_MIN;
    for (int i = 0; i < 3; i++) {
        if (i != last) {
            maxi = max(maxi, points[index][i] + recurse(index - 1, i, points));
        }
    }
    return maxi;
}

int ninjaTraining(vector<vector<int>> &points) {
    // return recurse(points.size() - 1, 3, points);
    vector<int> dp(4,0);
    dp[0] = max(points[0][1],points[0][2]);
    dp[1] = max(points[0][2],points[0][0]);
    dp[2] = max(points[0][0],points[0][1]);
    dp[3] = max(points[0][1],max(points[0][2],points[0][0]));

    for(int day=1;day<points.size();day++){
        vector<int> temp(4,0);

        for(int last = 0;last<4;last++){

            temp[last] = 0;

            for(int i=0;i<3;i++){

                if(i != last){
                    temp[last] = max(temp[last],points[day][i] + dp[i]);
                }

            }
        }
        dp = temp;

    }

    return dp[3];


    
    
    
}









int main(){

    vector<int> q = {2,7,9,3,1};
    int target = 8;
    vector<vector<int>> que = {{1,2,5}, {3 ,1 ,1} ,{3,3,3}};

    cout<<ninjaTraining(que);
    

}

