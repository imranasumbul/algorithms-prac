#include<bits/stdc++.h>
using namespace std;

int ans = INT_MIN;
void solve(int arr[], int target, int low, int high){ // for lower bound (a >= target)
    if(low > high){
        return ;
    }
    int mid = (low+high)/2;
    if(arr[mid] < target){
       return solve(arr, target, mid+1, high);
    }
    if(arr[mid] >= target){
        ans = arr[mid];
        return solve(arr, target, low, mid-1);
    }
}

int main(){

    int arr[] = {2, 5, 8, 9};
    int size = sizeof(arr)/sizeof(arr[0]);
    int target = 9;
    solve(arr, target, 0, size-1);
    cout << ans << endl;

}