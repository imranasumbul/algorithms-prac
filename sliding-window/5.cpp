#include<bits/stdc++.h>
using namespace std;
/*Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit
review it*/

int solve(vector<int> & vec, int &limit){
    int i = 0, j = 0;
    int maxm = INT_MIN;
    int minm = INT_MAX;
    int ans = 0;
    while(j < vec.size()){
        maxm = max(maxm, vec[j]);
        minm = min(minm, vec[j]);
        if(maxm - minm > limit){
            int temp = j - i;
            ans = max(temp, ans);
            while(maxm - minm > limit){
                if(vec[i] == maxm){
                    maxm = INT_MIN;
                }else if(vec[i] == minm){
                    minm = INT_MAX;
                }
                maxm = max(maxm, vec[i]);
                minm = min(minm, vec[i]);
                i++;
            }
           
        }
        if(j == vec.size()-1 && maxm - minm <= limit){
            ans = max(ans, j-i+1);
        }
        j++;
    }
    cout << i << vec[i] << " " << j << vec[j] << endl;
    cout << vec.size() << endl;
    return ans;
}
int main(){
    vector<int> nums = {2,2,2,4,4,2,5,5,5,5,5,2};
    int limit = 2;
    cout << solve(nums, limit) << endl;

}