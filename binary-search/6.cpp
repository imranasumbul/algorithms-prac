#include<bits/stdc++.h>
using namespace std;
/*merge sort by me*/

void divide(vector<int>& vec, int low, int high);
void merge(vector<int>&left, vector<int>&right, vector<int> &original, int &index);
void divide(vector<int>& vec, int low, int high){

    if(low == high){
        return;
    }
    int mid = (low+high)/2;

    divide(vec, low, mid);
    divide(vec, mid+1, high);
    vector<int>left, right;
    for(int i = low; i <= mid; i++){
        left.push_back(vec[i]);
    }
    for(int i = mid+1; i <= high; i++){
        right.push_back(vec[i]);
    }

    merge( left, right, vec, low);

}

void merge(vector<int>&left, vector<int>&right, vector<int> &original, int &index){
    int k = index;
    int i = 0, j = 0;
    while(i < left.size() && j < right.size()){
        if(left[i] <= right[j]){
            original[k] = left[i];
            i++;
        }else{
            original[k] = right[j];
            j++;
        }
    k++;
    }
    while(i < left.size()){
        original[k] = left[i];
        i++;
        k++;
    }
    while(j < right.size()){
        original[k] = right[j];
        j++;
        k++;
    }
}
void displayVec(vector<int>&v){
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
}
int main(){
    vector<int> v = {6, 1, 3, 2, 1, 5, 11, 6, 9, 7, 9};
    displayVec(v);
    divide(v, 0, v.size()-1);
    displayVec(v);

}