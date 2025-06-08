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

vector<int> bfsOfGraph(int V, vector<int> adj[]){
    
    int vis[V] = {0};
    queue<int> q;
    vector<int> bfs;
    q.push(0);
    vis[0] = 1;

    while(!q.empty()){
        int node = q.front();
        bfs.push_back(node);

        q.pop();

        for(auto it : adj[node]){
            if(!vis[it]){
                // cout<<it<<endl;
                vis[it] = 1;
                q.push(it);

            }
        }
        
    }

    return bfs;
}

void dfs(int node, vector<int> adj[],int vis[], vector<int> &ls){

    vis[node] = 1;

    ls.push_back(node);

    for(auto it : adj[node]){
        if(!vis[it]){
            dfs(it,adj,vis,ls);
        }
    }

}




vector<int> dfsOfGraph(int V, vector<int> adj[]){
    int vis[V] = {0};
    vector<int> ls;
    int start = 0;

    dfs(start,adj,vis,ls);

    return ls;




}

int recurse(int index1, int index2, string text1, string text2) {

    if(index1<0 || index2<0) return 0;

    if(text1[index1] == text2[index2]){
        return 1 + recurse(index1-1,index2-1,text1,text2);
    }else{
        return max(recurse(index1-1,index2,text1,text2), recurse(index1,index2-1,text1,text2));
    }
}



int longestCommonSubsequence(string text1, string text2) {
    // return recurse(text1.length()-1,text2.length()-1,text1,text2);
    int m = text1.length();
    int n = text2.length();
    vector<int> dp(m+1,0),cur(m+1,0);
    

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(text1[j-1] == text2[i-1]){
                cur[j] = 1 + dp[j-1];
                // ans = ans + text1[j-1];
            }else{
                cur[j] = max(dp[j],cur[j-1]);
            }
        }
        dp = cur;
    }

    return dp[m];
        
}

int longestPalindromeSubseq(string s) {

    string t = s;
    reverse(t.begin(),t.end());

    return longestCommonSubsequence(s,t);
        
        
}

int main(){

    string text1 = "cbbd";
    string text2 = text1;
    reverse(text2.begin(),text2.end());
    string ans = "";
    vector<vector<int>> que = {{2,1,3},{6,5,4},{7,8,9}};

    cout<<longestCommonSubsequence(text1,text2);
    cout<<ans;
    

}

