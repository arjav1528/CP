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
bool lemonadeChange(vector<int>& bills) {

    int five = 0;
    int ten = 0;
    int twenty = 0;

    for(int i=0;i<bills.size();i++){
        if(bills[i] == 5){
            five++;
        }else if(bills[i] == 10){
            ten++;
            if(five >= 1){
                five--;
            }else{
                return false;
            }
        }else if(bills[i] == 20){
            twenty++;
            if(ten>=1){
                if(five>=1){
                    ten--;
                    five--;
                }else{
                    return false;
                }
            }else{
                if(five>=3){
                    five-=3;
                }else{
                    return false;
                }
            }
        }
    }
    return true;
        
}







int main(){
    



    
    // cout<<nums.size();

    
    


}

