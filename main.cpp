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

int eraseOverlapIntervals(vector<vector<int>>& intervals) {

    int count = 0;

    for(int i=0;i<(intervals.size()-1);i++){
        if(intervals[i][1] >= intervals[i+1][0]){
            count++;
        }
    }

    cout<<count;
        
}


vector<int> numCars(vector<pair<int,int>> cars, int N){
    vector<int> time(N,0);
    for(int i=0;i<cars.size();i++){

        time[cars[i].first]++;

        if(cars[i].second < N){
            time[cars[i].second]--;
        }
    }

    // for(int i=0;i<time.size();i++){
    //     cout<<time[i];
    // }

    for(int i=1;i<time.size();i++){
        time[i] += time[i-1];
    }

    return time;
}


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






int main(){
    
    // vector<int> ratings = {1,3,2,2,1};

    // vector<pair<int,int>> vec = {{1,3},{2,4}};
    vector<int> adj[] = {{2, 3, 1}, {0}, {0, 4}, {0}, {2}};


    vector<int> ans = dfsOfGraph(5,adj);

    for(int i=0;i<ans.size();i++){
        cout<<ans[i];
    }


    return 0;

    
    

    

    // cout<<ans[0]<<" "<<ans[1];







    
    // cout<<nums.size();

    
    


}

