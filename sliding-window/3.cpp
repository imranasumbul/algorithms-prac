#include<bits/stdc++.h>
using namespace std;

/*maximum consecutive ones in an array (array has only 0's and 1's)*/

int bruteForce(int arr[], int size, int k){
    int ans = INT_MIN;
    int temp = k;
    for(int i = 0; i < size; i++){
        k = temp;
        for(int j = i; j < size; j++){
            if(arr[j] == 0){
                k--;
            }
            if(k == 0){
                ans = max(ans, (j-i+1));
            }
            if(j == size-1 && k > 0){
                ans = max(ans, (j-i+1));
            }
        }
    }
    return ans;
}

int solve(int arr[], int size, int k){
    int temp = k;
    int ans = INT_MIN;
    int i = 0, j = 0;
    while(j < size){
        if(arr[j] == 0){
            temp--;
        }
        if(temp < 0){
            ans = max(ans, (j-i));
            while(arr[i] != 0){
                i++;
            }
            i++;
            temp++;
        }
        if(j == size-1 && temp >= 0){
            ans = max(ans, (j-i+1));
        }
        j++;
    }
    return ans;
}

int main(){
    int arr[] = {1, 0, 0, 1, 0, 1, 1, 1, 1, 0, 0, 0, 1, 0};
    int size = sizeof(arr)/sizeof(arr[0]);
    int k = 4;
    cout << bruteForce(arr, size, k) << endl;
    cout << solve(arr, size, k) << endl;

}