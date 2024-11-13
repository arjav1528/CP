#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<char, int>& a, 
        pair<char, int>& b) 
{ 
    return a.second < b.second; 
}
void sortMap(unordered_map<char, int>& M) 
{ 
 
    // Declare vector of pairs 
    vector<pair<char, int> > A; 
 
    // Copy key-value pair from Map 
    // to vector of pairs 
    for (auto& it : M) { 
        A.push_back(it); 
    } 
 
    // Sort using comparator function 
    sort(A.begin(), A.end(), cmp); 
 
    // Print the sorted value 
    // for (auto& it : A) { 
 
    //     cout << it.first << ' '
    //         << it.second << endl; 
    // } 
}

int main(){
    string s = "aabcb";
    int left = 0;
    int right = 0;
    while((left<=right) && (right<s.size())){
        unordered_map<char,int> mpp;
        for(int i=left;i<=right;i++){
            mpp[s[i]]++;
        }
        sortMap(mpp);
        cout<<mpp.begin()->first<<" "<<mpp.end()->second;
        if(left<right){
            right--;
        }
        else{
            left++;
            right = s.size()-1;
        }
    }
        
        
}
