#include<bits/stdc++.h>
using namespace std;
/*peak index in a mountain array*/

int peakIndex(vector<int>&vec, int low, int high){
    if(low == high){
        return low;
    }
    int mid = (low+high)/2;
    if(vec[mid] > vec[mid+1]){
        return peakIndex(vec, low, mid);
    }else{ 
        return peakIndex(vec, mid+1, high);
    }
    
}
int main(){
    vector<int> abc = {1, 2, 3, 4, 5, 6};
    cout << peakIndex(abc, 0, abc.size()-1) << endl;
    
}