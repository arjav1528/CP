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
bool checkValidString(string s) {

    int cmin = 0;
    int cmax = 0;
    
    for(int i=0;i<s.length();i++){
        if(s[i] == '('){
            cmax++;
            cmin++;
        }else if(s[i] == ')'){
            cmax--;
            cmin--;
        }else{
            cmin--;
            cmax++;
        }

        if(cmin<0){
            cmin=0;
        }
        if(cmax < 0){
            return false;
        }
    }

    if(cmin <= 0 && 0 <= cmax){
        return true;
    }else{
        return false;
    }
    
        
}

bool canJump(vector<int>& nums) {
    int max = 0;

    for(int i=0;i<nums.size();i++){
        if(i>max){
            return false;
        }
        max = nums[i]+i;
        if(max>=nums.size()){
            return true;
        }
        
    }
    return true;
        
}

int jump(vector<int>& nums) {
        

    int count = 0;

        int l = 0;
        int r = 0;
        int jumps = 0;

        while(r<nums.size()-1){
            int farthest = 0;

            for(int i=l;i<=r;i++){
                farthest = max(farthest,i+nums[i]);
            }

            l = r+1;
            r = farthest;
            jumps++;
        }        

    return jumps;
        
}

bool customSort(pair<int,int> a, pair<int,int>b){
    return a.first < b.first;
}

int findPlatform(vector<int>& Arrival, vector<int>& Departure){

    vector<pair<int,char>> arr;

    for(int i=0;i<Arrival.size();i++){
        arr.emplace_back(Arrival[i],'A');
        arr.emplace_back(Departure[i],'D');
    }

    sort(arr.begin(),arr.end(),customSort);
   
    int len = 0;
    int maxLen = 0;

    for(int i=0;i<arr.size();i++){
        if(arr[i].second == 'A'){
            len++;
        }else{
            maxLen = max(maxLen,len);
            len = 0;
        }
    }

    return maxLen;




}







int main(){
    
    vector<int> arrival = {900, 940, 950, 1100, 1500, 1800};
    vector<int> departure = {910, 1200, 1120, 1130, 1900, 2000};

    cout<<findPlatform(arrival,departure);





    
    // cout<<nums.size();

    
    


}

