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

class Input{
    public:
        vector<vector<int>> intInput(){
            vector<vector<int>> grid;
            string input;
            cin >> input;


            vector<int> row;
            int num = 0;
            bool building_num = false;
            for (size_t i = 0; i < input.size(); ++i) {
                char ch = input[i];
                if (isdigit(ch)) {
                    num = num * 10 + (ch - '0');
                    building_num = true;
                } else if (ch == ',' || ch == ']') {
                    if (building_num) {
                        row.push_back(num);
                        num = 0;
                        building_num = false;
                    }
                    if (ch == ']') {
                        if (!row.empty()) {
                            grid.push_back(row);
                            row.clear();
                        }
                    }
                }
            }

            return grid;

        }

     public:
        vector<vector<char>> charInput(){
            vector<vector<char>> grid;
            string input;
            cin >> input;

            vector<char> row;
            for (size_t i = 0; i < input.size(); ++i) {
                char ch = input[i];
                if (ch >= 'A' && ch <= 'Z' || ch >= 'a' && ch <= 'z' || ch >= '0' && ch <= '9' || ch == '.' || ch == '#' || ch == 'X' || ch == 'O') {
                    // Add any specific characters you expect in your grid
                    row.push_back(ch);
                } else if (ch == ',' || ch == ']') {
                    if (ch == ']') {
                        if (!row.empty()) {
                            grid.push_back(row);
                            row.clear();
                        }
                    }
                }
            }

            return grid;

        }
};

class Output{
    public:
        static void intOutput(vector<vector<int>> vec){
            for(int i=0;i<vec.size();i++){
                for(int j=0;j<vec[i].size();j++){
                    cout<<vec[i][j]<<" ";
                }
                cout<<endl;
            }
        }
    
    public:
        static void charOutput(vector<vector<char>> vec){
            for(int i=0;i<vec.size();i++){
                for(int j=0;j<vec[i].size();j++){
                    cout<<vec[i][j]<<" ";
                }
                cout<<endl;
            }
        }

};


void topoSort(int node, vector<vector<pair<int,int>>> adj, stack<int> &s, vector<int> &vis){
    vis[node] = 1;
    for(auto it : adj[node]){
        if(!vis[it.first]){
            topoSort(it.first,adj,s,vis);
        }
    }

    s.push(node);
}

vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
    // Fix: Use V instead of edges.size() for adjacency list
    vector<vector<pair<int,int>>> adj(V);
    for(int i=0;i<edges.size();i++){ 
        adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
    }

    stack<int> s;
    vector<int> vis(V,0);
    
    for(int i=0;i<V;i++){
        if(!vis[i]) {
            topoSort(i,adj,s,vis);
        }
    }

    vector<int> dist(V, INT_MAX);
    dist[0] = 0; 
    
    while(!s.empty()) {
        int u = s.top();
        s.pop();
        
        if(dist[u] != INT_MAX) {
            for(auto it : adj[u]) {
                int v = it.first;
                int weight = it.second;
                if(dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                }
            }
        }
    }
    
    return dist;
}




int main(){
    vector<vector<int>> grid = {
        {0,1,2}, 
        {0,4,1}, 
        {4,5,4}, 
        {4,2,2}, 
        {1,2,3}, 
        {2,3,6}, 
        {5,3,1}
    };
    vector<int> ans = shortestPath(6,7,grid);


    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }


    
    
    
}

