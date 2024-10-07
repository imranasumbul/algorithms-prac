#include<bits/stdc++.h>
using namespace std;
/*brackets question  -- generate parenthesis */

void solve( vector<string>&anss, string &str, int count, int& size){
    if(str.length() == size){
        if(count == 0){
            anss.push_back(str);
        }
        return;
    }
    if(count == 0){
        str.push_back('(');
        
        solve(anss, str, count+1, size);
    }else{
        str.push_back('(');
        
        solve(anss, str, count+1, size);
        str.pop_back();
        
        str.push_back(')');
        
        solve(anss, str, count-1, size);
        str.pop_back();
        
    }
}
vector<string> generateParenthesis(int n) {
    vector<string> anss;
    int count = 0;
    string str = "";
    int x = 2*n;
    solve(anss, str, count, x);
    return anss;
}

int main(){
    int n;
    cin >> n;
    vector<string> ans = generateParenthesis(n);
    for(auto a : ans){
        cout << a << endl;
    }
}