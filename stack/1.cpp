#include<bits/stdc++.h>
using namespace std;

/*remove repeated adjacent characters*/
void ans(string& s, stack<char>& st){
    if(st.empty()){
        return;
    }
    int top = st.top();
    st.pop();
    ans(s, st);
    s.push_back(top);

}
string removeDuplicates(string s) {
    stack<char> st;
    string str = "";
    for(auto ch : s){
        if(st.empty()){
            st.push(ch);
        }else{
            if(st.top() == ch){
                st.pop();
            }else{
                st.push(ch);
            }
        }
    }
    ans(str, st);
    return str;
}

int main(){
    string s;
    cin >> s;
    string ans = removeDuplicates(s);
    cout << ans << endl;
}