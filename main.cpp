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

vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
    vector<vector<pair<int,int>>> adj(n+1);

    for(auto it : edges){
        adj[it[0]].push_back({it[1],it[2]});
        adj[it[1]].push_back({it[0],it[2]});
    }

    stack<pair<int,int>> st;
    st.push({0,1});
    vector<int> dist(n+1, 1e9), parent(n+1);
    vector<bool> visited(n+1, false);
    dist[1] = 0;
    for(int i=1;i<=n;i++) parent[i] = i;

    while(!st.empty()){
        int wt = st.top().first;
        int node = st.top().second;
        st.pop();
        
        if(visited[node]) continue;
        visited[node] = true;
        
        for(auto neighbor : adj[node]){
            int adjNode = neighbor.first;
            int edgeWt = neighbor.second;
            
            if(!visited[adjNode] && wt + edgeWt < dist[adjNode]){
                dist[adjNode] = wt + edgeWt;
                parent[adjNode] = node;
                st.push({dist[adjNode], adjNode});
            }
        }
    }
    
    if(dist[n] == 1e9) return {-1};
    vector<int> path;
    int current = n;
    while(parent[current] != current){
        path.push_back(current);
        current = parent[current];
    }
    path.push_back(1);
    
    reverse(path.begin(), path.end());
    return path;
}



int main(){
    vector<vector<int>> grid = {
        {1, 2, 2}, {2, 5, 5}, {2, 3, 4}, {1, 4, 1}, {4, 3, 3}, {3, 5, 1}

    };
    vector<int> ans = shortestPath(5,grid.size(),grid);


    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }


    
    
    
}

