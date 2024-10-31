#include<iostream>
#include<bits/stdc++.h>
#include<map>
#include<limits>
using namespace std;
void printArray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
// 2Sum Problem
void q1(){
    int n,k;
    cin>>n>>k;
    int count=0;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        int temp = arr[i];
        int rem = k-temp;
        for(int j=i;j<n;j++){
            if(arr[j]==rem){
                count++;
                cout<<"1";
                return;
            }
        }
    }
    cout<<"0";

}
// Sort array of 0s,1s and 2s{{{Better Method}}}
void q2(){
    int n;
    cin>>n;
    int arr[n];
    int hash[3]={0};
    for(int i=0;i<n;i++){
        cin>>arr[i];
        hash[arr[i]]++;
    }
   for(int i=0;i<hash[0];i++){
      arr[i] = 0;
   }
   for(int i=hash[0];i<(hash[0]+hash[1]);i++){
      arr[i] = 1;
   }
   for(int i=(hash[0]+hash[1]);i<(hash[0]+hash[1]+hash[2]);i++){
      arr[i] = 2;
   }
   printArray(arr,n);
}
// Sort array of 0s,1s and 2s{{{Optimal Method}}} 
//Deutch National Flag Algorithm
void q2optimal(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int low = 0;
    int mid = 0;
    int high = n-1;
    while(mid<=high){
        if(arr[mid]==0){
            swap(arr[low++],arr[mid++]);
        }
        else if(arr[mid] == 1){
            mid++;
        }
        else{
            swap(arr[mid],arr[high--]);

        }
    
    }
    printArray(arr,n);

}
//Find the element that occurs at majority
void q3(){
    int n = 1;
    cin>>n;
    int arr[n];
    map<int,int> map1;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        map1[arr[i]]++;
    }
    for(auto it = map1.begin();it!=map1.end();it++){
        if(it->second>n/2){
            cout<<(it->first)<<endl;
            return;
        }
    }
    
    

}
//Kadane's Algorithm to find the maximum sum from a subarray
void q4(){
    int n;
    cin>>n;
    int arr[n];
    int sum = 0;
    int maxsum = INT_MIN;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum+=arr[i];
        maxsum = sum>maxsum ? sum : maxsum;
        sum = sum<=0 ? 0 : sum;
    }
    cout<<maxsum<<endl;
}
//Print that subarray
void q5(){
    int n;
    cin>>n;
    int arr[n];
    int sum = 0;
    int maxsum = 0;
    int start = 0;
    int length = 0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(sum==0){
            start=i;
            length=0;
        }
        sum+=arr[i];
        length++;
        if(sum>maxsum){
            maxsum = sum;
            
        }
        if(sum<0){
            sum = 0;
            length = 0;
        }    
    }
    for(int i=start;i<(start + length);i++){
        cout<<arr[i]<<" ";
    }
    
}
//Stock market buy and sell question
void q6(){
    int n;
    cin>>n;
    int arr[n];
    int minindex = 0;
    int maxindex = 0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(arr[i]<=arr[minindex]){
            minindex = i;
        }
        if(arr[i]>=arr[maxindex] && maxindex>=minindex && maxindex<n){
            maxindex = i;
        }
    }
    cout<<(maxindex-minindex)<<endl;

}
//Rearragne the elemtnets of an array with alteranted positive and negative
void q7(){
    int n;
    cin>>n;
    vector<int> input;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        input.push_back(x);
    }
    vector<int> final(n,0);
    int pos = 0;
    int neg = 1;
    for(int i=0;i<n;i++){
        if(input[i]>0){
            final[pos] = input[i];
            pos+=2;
        }
        else{
            final[neg] = input[i];
            neg+=2;
        }
    }
    for(int i=0;i<n;i++){
        cout<<final[i]<<" ";
    }
}
//Next Permutation of an Array
void q8(){
    int n;
    cin>>n;
    vector<int> arr;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    int index = -1;
    for(int i=(n-2);i>=0;i--){
        if(arr[i]<arr[i+1]){
            index = i;
            break;
        }
    }
    if(index==-1){
        reverse(arr.begin(),arr.end());
    }
    else{
        for(int i=(n-1);i>index;i--){
            if(arr[i] > arr[index]){
                swap(arr[i],arr[index]);
                break;
            }
        }
        reverse(arr.begin() + index + 1,arr.end());
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
void q9(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> final;
    int mid = -1;
    while(mid<(n-1)){
        int maxel = -1;
        int maxi = 0;
        for(int i=(mid+1);i<n;i++){
            if(arr[i]>maxel){
                maxel = arr[i];
                maxi = i;
            }    
        }
        final.push_back(maxel);
        mid = maxi;
    }
    for(int i=0;i<final.size();i++){
        cout<<final[i]<<" ";
    }
    // cout<<maxindex;


}
void q10(){
    int n;
    cin>>n;
    vector<int> arr;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    sort(arr.begin(),arr.end());
    // for(int i=0;i<n;i++){
    //     cout<<arr[i]<<" ";
    // }
    int count = 1;
    int max_count = 0;
    for(int i=0;i<(n-1);i++){
        if((arr[i+1] - arr[i]) == 1){
            if(count==0){
                count+=2;
            }
            else{
                count++;
            }
        }
        else{
            count=0;
        }
        if(count>max_count){
            max_count = count;
        }
    }
    cout<<max_count;

}
int subarraySum(vector<int>& arr, int k) {
        int n=arr.size();
        int start = 0;
        int current = 0;
        int sum = arr[0];
        int count = 0;
        while(current < n){
            if(sum<k){
                current++;
                if(current<n){
                    sum+=arr[current];
                }
                
            }
            else if(sum>k){
                sum-=arr[start];
                start++;
            }
            else{
                count++;
                current++;
                if(current<n){
                    sum+=arr[current];
                }
            }
        }
        return count;
}



int main(){
    // q1();
    // q2();
    // q2optimal();
    // q3();
    // q4();
    // q5();
    // q6();
    // q7();
    // q8();
    // q9();
    // q10();
    vector<int> final = {1,2,3,-3,1,1,1,4,2,-3};
    int ans = subarraySum(final,3);
    cout<<ans;

}