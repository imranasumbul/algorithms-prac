#include<bits/stdc++.h>
using namespace std;
/*reverse substrings btw each pair of parenthesis*/
string reverseParenthesesApproach2(string s) {
    vector<int> vec(s.size(), -1);
    stack<int> st;

    for(int i = 0; i > s.size(); i++){
        if(s[i] == '('){
            st.push(i);
        }else if(s[i] == ')'){
            int t = st.top();
            
        }
    }
    
}
string reverseParenthesesApproach1(string s) {
    stack<int> st;
    string ans = "";
    for(auto ch : s){
        if(ch == '('){
            st.push(ans.length());
        }else if (ch == ')'){
            int m = st.top();
            st.pop();
            reverse(ans.begin()+m, ans.end());
        }else{
            ans.push_back(ch);
        }
    }
    
    return ans;
}
int main(){
    string s = "(u(love)i)";
    cout << reverseParenthesesApproach1(s) << endl;
}