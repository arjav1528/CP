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


int orangesRotting(vector<vector<int>>& grid) {

    queue<pair<pair<int,int>,int>> q;
    int n = grid.size();
    int m = grid[0].size();
    int vis[n][m];

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j] == 2){
                q.push({{i,j},0});
                vis[i][j] = 2;
            }else{
                vis[i][j] = 0;
            }
        }
    }

    int tm = 0;
    vector<int> drow = {-1,0,1,0};
    vector<int> dcol = {0,1,0,-1};

    while(!q.empty()){
        int r = q.front().first.first;
        int c = q.front().first.second;
        int t = q.front().second;
        q.pop();

        tm = max(t,tm);

        for(int i=0;i<4;i++){
            int nrow = r + drow[i];
            int ncol = c + dcol[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]!=2 && grid[nrow][ncol]==1){
                q.push({{nrow,ncol},t+1});
                vis[nrow][ncol] = 2;

            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(vis[i][j] != 2 && grid[i][j] ==1){
                return -1;
            }
        }
    }
    return tm;
        
}
int main(){

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

    cout << orangesRotting(grid);
}

