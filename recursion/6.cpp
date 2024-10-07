#include<bits/stdc++.h>
using namespace std;
/*sub sets and letter case permutation*/

void solve(vector<int>&nums, int index, vector<int>&ans, vector<vector<int>>& anss){
    if(index == nums.size()){
        anss.push_back(ans);
        return;
    }
    ans.push_back(nums[index]);
    solve(nums, index+1, ans, anss);
    ans.pop_back();
    solve(nums, index+1, ans, anss);
}
vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> anss;
    vector<int> ans;
    solve(nums, 0, ans, anss);
    return anss;
}
void solveLetterCase(string&s, vector<string>& anss, string str, int i){
    if(i == s.size()){
        anss.push_back(str);
        return;
    }

    if(s[i] >= 97 && s[i] <= 122){
        str.push_back(s[i]); 
        solveLetterCase(s, anss, str, i+1);
        str.pop_back();
        str.push_back(s[i]-32);
        solveLetterCase(s, anss, str, i+1);
    }else if(s[i] >= 65 && s[i] <= 90){
        str.push_back(s[i]);
        solveLetterCase(s, anss, str, i+1);
        str.pop_back();
        str.push_back(s[i]+32);
        solveLetterCase(s, anss, str, i+1);
    }else{
        str.push_back(s[i]);
        solveLetterCase(s, anss, str, i+1);

    }
}
vector<string> letterCasePermutation(string s) {
    vector<string> anss;
    string str = "";
    solveLetterCase(s, anss, str, 0);
    return anss;
}



int main(){
    vector<int> vec = {1, 2, 3,4};
    vector<vector<int>>anss = subsets(vec);
    for(auto a : anss){
        for(auto b : a){
            cout << b << " ";
        }
        cout << endl;
    }
    cout << "hahahahahahahahhahahahahahahahahahahahahah" << endl;
    string s = "a1b2";
    vector<string> anss2 = letterCasePermutation(s);

    for(auto m : anss2){
        cout << m << endl;
    }

}