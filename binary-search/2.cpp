/*find first and last position in sorted array*/

#include<bits/stdc++.h>
using namespace std;
int right(vector<int>& nums, int target, int position);
int left(vector<int>& nums, int target, int position);
int find(vector<int>& nums, int target, int low, int high){
        
    if(low > high){
        return -1;
    }
    int mid = (low+high)/2;
    if(nums[mid] < target){
        return find(nums, target, mid+1, high);
    }else if(nums[mid] > target){
        return find(nums, target, low, mid-1);
    }else{
        return mid;
    }
}
int left(vector<int>& nums, int target, int position){
    int pos = find(nums, target, 0, position-1);
    if(pos == -1){
        return position;
    }else{
        return left(nums, target, pos);
    }
}
int right(vector<int>& nums, int target, int position){
    int pos = find(nums, target, position+1, nums.size()-1);
    if(pos == -1){
        return position;
    }else{
        return right(nums, target, pos);
    }
}
vector<int> searchRange(vector<int>& nums, int target) {
    vector<int>ans(2, -1);
    int present = find(nums, target, 0, nums.size()-1);
    if(present == -1){
        return ans;
    }else{
        ans[0] = left(nums, target, present);
        ans[1] = right(nums, target, present);
        return ans;
    }


}

int main(){
    int n;
    cin >> n;
    vector<int>vec;
    while(n > 0){
        int num;
        cin >> num;
        vec.push_back(num);
        n--;
    }
    int target;
    cin >> target;
    vector<int>ans = searchRange(vec, target);
    for(auto a : ans){
        cout << a << " ";
    }
    cout << endl;
}