#include<bits/stdc++.h>
using namespace std;
/*2d binary search in tc O(log(m*n))*/
int binaryS(vector<int>&vec, int target, int low, int high){
    if(high < low){
        return -1;
    }
    int mid = (low+high)/2;
    if(vec[mid] > target){
        return binaryS(vec, target, low, mid-1);
    }
    else if(vec[mid] < target){
        return binaryS(vec, target, mid+1, high);
    }
    else{
        return mid;
    }

}

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    int n = matrix[0].size();
    int j = n-1;
    bool mightExist = false;
    for(int i = 0; i < m; i++){
        if(matrix[i][j] >= target){
            mightExist = true;
            j = i;
            break;
        }
    }
    if(mightExist){
        int ans = binaryS(matrix[j], target, 0, n-1);
        if(ans == -1){
            return false;
        }
        return true;
    }
    return false;
        
}

int main(){
    vector<vector<int>>matrix;
    int m, n;
    cin >> m >> n;
    for(int i = 0; i < m; i++){
        vector<int>inside;
        for(int j = 0; j < n; j++){
            int num;
            cin >> num;
            inside.push_back(num);
        }
        matrix.push_back(inside);
    }
    for(auto m : matrix){
        for(auto n : m){
            cout << n << " ";
        }
        cout << endl;
    }
    int target; cin >> target;
    cout << searchMatrix(matrix, target) << endl;
}