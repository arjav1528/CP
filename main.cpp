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
int findContentChildren(vector<int>& g, vector<int>& s) {

    sort(g.begin(),g.end());
    sort(s.begin(),s.end());
    int r = 0;
    int l = 0;

    while(l<s.size()){
        if(g[r] <= s[l]){
            r++;
        }
        l++;
    }

    return r;



    

        
        
}







int main(){
    



    
    // cout<<nums.size();

    
    


}

