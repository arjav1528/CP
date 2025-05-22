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

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    
    vector<vector<int>> finalAns;

    int i=0;

    while(i<intervals.size() && intervals[i][1] < newInterval[0]){
        finalAns.push_back(intervals[i]);
        i++;
    }

    while(i<intervals.size() && intervals[i][0] <= newInterval[1]){
        newInterval[0] = min(newInterval[0],intervals[i][0]);
        newInterval[1] = max(newInterval[1],intervals[i][1]);
        i++
    }

    while(i<intervals.size()){
        finalAns.push_back(intervals[i]);
        i++;
    }

    return finalAns;


    

        
}










int main(){
    
    // vector<int> ratings = {1,3,2,2,1};

    vector<vector<int>> vec = {{1,2},{3,5},{6,7},{8,10},{12,16}};
    // vector<vector<int>> vec = {{1,3},{6,9}};
    vector<int> newInterval = {4,8};

    vector<vector<int>> ans = insert(vec,newInterval);

    

    // cout<<ans[0]<<" "<<ans[1];







    
    // cout<<nums.size();

    
    


}

