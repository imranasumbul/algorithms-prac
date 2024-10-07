#include<bits/stdc++.h>
using namespace std;
/*
simplify path 
remove stars
*/
string removeStars(string s) {

    string ans = "";
    for(auto ch : s){
        if(ans.length() == 0){
            ans.push_back(ch);
        }
        else{
            if(ch == '*'){
                ans.pop_back();
                continue;
            }else{
                ans.push_back(ch);
            }
        }
    }
    
    return ans;
}

string simplifyPath(string path){
    string str = path;
    stringstream ss(str);
    string token = "";
    stack<string> st;
    while(getline(ss, token , '/')){
        if(token != "" && token != "."){
            if(token == ".." && !st.empty()){
                st.pop();
            }else if(token == ".." && st.empty()){
                continue;
            }
            else{
                st.push(token);
            }
        }
    };
    string ans = "";
    if(st.empty()){
        ans = "/";
    }
    else{
        while(!st.empty()){
            ans = "/" + st.top() + ans;
            st.pop();
        }
    }
    return ans;
}
void showStack(stack<string> st){
    while(!st.empty()){
        cout << st.top() << endl;
        st.pop();
    }
}
int main(){
    
    string s = "dft***ss*rt*ss";
    cout << removeStars(s) << endl;
}