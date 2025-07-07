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


vector<int> shortestPath(vector<vector<int>>& adj, int src) {
    vector<int> dist(adj.size(), 1e9);
    
    // Fix: Initialize source distance to 0
    dist[src] = 0;
    
    queue<int> q;
    q.push(src);

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(auto it : adj[node]){
            // Fix: Check if this gives a shorter path
            if(dist[node] + 1 < dist[it]){
                dist[it] = dist[node] + 1;
                q.push(it);
            }
        }
    }
    return dist;
}

int main(){
    vector<vector<int>> grid = {{1,3},{0,2},{1,6},{0,4},{3,5},{4,6},{2, 5, 7, 8},{6, 8},{7,6}};

    vector<int> ans = shortestPath(grid,0);

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }


    
    
    
}

