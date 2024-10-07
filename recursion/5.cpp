#include<bits/stdc++.h>
using namespace std;
/*power sets*/

void solve(string &str, vector<string> &anss, string s, int i){
    if(i == str.length()){
        anss.push_back(s);
        return;
    }
    s.push_back(str[i]);

    solve(str, anss, s, i+1);
    s.pop_back();
    solve(str, anss, s, i+1);
}
void take(){
    
}

int main(){
    string str = "abc";
    vector<string> anss;
    string s = "";
    solve(str, anss, s, 0);
    for(auto str: anss){
        cout << str << endl;
    }

}