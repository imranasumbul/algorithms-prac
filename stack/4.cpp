#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

/*reverse polish notation*/

int evalRPN(vector<string>& tokens) {
    stack<string> st;
    for(int i = 0; i < tokens.size(); i++){
        if(tokens[i] == "*" || tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "/"){
            ll first, second;
            second = stoi(st.top());
            st.pop();
            first = stoi(st.top());
            st.pop();
            if(tokens[i] == "+"){
                ll ans = first + second;
                st.push(to_string(ans));
            }else if(tokens[i] == "/"){
                ll ans = first / second;
                st.push(to_string(ans));
            }else if(tokens[i] == "-"){
                ll ans = first - second;
                st.push(to_string(ans));
            }else{
                ll ans = first * second;
                st.push(to_string(ans));
            }
        }else{
            st.push(tokens[i]);
        }
    }
    int answer = stoi(st.top());
    return answer;
}


int main(){
    vector<string> vec = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    cout << evalRPN(vec) << endl;
}