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

int eraseOverlapIntervals(vector<vector<int>>& intervals) {

    int count = 0;

    for(int i=0;i<(intervals.size()-1);i++){
        if(intervals[i][1] >= intervals[i+1][0]){
            count++;
        }
    }

    cout<<count;
        
}


vector<int> numCars(vector<pair<int,int>> cars, int N){
    vector<int> time(N,0);
    for(int i=0;i<cars.size();i++){

        time[cars[i].first]++;

        if(cars[i].second < N){
            time[cars[i].second]--;
        }
    }

    // for(int i=0;i<time.size();i++){
    //     cout<<time[i];
    // }

    for(int i=1;i<time.size();i++){
        time[i] += time[i-1];
    }

    return time;
}










int main(){
    
    // vector<int> ratings = {1,3,2,2,1};

    vector<pair<int,int>> vec = {{1,3},{2,4}};


    vector<int> ans = numCars(vec,5);

    for(int i=0;i<ans.size();i++){
        cout<<ans[i];
    }

    
    

    

    // cout<<ans[0]<<" "<<ans[1];







    
    // cout<<nums.size();

    
    


}

