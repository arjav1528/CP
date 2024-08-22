#include<iostream>
using namespace std;
void printArray(int arr[], int n){
    
    for(int i=0;i<n;i++){
        if(i==(n-1)){
            cout<<arr[i];
        }
        else{
            cout<<arr[i]<<",";
        }
    }
    cout<<endl;
    
}
void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void selectionSort(int arr[],int n){
    for(int i=0;i<n;i++){
        int min = i;
        for(int j=i;j<n;j++){
            if(arr[j] < arr[min]){
                min = j;
            }
        }
        swap(&arr[i],&arr[min]);
        printArray(arr,10);
    }

}
void bubbleSort(int arr[],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<(n-i);j++){
            if(arr[j] > arr[j+1]){
                swap(&arr[j],&arr[j+1]);
            }
        }
        printArray(arr,10);
    }
}
void insertionSort(int arr[],int n){
    for(int i=0;i<n;i++){
        int j = i;
        while(j>0 && arr[j] < arr[j-1]){
            swap(&arr[j],&arr[j-1]);
            j--;
        }
        printArray(arr,10);
    }
}
int main(){
    int arr[10] = {23,51,12,1,33,97,22,11,64,2};
    int size =10;
    printArray(arr,10);
    // selectionSort(arr,10);
    // bubbleSort(arr,size);
    insertionSort(arr,10);

}