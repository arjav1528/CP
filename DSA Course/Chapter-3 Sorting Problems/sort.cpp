#include<iostream>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;



//Largest Element in An Array
void q1(){
    int n;
    cin>>n;
    int max = 0;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        max = max > x ? max : x;
    }
    cout<<max<<endl;

}
//Second Larger and Second Smallest element in an array without sorting
void q2(){
    int n;
    int min,max;
    max = 0;    
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        min = (min<arr[i] ? min : arr[i]);
        max = (max>arr[i] ? max : arr[i]);
    }
    int smax,smin;
    smax = arr[0];
    smin = arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]>smax && arr[i] < max){
            smax = arr[i];
        }
        if(arr[i] < smin  && arr[i] > min){
            smin = arr[i];
        }

    }
    cout<<smax<<" "<<smin;
}
//Check if array is sorted
void q3(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<(n-1);i++){
        if(arr[i] <= arr[i+1]){
            continue;
        }
        else{
            cout<<"0"<<endl;
            return;
        }
    }
    cout<<"1"<<endl;
}
// Remove duplicates from the array
void q4(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> temp;
    temp.push_back(arr[0]);
    for(int i=1;i<n;i++){
        if(arr[i] != temp[(temp.size() - 1)]){
            temp.push_back(arr[i]);
        }
        else{
            continue;
        }
    
    }
    cout<<temp.size()<<endl;
}
//Left Rotate the array by one place
void q5(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int temp = arr[0];
    for(int i=1;i<n;i++){
        arr[i-1] = arr[i];
    }
    arr[n-1] = temp;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
//Right rotate the array by k places
void q6(){
    int n,k;
    k = k%n; // This is because rotation of array to its full size is array itself
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int temp[n-k];
    for(int i=0;i<(n-k);i++){
        temp[i] = arr[i];
    }
    int x = 0;
    for(int i =(n-k);i<n;i++){
        arr[x++] = arr[i];
    }
    for(int i=0;i<(n-k);i++){
        arr[x++] = temp[i];
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

}
//Move all the zeroes to the end
void q7(){
    int n;
    cin>>n;
    int arr[n];
    int count = 0;
    vector<int> temp;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(arr[i] == 0){
            count++;
        }
        else{
            temp.push_back(arr[i]);
        }
    }
    for(int i=0;i<count;i++){
        temp.push_back(0);
    }
    for(int i=0;i<n;i++){
        cout<<temp[i]<<" ";
    }
}
//Linear Search
void q8(){
    int n,k;
    cin>>n>>k;
    int arr[n];
    int index = 0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(arr[i] == k){
            index = i;
        }
    }
    cout<<index;

}
//Union of Two arrays   Learn about Set Data Structure
void q9(){
    int a,b;
    cin>>a>>b;
    int arr1[a],arr2[b];
    for(int i=0;i<a;i++){
        cin>>arr1[i];
    }
    for(int i=0;i<b;i++){
        cin>>arr2[i];
    }
    set<int> s1;
    for(int i=0;i<a;i++){
        s1.insert(arr1[i]);
    }
    for(int i=0;i<b;i++){
        s1.insert(arr2[i]);
    }
    for(auto it : s1){
        cout<<it<<" ";
    }

}
//Find the missing number 
void q10(){
    int N;
    cin>>N;
    int arr[N] = {0};
    for(int i=0;i<N;i++){
        cin>>arr[i];

    }
    for(int i=0;i<N;i++){
        if(arr[i] == 0){
            cout<<i+1;
        }
    }

}
//Count Maximum consecutive one's in the array
void q11(){
    int n;
    cin>>n;
    int arr[n];
    int max = 0;
    int check = 0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(arr[i]==1){
            check++;
        }
        else{
            check = 0;
        }
        max = max>=check ? max : check;
    }
    cout<<max;
}
//Count The number which appears only once
void q12(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int count[n+1] = {0};
    for(int i=0;i<n;i++){
        count[arr[i]]++;
    }
    for(int i=0;i<n;i++){
        if(count[arr[i]] == 1){
            cout<<arr[i];
        }
    }


}
//Find the longest sub array with sum k which has positives
void q13(){
    int n;
    long long k;
    cin>>n;
    cin>>k;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int left = 0;
    int right = 0;
    long long sum = arr[0];
    int maxLen = 0;
    while(right<n){
        while(left<=right && sum>k){
            sum-=arr[left];
            left++;
        }
        if(sum==k){
            maxLen = max(maxLen,right-left+1);
        }
        right++;
        if(right<n){
            sum+=arr[right];
        }
    }
    cout<<maxLen<<endl;
    
}
//Find the longest sub array with sum k which has positives as well as negatives
void q14(){
    int n;
    long long k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    long long sum = 0;
    int maxlen = 0;
    map<long long,long long> preSumMap;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(sum==k){
            maxlen = i+1;
        }
        int rem = sum-k;
        
        if(preSumMap.find(rem)!=preSumMap.end()){
            int len = i-preSumMap[rem];
            maxlen = max(maxlen,len);
        }
        if(preSumMap.find(sum) == preSumMap.end()){
            preSumMap[sum] = i;
        }
    }
    cout<<maxlen;
}











int main(){
    // q1();
    // q2();
    // q3();
    // q4();
    // q5();
    // q6();
    // q7();
    // q8();
    // q9();
    // q10();
    // q11();
    // q12();
    q13();
    // q14();
    
}