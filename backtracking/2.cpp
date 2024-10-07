#include <bits/stdc++.h>
using namespace std;
/*non decreasing subsequences
beautiful subsets
cookie distribution - https://leetcode.com/problems/fair-distribution-of-cookies/description/*/

bool ifNumsPresent(vector<int> &vec, int  a, int b){
    for(auto v : vec){
        if(v == a || v == b){
            return true;
        }
    }
    return false;
}
void beautifulSubsets(int & k, int &count, vector<int> &given, int index, vector<vector<int>> & anss, vector<int>& ans){
    if(index == given.size()){
        if(ans.size() > 0){
            anss.push_back(ans);
            count++;
        }
        
        return;
    }

    int num = given[index];
    int small = num-k, big = num+k;
    if(ans.empty() || ifNumsPresent(ans, small, big) == false){
        ans.push_back(num);
        beautifulSubsets(k, count, given, index+1, anss, ans);
        ans.pop_back();
        beautifulSubsets(k, count, given, index+1, anss, ans);
    }else{
        beautifulSubsets(k, count, given, index+1, anss, ans);
    }

}

void cookieDistribution(int k, int index, vector<int> & cookies, vector<int> & children, int &ans){
    
    if(index == cookies.size()){
        int unfairness = *max_element(children.begin(), children.end());
        ans = min(ans, unfairness);
        return;
    }
    for(int i = 0; i < k; i++){
        children[i] = children[i] + cookies[index];
        cookieDistribution(k, index+1, cookies, children, ans);
        children[i] = children[i] - cookies[index];
    }
}
int distributeCookies(vector<int>& cookies, int k) {
    int ans = INT_MAX;
    vector<int> kids(k, 0);
    cookieDistribution(k, 0, cookies, kids, ans);
    return ans;

}
void nonDecSubsequences(vector<vector<int>>&finalAns, vector<int> & given, set<vector<int>> & anss, vector<int> ans, int index){
    if(index == given.size()){
        
        if(anss.find(ans) == anss.end() && ans.size() >= 2){
            finalAns.push_back(ans);
            anss.insert(ans);
        }
        return;
    }

    if((ans.size() == 0 || ans.back() <= given[index])){
        ans.push_back(given[index]);
        nonDecSubsequences(finalAns, given, anss, ans, index+1);
        ans.pop_back();
        nonDecSubsequences( finalAns, given, anss, ans, index+1);
    }
    else{
        nonDecSubsequences( finalAns, given, anss, ans, index+1);
    }
    
    
}
int main(){
    // vector<int> vec;
    
    // vector<vector<int>> ansss;
    // vector<int> ans;
    // int ct = 0, k = 1;
    // beautifulSubsets(k, ct, vec, 0, ansss, ans);
    // for(auto a : ansss){
    //     for(auto b : a){
    //         cout << b << " ";
    //     }
    //     cout << endl;
    // }
    // cout << ct << endl;

    vector<int> cookies = {8,15,10,20,8};
    int k = 2;
    cout << distributeCookies(cookies, k) << endl;


}