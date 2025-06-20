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

void solve(vector<vector<char>>& board) {
    int n = board.size();
    int m = board[0].size();
    vector<vector<int>> vis(n,vector<int>(m,0));
    queue<pair<pair<int,int>,int>> q;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j] == 'O'){
                vis[i][j] = 0;
            }else{
                q.push({{i,j},0});
                vis[i][j] = 1;
            }
        }
    }

    vector<int> drow = {-1,0,1,0};
    vector<int> dcol = {0,1,0,-1};

    while(!q.empty()){
        int row = q.front().first.first;
        int col = q.front().first.second;
        int step = q.front().second;

        q.pop();

        board[row][col] = 'X';

        for(int i=0;i<4;i++){
            int r = row + drow[i];
            int c = col + dcol[i];

            if(r>=0 && r<n && c>=0 && c<m && vis[r][c]==0){
                q.push({{r,c},step+1});
                vis[r][c] = 1;

            }
        }
    }
    

    // for(int i=0;i<vis.size();i++){
    //     for(int j=0;j<vis[i].size();j++){
    //         cout<<vis[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
        
}


int main(){
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

    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[i].size();j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }


    cout<<endl<<endl;

    solve(grid);


    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[i].size();j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }









    //  vector<vector<int>> grid;
    // string input;
    // cin >> input;


    // vector<int> row;
    // int num = 0;
    // bool building_num = false;
    // for (size_t i = 0; i < input.size(); ++i) {
    //     char ch = input[i];
    //     if (isdigit(ch)) {
    //         num = num * 10 + (ch - '0');
    //         building_num = true;
    //     } else if (ch == ',' || ch == ']') {
    //         if (building_num) {
    //             row.push_back(num);
    //             num = 0;
    //             building_num = false;
    //         }
    //         if (ch == ']') {
    //             if (!row.empty()) {
    //                 grid.push_back(row);
    //                 row.clear();
    //             }
    //         }
    //     }
    // }




    // vector<vector<char>> finalAns = solve(grid);
    
    // for(int i=0;i<finalAns.size();i++){
    //     for(int j=0;j<finalAns[i].size();j++){
    //         cout<<finalAns[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
}

