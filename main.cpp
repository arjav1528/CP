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

void recurse( int nrow, int ncol, vector<vector<int>> &image, vector<vector<int>> &visible, vector<int> drow, vector<int> dcol,int color, int initial){

    for(int i=0;i<4;i++){
        int r = nrow + drow[i];
        int c = ncol + dcol[i];

        if(r>=0 && r<image.size() && c>=0 && c<image[0].size() && visible[r][c]!=color && image[r][c] == initial){
            image[r][c] = color;
            visible[r][c] = color;
            recurse(r,c,image,visible,drow,dcol,color, initial);
        }

    }

}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    int n = image.size();
    int m = image[0].size();
    vector<vector<int>> visible(n, vector<int> (m, 0));
    int initial = image[sr][sc];
    visible[sr][sc] = color;
    image[sr][sc] = color;
    vector<int> drow = {-1,0,1,0};
    vector<int> dcol = {0,1,0,-1};

    recurse(sr,sc,image,visible,drow,dcol,color, initial);

    return image;
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

    vector<vector<int>> finalAns = floodFill(grid,1,1,2);


    for(int i=0;i<finalAns.size();i++){
        for(int j=0;j<finalAns[i].size();j++){
            cout<<finalAns[i][j]<<" ";
        }
        cout<<endl;
    }
}

