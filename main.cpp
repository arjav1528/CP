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

void toposort(int node,vector<int> &vis, vector<vector<pair<int,int>>> adj,stack<int> &st){
    vis[node] = 1;

    for(auto it : adj[node]){
        if(!vis[it.first]){
            toposort(it.first,vis,adj,st);
        }
    }
    st.push(node);

}



int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

    vector<vector<pair<int,int>>> adj(n);

    for(int i=0;i<flights.size();i++){
        adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
    }

    queue<pair<int,pair<int,int>>> q;
    q.push({0,{src,0}});

    vector<int> dist(n,1e9);
    dist[src] = 0;

    while(!q.empty()){
        
        int stops = q.front().first;
        int node = q.front().second.first;
        int distance = q.front().second.second;

        q.pop();

        if(stops > k) continue;

        for(auto it : adj[node]){
            int edgeWt = it.second;
            if(distance + edgeWt < dist[it.first] && stops <= k){
                dist[it.first] = distance + edgeWt;
                q.push({stops+1,{it.first,distance + edgeWt}});
            }
        }
    }


    return dist[dst] == 1e9 ? -1 : dist[dst];


    


        
}




int main(){
    vector<vector<int>> grid = Input().intInput();


    cout<<findCheapestPrice(3,grid,0,2,0);


    
    
    
}

