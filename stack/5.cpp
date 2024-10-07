#include<bits/stdc++.h>
using namespace std;
/*sum of subarrays minimums*/

void displayVec(vector<int> & v){
    for(auto vv : v){
        cout << vv << " ";
    }
    cout << endl;
}

vector<int> largerOnRight(vector<int> & vec){
    stack<pair<int, int>>st;
    vector<int> ans(vec.size());
    for(int j = vec.size()-1; j >= 0; j--){
        int count = vec.size();
        if(st.empty()){
            st.push({vec[j], j});
        }else{
            while(!st.empty() && vec[j] > st.top().first){
                st.pop();
            }
            if(!st.empty() && vec[j] < st.top().first){
                count = st.top().second;
                st.push({vec[j], j});

            }
            if(st.empty()){
                st.push({vec[j], j});
            }
            
        }
        ans[j] = count-j;
    }
    displayVec(ans);
    return ans;
}
vector<int> largerOnLeft(vector<int> &v){
    stack<pair<int, int>> st;
    vector<int> ans(v.size());
    for(int i = 0; i < v.size(); i++){
        int count = -1;
        if(st.empty()){
            st.push({v[i], i});
        }else{
            while( !st.empty() && st.top().first < v[i]){
                st.pop();
            }
            if(st.empty()){
                st.push({v[i], i});
            }
            if( !st.empty() && v[i] < st.top().first){
                count = st.top().second;
                st.push({v[i], i});
            } 
        }
        ans[i] = i-count;
    }
    displayVec(ans);
    return ans;
}
vector<int> smallerOnLeft(vector<int> &v){
    stack<pair<int, int>> st;
    vector<int> ans(v.size());
    for(int i = 0; i < v.size(); i++){
        int count = -1;
        if(st.empty()){
            st.push({v[i], i});
        }else{
            while( !st.empty() && st.top().first > v[i]){
                st.pop();
            }
            if(st.empty()){
                st.push({v[i], i});
            }
            if( !st.empty() && v[i] > st.top().first){
                count = st.top().second;
                st.push({v[i], i});
            } 
        }
        ans[i] = i-count;
    }
    displayVec(ans);
    return ans;
}
vector<int> smallerOnRight(vector<int> &v){
    stack<pair<int, int>> st;
    vector<int> ans(v.size());
    for(int i = v.size()-1; i >= 0; i--){
        int count = v.size();
        if(st.empty()){
            st.push({v[i], i});
        }else{
            while( !st.empty() && st.top().first > v[i]){
                st.pop();
            }
            if(st.empty()){
                st.push({v[i], i});
            }
            if( !st.empty() && v[i] > st.top().first){
                count = st.top().second;
                st.push({v[i], i});
            } 
        }
        ans[i] = count-i;
    }
    displayVec(ans);
    return ans;
}
// int solve(vector<int> & a){
//     int size = a.size();
//     vector<int> l(size), r(size);
//     l[0] = 0;
//     r[size-1] = 0;
//     int ans = 0;
//     for(int i = 0; i < size; i++){
//         int j = i-1;
//         while(j > -1){
//             if(a[j] < a[i]){
//                 l[i] = i-j-1;
//                 break;
//             }
//             if(j == 0){
//                 l[i] = i-j;
//             }
//             j--;
//         }
//         j = i+1;
//         while(j != size){
//             if(a[j] < a[i]){
//                 r[i] = j - i-1;
//                 break;
//             }
//             if(j == size-1){
//                 r[i] = j - i;
//             }
//             j++;

//         }
//         ans = ans + ((l[i]+1)*(r[i]+1))*a[i];
       
//     }
//     displayVec(l);
//     displayVec(r);
//     return ans;  

// }
int main(){
    int mod = 1000000007;
    vector<int> vec = {71,55,82,55};
    vector<int> smallerToleft = smallerOnLeft(vec);
    vector<int> smallerToright = smallerOnRight(vec);
    int ans = 0;
    for(int i = 0; i < vec.size(); i++){
        ans = (ans + (smallerToleft[i] * smallerToright[i])*vec[i])%mod;
       
    }
    cout << ans << endl;
}