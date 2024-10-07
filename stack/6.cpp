#include<bits/stdc++.h>
using namespace std;
/*asteroid collision
validate stack sequences*/
vector<int> asteroidCollision(vector<int>& asteroids) {
    vector<int> anss;
    bool temp = true;
    for(int i = 0; i < asteroids.size(); i++){
        temp = true;
        if(anss.size() == 0){
            anss.push_back(asteroids[i]);
        }else{
            while(anss.size() > 0 && anss[anss.size()-1]* asteroids[i] < 0){
                if(abs(asteroids[i]) > abs(anss[anss.size()-1])){
                    anss.pop_back();
                }else if(abs(asteroids[i]) == abs(anss[anss.size()-1])){
                    anss.pop_back();
                    temp = false;
                    break;
                }else{
                    break;
                } 
            }
            
            if(anss[anss.size()-1]* asteroids[i] > 0 || (anss.size() == 0 && temp)){
                anss.push_back(asteroids[i]);
            }
        }
    }
    return anss; 
}

bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    int i = 0, j = 0;
    int size = pushed.size();
    stack<int> st;
    while(i < size && j < size){
        if(st.empty()){
            st.push(pushed[i]);
            i++;
        }else{
            if(popped[j] != st.top()){
                st.push(pushed[i]);
                i++;
            }else{
                st.pop();
                j++;
            }
        }
    }while(j < size){
        if(!st.empty() && popped[j] == st.top()){
            st.pop();
            j++;
        }else{
            break;
        }
    }
    return st.empty();
}
void displayVec(vector<int> & v){
    for(auto vv : v){
        cout << vv << " ";
    }
    cout << endl;
}
int main(){
    vector<int> a = {19, 3, 9, -3, -20, 70, -70};
    vector<int>ans = asteroidCollision(a);
    displayVec(ans);
    vector<int> m = {3, 4, 7, 1, 2};
    vector<int> n = {7, 1, 2, 4, 3};
    cout << validateStackSequences(m, n) << endl;


}