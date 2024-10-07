#include<bits/stdc++.h>
using namespace std;
/*Minimum Swaps to Group All 1's Together II 
https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii/
in case of subarray, we can always use the array twice*/

int solve(vector<int>& vec, int num){
    int i = 0, j = 0;
    int ans = 0, temp = 0;
    int jval = 0;
    int x = vec.size() + num - 1;
    while(x > 0){
        if(vec[j] == 1){
            temp++;
        }
        if(jval-i+1 == num){
            
            ans = max(ans, temp);
            if(vec[i] == 1){
                temp--;
                
            }
            i++;
            
        }
        j++;
        jval++;
        if(j == vec.size()){
            j = 0;
        }
        
        x--;
    }
    
    return num - ans;
}
int main(){

    vector<int> nums = {1,1,0,0,1};
    int numofOne = 0;
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] == 1){
            numofOne++;
        }
    }

    cout << solve(nums, numofOne) << endl;
}