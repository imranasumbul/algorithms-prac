#include<bits/stdc++.h>
using namespace std;
/*Max sum of n sized subarray
first negative integer in a window of size k
subarray + max/min + bruteForceTC(O(n^2))(in the loop form of i and j)
*/
vector<int> firstNegativeIntInAwindowOfSizeK(vector<int> &ans, int arr[], int size, int k){
    
    queue<int> q;
    int i = 0, j = 0;
    while(j < size){
        if(arr[j] < 0){
            q.push(arr[j]);
        }
        if(j-i+1 == k){
            if(q.empty()){
                ans.push_back(0);
            }else{
                ans.push_back(q.front());
            }
            if(arr[i] < 0){
                q.pop();
            }
            i++;
        }
        j++;
    }
    return ans;
}

int maxSumOfNsizedSubarray(int arr[], int size, int n){
    
    int sum1 = 0;
    
    if(size<=n){
        int ans = 0;
        for(int i = 0; i < size; i++){
            ans += arr[i];
        }
        return ans;
    }
    for(int i = 0; i < n; i++){
        sum1 += arr[i];
    }
    int ans = sum1;
    for(int i = n; i < size; i++){
        
        int sum = sum1 - arr[i-n] + arr[i];
        cout << sum1  << " " << sum  <<" " << ans << endl;
        ans = max(sum, ans);
        sum1 = sum;
    }
    return ans;

}
int main(){
    int arr[] = {3, 5, 2, 3, 5};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout << maxSumOfNsizedSubarray(arr, size, 3) << endl;
    cout << maxSumOfNsizedSubarray(arr, size, 4) << endl;

    // cout << maxSumOfNsizedSubarray(arr, size, 4) << endl;
    // cout << maxSumOfNsizedSubarray(arr, size, 5) << endl;
    // cout << maxSumOfNsizedSubarray(arr, size, 6) << endl;
   
}