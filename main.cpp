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
class Inputs{
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
    ListNode* convertArrayToLL(vector<int> &arr){
        ListNode* head = new ListNode(arr[0]);
        ListNode* ref = head;
        for(int i=1;i<arr.size();i++){
            ListNode* temp = new ListNode(arr[i]);
            head->next = temp;
            head = temp;
        }
        return ref;
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
    
};
class Solution {
public :
    
    bool canAliceWin(int n){
        int x = 10;
        bool aliceWin = 0;
        while(n>0){
            if(n>=x){
                n = n-x;
                x--;
                aliceWin = !aliceWin;
            }
            else{
                return aliceWin;
            }           
        }
        return aliceWin;
    }
public:
    long long shiftDistance(string s, string t, vector<int>& nextCost, vector<int>& previousCost) {
        int i = 0;
        int shiftleftcost = 0;
        int shiftrightcost = 0;
        long long totalCost = 0;
        while(i<s.length()){
            if(s[i]<t[i]){
                if(s[i]== 'a'){

                }
                else{
                    shiftleftcost += previousCost[s[i]-97];
                }
                if(s[i]=='z'){

                }
                else{
                    shiftrightcost += nextCost[s[i]-97];
                }  
            }
            else if(s[i]>t[i]){
                
                
            }
            else{
                i++;
            }
        }
        return totalCost;
        
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
        ListNode* first = head;
        ListNode* second = secondHalf(first);
        second = reverseList(second);
        while(second != nullptr){
            if(first->val != second->val){
                return false;
            }
            second = second->next;
            first = first->next;
        }
        return true;    
    }
public : 
    ListNode* oddEvenList(ListNode* head) {
        if(head->next == nullptr || head->next->next == nullptr){
            return head;
        }
        ListNode* ref = head;
        ListNode* odd = new ListNode(ref->val);
        ListNode* even = new ListNode(ref->next->val);
        ListNode* oddOrigin = odd;
        ListNode* evenOrigin = even;
        while(ref->next->next != nullptr && ref->next != nullptr){
            ListNode* oddn = new ListNode(ref->val);
            ListNode* evenn = new ListNode(ref->next->val);
            odd->next = oddn;
            even->next = evenn;
            ref = ref->next->next;
        }
        odd->next = evenOrigin;
        return oddOrigin;
    }
    
};
int main(){
    Solution mySolution;
    Inputs myInput;
    vector<int> arr = {5};
    vector<int> arr2 = {5};
    ListNode* l1 = myInput.convertArrayToLL(arr);
    ListNode* l2 = myInput.convertArrayToLL(arr2);
    ListNode* temp1 = (l1);
    ListNode* temp2 = (l2);
    ListNode* final = temp1;
    int carry = 0;
    while(temp1 != nullptr && temp2 != nullptr){
        temp1->val += (temp2->val) + carry;
        carry = (temp1->val)/10;
        temp1->val %= 10;
        if(temp1->next == nullptr && temp2->next == nullptr && carry!=0){
            ListNode* h = new ListNode(carry%10);
            carry = carry/10;
            temp1->next = h;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    if(temp1!= nullptr){
        while(temp1 != nullptr){
            temp1->val += carry;
            carry = (temp1->val)/10;
            temp1->val %= 10;
            
            if((temp1->next == nullptr) && (carry != 0)){
                ListNode* h = new ListNode((carry%10));
                carry = carry/10;
                temp1->next = h;
            }
            temp1 = temp1->next;
        }
        
    }
    myInput.printLinkedList(final);

  
}