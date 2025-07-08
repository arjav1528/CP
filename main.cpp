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

void dfs(int x, int){

}

int minimumEffortPath(vector<vector<int>>& heights) {

    int n = heights.size();
    int m = heights[0].size();
    
    vector<vector<int>> dist(heights.size(),vector<int>(heights[0].size(),1e9));
    set<pair<int,pair<int,int>>> st;
    st.insert({0,{0,0}});
    dist[0][0] = 0;
    vector<int> drow = {-1,0,1,0};
    vector<int> dcol = {0,1,0,-1};

    while(!st.empty()){
        auto it = *st.begin();
        int distance = it.first;
        int row = it.second.first;
        int col = it.second.second;

        if(row == n-1 && col == m-1) return distance;

        st.erase(st.begin());

        for(int i=0;i<4;i++){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                int newEffort = max(distance,abs(heights[row][col] - heights[nrow][ncol]));
                if(newEffort < dist[nrow][ncol]){
                    dist[nrow][ncol] = newEffort;
                    st.insert({newEffort,{nrow,ncol}});
                }
            }
        }
    }

    return 0;

        
}




int main(){
    vector<vector<int>> grid = Input().intInput();


    cout<<minimumEffortPath(grid);


    
    
    
}

