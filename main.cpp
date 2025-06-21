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




int main(){
    Input input = Input();
    
    vector<vector<int>> grid = input.intInput();
    int ans = numEnclaves(grid);

    cout<<ans;



}

