#include<bits/stdc++.h>
using namespace std;
/*Longest Subarray of 1's After Deleting One Element | Multiple Approaches | GOOGLE | Leetcode-1493*/
int bruteForceApproach(int arr[], int size){
    int ans = INT_MIN;
    for(int i = 0; i < size; i++){
        int zeroC = 0;
        for(int j = i; j < size;j++){
            if(arr[j] == 0){
                zeroC++;
            }
            if(zeroC > 1){
                ans = max(ans, j-i);
                break;
            }
            if(j == size-1 && arr[j] == 1){
                ans = max(ans, j-i);
            }

        }
    }
    return ans;
}
int solve(int arr[], int size){
    int i = 0, j = 0;
    int zeroCount = 0;
    int ans = INT_MIN;
    while(j < size){
        if(arr[j] == 0){
            zeroCount++;
        }
        if(zeroCount > 1){
            while(arr[i] != 0){
                i++;
            }
            zeroCount--;
            i++;
        }
        ans = max(ans, (j-i+1));
        j++;
    }
    return ans-1;
}
int main(){
    int arr[] = {0, 1, 1, 0, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << solve(arr, n) << endl;
    cout << bruteForceApproach(arr, n) << endl;

}