#include<bits/stdc++.h>
using namespace std;
 typedef long long int ll;
/*tower of hanoi
tc-O(2^n), recursion stack space complexity - O(n), auxillary stack space complexity - O(1)*/

void TOH(int n, stack<int>&from, stack<int>&mid, stack<int>&to){
    if(n==1){
        to.push(from.top());
        from.pop();
        //cout<< "moved 1 rod from " << from << " to " << to << endl;
        return;
    }

    TOH(n-1, from, to, mid);
    to.push(from.top());
    from.pop();
    TOH(n-1, mid, from, to);
}
void displayStack(stack<int> ab){
    while(!ab.empty()){
        cout << ab.top() << " ";
        ab.pop();
    }
    cout << endl;
    return;
}
//gfg code below
void ans(int n, int from, int to, int aux, long long &count){
        count++;
        if(n == 1){
            cout << "move disk " << n << " from rod " << from << " to rod " << to << endl;
            return; 
        }
        
        ans(n-1, from, aux, to, count);
        cout << "move disk " << n << " from rod " << from << " to rod " << to << endl;
        ans(n-1, aux, to, from, count);
    }
    
    long long toh(int n, int from, int to, int aux) {
        long long int count = 0;
        
        ans(n, from, to, aux, count);
        cout << count << endl;
        return count;
        
        // Your code here
    }
//gfg code ends
int main(){
    // stack<int> from;
    // from.push(5);
    // from.push(4);
    // from.push(3);
    // from.push(2);
    // from.push(1);
    // stack<int> mid, to;
    // cout << "from ";
    // displayStack(from);
    // cout << "mid ";
    // displayStack(mid);
    // cout << "to ";
    // displayStack(to);
    // TOH(5, from, mid, to);
    // cout << "from ";
    // displayStack(from);
    // cout << "mid ";
    // displayStack(mid);
    // cout << "to ";
    // displayStack(to);
    
    toh(4, 1, 3, 2);
}