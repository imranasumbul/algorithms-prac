#include <bits/stdc++.h>
using namespace std;
/*word search
combinations
letter combinations of a phone number

whenever 'return all possible' keyword us given, subarrays, subsets, think of applying backtracking */

void letterComb(string &given, int index, string str, vector<string> &ans, map<char, string>& mp){
    if(index == given.length()){
        ans.push_back(str);
        return;
    }
    //time complexity of total algo = O(n*(4^n)) n is length of given
    char c = given[index];
    string s = mp[c];
    for(auto ch : s){
        str.push_back(ch);
        letterComb(given, index+1, str, ans, mp);
        str.pop_back();
    }
}
void combinations(vector<int>&vec, int index, int k, vector<int>&ans, vector<vector<int>>&anss){
    if(index == vec.size()){
        if(k == 0){
            anss.push_back(ans);
        }
        
        return;
    }

    ans.push_back(vec[index]);
    combinations(vec, index+1, k-1, ans, anss);
    ans.pop_back();
    combinations(vec, index+1, k, ans, anss);
}


int main(){
    // vector<vector<char>> board = {{'K', 'W', 'E'}, {'I', 'L', 'O'}, {'T', 'P', 'H'}, {'E', 'X', 'K'}};
    // int rows = board.size();
    // int cols = board[0].size();
    // vector<int> vec = {2, 5, 1, 3};
    // vector<vector<int>> anss;
    // vector<int> ans;
    // combinations(vec, 0, 2, ans, anss);
    // for(auto a : anss){
    //     for(auto b : a){
    //         cout << b << " ";
    //     }
    //     cout << endl;
    // }

    map<char, string>mp;
    mp['2']= "abc";
    mp['3']= "def";
    mp['4']= "ghi";
    mp['5']= "jkl";
    mp['6']= "mno";
    mp['7']= "pqrs";
    mp['8']= "tuv";
    mp['9']= "wxyz";

    string a = "2";
    vector<string> ans;
    letterComb(a, 0, "", ans, mp);
    for(auto a : ans){
        cout << a << endl;
    }

}
