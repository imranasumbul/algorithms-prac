#include<bits/stdc++.h>
using namespace std;
/*reverse a stack --- always try to optimise by using tail recursion
optimal solution = tc-O(n^2) and sc - O(1)*/
stack<int> Ans(stack<int>&St, stack<int>&ans){
    if(St.empty()){
        return ans;
    }
    ans.push(St.top());
    St.pop();
    return Ans(St, ans);
}
    
stack<int> Reverse(stack<int> &St){ //space n
    stack<int>ww;
    return Ans(St, ww);
}

void displayStack(stack<int> ab){
    while(!ab.empty()){
        cout << ab.top() << " ";
        ab.pop();
    }
    cout << endl;
    return;
}

void pushElemAtBottom(stack<int>&st, int element){
    if(st.empty()){
        st.push(element);
        return;
    }
    int top = st.top();
    st.pop();
    pushElemAtBottom(st, element);
    st.push(top);
   
}
void revStack(stack<int> &St){
    if(St.empty()){
        return;
    }
    
    int top = St.top();
    St.pop();
    revStack(St);
    pushElemAtBottom(St, top);
}
int main(){
    stack<int> abc;
    abc.push(1);
    abc.push(2);
    abc.push(3);
    abc.push(4);
    abc.push(5);
    
    displayStack(abc);
    cout << "in btw " << endl;
    revStack(abc);
    displayStack(abc);
}