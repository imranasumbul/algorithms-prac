#include<bits/stdc++.h>
using namespace std;
/*stockspan problem*/
void solveStockSpan(vector<int>& ip, vector<int>& ans){
    stack<pair<int, int>> st;
    
    for(auto a : ip){
        int count = 1;
        if(st.empty()){
            st.push({a, count});
        }else{
            while(!st.empty()){
                if(st.top().first <= a){
                    count = count + st.top().second;
                    st.pop();
                    
                }else{
                    
                    break;
                }
            }
            st.push({a, count});
            
        }
        ans.push_back(count);
    }
    
}

int main(){
    vector<int> ip = {200, 120, 30, 55, 67, 89, 890, 230, 100};
    vector<int> ans;
    solveStockSpan(ip, ans);
    for(auto a : ans){
        cout << a << " ";
    }
    cout << endl;
}