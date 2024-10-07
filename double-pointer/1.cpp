#include<bits/stdc++.h>
using namespace std;
/*remove duplicate elements from sorted array*/

int removeDuplicates(vector<int>& nums) {
    int i = 0, j = 1;
    while(j != nums.size()){
        if(nums[j] != nums[i]){
            i++;
            nums[i] = nums[j];
            j++;
        }else{
            j++;
        }
    }
    return i+1;

}

void displayvec(vector<int>& v){
    for(auto a : v){
        cout << a << " ";
    }
    cout << endl;
}
int main(){
    vector<int> nums = {1,1,2};
    displayvec(nums);
    cout << removeDuplicates(nums) << endl;
    displayvec(nums);
}