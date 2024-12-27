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
    void printLinkedList(Node* head){
        Node* temp = head;
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
    int stringToNum(string s,int curr,bool negative){
        // cout<<negative<<"is the bool";
        if(s == ""){
            return curr;
        }
        else if(notInteger(s[0])){
            return curr;
        }
        
        
        else{
            if(negative){
                cout<<"Negative"<<endl;
                long long temp = curr*(-1);
                if(temp<INT_MIN){
                    cout<<temp<<"Limit";
                    return INT_MIN;
                }
                else{
                    curr = curr*10 + (long long)(s[0] - 48);
                    cout<<curr<<endl<<"CURR value";
                    // cout<<curr<<endl;
                    s.erase(s.begin());
                    // cout<<s<<endl;
                    return stringToNum(s,curr,negative);
                }
            }
            else{
                cout<<"POSITIVE ";
                long long temp = curr;
                cout<<temp<<endl;
                // cout<<temp;
                if(temp>INT_MAX){
                    return INT_MAX;
                }
                else{
                    // long long num = s[0] - 48;
                    if(curr*10>=INT_MAX){
                        cout<<"YAYY";
                    }
                    curr = curr*10 + (s[0] - 48);
                    
                    // cout<<curr<<endl;
                    s.erase(s.begin());
                    // cout<<s<<endl;
                    return stringToNum(s,curr,negative);
                }
            }
        }

    }


    bool notInteger(char s){
        if(48<=s && s<=57){
            return false;
        }
        else{
            return true;
        }

    }
    int myAtoi(string s) {
        // bool negative = false;
        s.erase(remove(s.begin(), s.end(), ' '), s.end()); 
        if(notInteger(s[0]) && notInteger(s[1])){
            // cout<<"Hello";
            return 0;
        }
        else{
            if(s[0] == '-'){
                // negative = true;
                s.erase(s.begin());
                return stringToNum(s,0,true);
            }
            else if(s[0] == '+'){
                s.erase(s.begin());
                return stringToNum(s,0,false);
            }
            else{
                return stringToNum(s,0,false);
            }
            
        }
    }
};



int main(){
    Solution mySolution;
    Inputs myInput;
    string s = "21474836460";
    long long temp = mySolution.myAtoi(s);
    cout<<temp;
}

    