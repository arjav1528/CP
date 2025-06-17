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


void dfs(int node, vector<vector<int>>& adj, vector<int>& visited) {
    visited[node] = 1;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited);
        }
    }
}

int findCircleNum(vector<vector<int>>& isConnected) {
    int n = isConnected.size();
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (isConnected[i][j] == 1 && i != j) {
                adj[j].push_back(i);
            }
        }
    }

    // cout << "Adjacency List:" << endl;
    // for (int i = 0; i < n; i++) {
    //     cout << i << ": ";
    //     for (int neighbor : adj[i]) {
    //         cout << neighbor << " ";
    //     }
    //     cout << endl;
    // }
    int count = 0;
    vector<int> visited(n, 0);
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            count++;
            dfs(i, adj, visited);
        }
    }
    return count;
}
int main(){

    vector<vector<int>> isConnected = {{1,1,0},{1,1,0},{0,0,1}};

    cout<<findCircleNum(isConnected);
    

}

