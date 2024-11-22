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
class Solution {
public :
    void printArray(vector<int> &arr){
        for(int i=0;i<arr.size();i++){
            cout<<arr[i]<<" "; 
        }
        cout<<endl;
    }
public : 
    vector<int> takeInputArray(){
        int len;
        cin>>len;
        vector<int> vec(len);
        for(int i=0;i<len;i++){
            cin>>vec[i];
        }
        return vec;

    }
public : 
    void printLinkedList(ListNode* head){
        ListNode* temp = head;
        while(temp != nullptr){
            cout<<temp->val<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
public : 
    ListNode* secondHalf(ListNode* head){
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast != nullptr && fast->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
public : 
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr){
            return head;
        }
        ListNode* final = new ListNode(head->val);
        ListNode* temp = head->next;

        while(temp != nullptr){
            ListNode* temp1 = new ListNode(temp->val);
            temp1->next = final;
            final = temp1;
            temp = temp->next;

        }
        return final;
        
    }
public:
    bool isPalindrome(ListNode* head) {
        ListNode* temp = head;
        ListNode* rest = secondHalf(head);
        rest = reverseList(rest);
        while(rest != nullptr){
            if(rest->val != temp->val){
                rest = reverseList(rest);
                return false;
            }
            rest = rest->next;
        }
        rest = reverseList(rest);
        return true;

        
    
        
    }
};
int main(){
        Solution mySolution;
        vector<int> arr = mySolution.takeInputArray();
        // mySolution.printArray(arr);
        ListNode* head = new ListNode(arr[0],nullptr);
        ListNode* mover = head;
        for(int i=1;i<arr.size();i++){
            ListNode* temp = new ListNode(arr[i]);
            mover->next = temp;
            mover = mover->next;

        }
        ListNode* first = head;
        ListNode* second = mySolution.secondHalf(first);
        second = mySolution.reverseList(second);
        while(second != nullptr){
            if(first->val != second->val){
                cout<<"This is not a palindrome";
                return 0;
            }
            second = second->next;
            first = first->next;
        }
        cout<<"This is a palindrome";
        return 0;
}