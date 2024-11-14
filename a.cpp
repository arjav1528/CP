#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    // public :
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }
    // public:
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};
int main(){
    vector<int> arr = {1,2,3,4,5,6};
    Node* head = new Node(arr[0],nullptr);
    Node* mover = head;
    for(int i=1;i<arr.size();i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
}