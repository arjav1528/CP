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

void recurse(vector<int> nums,int index, vector<int> &ls, vector<vector<int>> &finalList){
    finalList.push_back(ls);

    for(int i=index;i<nums.size();i++){
        ls.push_back(nums[i]);
        recurse(nums,i+1,ls,finalList);
        ls.pop_back();

    }

}

vector<vector<int>> subsets(vector<int>& nums) {

    vector<vector<int>> finalList;
    vector<int> ls;

    for(int i=0;i<pow(2,nums.size());i++){

        ls = {};
        for(int j=0;j<nums.size();j++){
            if(i & (1<<j)){
                ls.push_back(nums[j]);
            }
        }

        finalList.push_back(ls);

    }

    return finalList;
        
}

void generateSumDuplicatesAllowed(int index, vector<vector<int>> &finalAns, vector<int> ds, vector<int> arr, int target){
    if(index == arr.size()){
        if(target == 0){
            // sort(ds.begin(),ds.end());
            finalAns.push_back(ds);
        }
        return;
    }

    if(arr[index] <= target){
        ds.push_back(arr[index]);
        generateSumDuplicatesAllowed(index,finalAns,ds,arr,target-arr[index]);
        ds.pop_back();
    }

    generateSumDuplicatesAllowed(index+1,finalAns,ds,arr,target);
}


void generateSumDuplicatesNotAllowed(int index,vector<vector<int>> &finalAns, vector<int> ds, vector<int> arr, int sum, int target){
    if(index == arr.size()){
        if(sum == target){
            sort(ds.begin(),ds.end());

            for(int i=0;i<finalAns.size();i++){
                if(finalAns[i] == ds){
                    return;
                }
            }
            finalAns.push_back(ds);
        }
        return;
    }

    ds.push_back(arr[index]);
    sum+= arr[index];

    generateSumDuplicatesNotAllowed(index+1,finalAns,ds,arr,sum,target);

    sum -= arr[index];
    ds.pop_back();

    generateSumDuplicatesNotAllowed(index+1,finalAns,ds,arr,sum,target);
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

    vector<vector<int>> finalAns;

    vector<int> ds;

    generateSumDuplicatesNotAllowed(0,finalAns,ds,candidates,0,target);

    


    return finalAns;
    
        
}









int main(){

    vector<int> q = {10,1,2,7,6,1,5};
    int target = 8;

    vector<vector<int>> ans = combinationSum(q,target);

    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<",";
        }

        cout<<endl;
    }
}

