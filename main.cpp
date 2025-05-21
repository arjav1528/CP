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







int main(){
    vector<int> nums = {2,3,1,1,4};

    cout<<jump(nums);



    
    // cout<<nums.size();

    
    


}

