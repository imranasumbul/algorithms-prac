#include<bits/stdc++.h>
using namespace std;
/*quick sort
space complexity - O(n)
time complexity worst case - O(n^2)
best case - O(nlogn)*/

int partition (int arr[], int low, int high);
void quickSort(int arr[], int low, int high);

void quickSort(int arr[], int low, int high){

        //int sizeOfArr = sizeof(arr)/sizeof(arr[0]);
        if(high < low){
            return;
        }
        int partition_index = partition(arr, low, high);
        quickSort(arr, low, partition_index-1);
        quickSort(arr, partition_index+1, high);
        
}

    void swap(int&a, int&b){
        int c = a;
        a = b;
        b = c;
        
        return;
    }
    
  
    int partition (int arr[], int low, int high)
    {
        //
        int elem = arr[high];
        int partIndex = low;
        for(int i = low; i < high; i++){
            if(arr[i] < elem){
                swap(arr[i], arr[partIndex]);
                partIndex++;
            }
        }
        swap(arr[partIndex], arr[high]);
        return partIndex;
        
       // Your code here
    }

    void displayArr(int arr[], int size){
        for(int i = 0; i < size; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
int main(){

    int arr[] = {3, 6, 1};
    int size = sizeof(arr)/sizeof(arr[0]);
    displayArr(arr, size);
    quickSort(arr, 0, size-1);
    displayArr(arr, size);
    
    
    
}