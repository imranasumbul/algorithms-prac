#include<bits/stdc++.h>
using namespace std;
/*merge sort O(nlogn)*/
void displayVec(vector<int>&v){
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
}
void merge(int arr[], int l, int m, int r) {
        int n1 = m - l + 1;
        int n2 = r - m;
        // Create temporary arrays to store the two halves
        int L[n1], R[n2];
        int k = l;
        // Copy data to temporary arrays L[] and R[]
        for (int i = 0; i < n1; i++)
            L[i] = arr[k++];
        for (int j = 0; j < n2; j++)
            R[j] = arr[k++];
        
        int i = 0; // Initial index of first subarray
        int j = 0; // Initial index of second subarray
        k = l; // Initial index of merged subarray
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }
        // Copy the remaining elements of L[], if there are any
        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }

        // Copy the remaining elements of R[], if there are any
        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }
    }
    
   
    void mergeSort(int arr[], int l, int r) {
        
        if(l >= r) {
            return;
        }
        
        int mid = l + (r-l)/2;
        
        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, r);
        
        merge(arr, l, mid ,r);
        
    }

void displayArr(int arr[], int size){
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main(){

    int arr[] = {4, 2, 7, 5, 1};
    int size = sizeof(arr)/sizeof(arr[0]);
    displayArr(arr, size);
    mergeSort(arr, 0, size-1);
    displayArr(arr, size);

}