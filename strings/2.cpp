#include<bits/stdc++.h>
using namespace std;
/*determine if strings are close*/
void displayVec(vector<int> & v){
    for(auto a : v){
        cout << a << " ";
    }
    cout << endl;
}
void mergeSort(int low, int mid, int high, vector<int>& vec){
    if(low == high){
        return;
    }
    mergeSort(low, (low+mid)/2, mid, vec);
    mergeSort(mid+1, (mid+1+high)/2, high, vec);
    vector<int> v1(mid-low+1), v2(high - mid);
    int i = 0, j = 0;
    for(int k = low; k <= mid; k++){
        v1[i] = vec[k];
        i++;
    }
    for(int l = mid+1; l <= high; l++){
        v2[j] = vec[l];
        j++;
    }
    i = 0, j = 0;
    while(i < v1.size() && j < v2.size()){
        if(v1[i] >= v2[j]){
            vec[low] = v2[j];
            low++;
            j++;
        }else{
            vec[low] = v1[i];
            low++;
            i++;
        }
    }
    while(i < v1.size()){
        vec[low] = v1[i];
        i++;
        low++;
    }
    while(j < v2.size()){
        vec[low] = v2[j];
        j++;
        low++;
    }
}
bool ifStringsClose(string& s1, string & s2){
    vector<int> v1(27, 0), v2(27, 0);
    for(auto a: s1){
        v1[a - 'a']++;
    }for(auto a: s2){
        v2[a - 'a']++;
    }
    for(int i = 0; i < v1.size(); i++){
        if((v1[i] == 0 && v2[i] != 0) || (v1[i] != 0 && v2[i] == 0)){
            return false;
        }
    }
    mergeSort(0, (v1.size()-1)/2, v1.size()-1, v1);
    mergeSort(0, (v2.size()-1)/2, v2.size()-1, v2);
    displayVec(v1);
    displayVec(v2);
    for(int i = 0; i < v1.size(); i++){
        if(v1[i] != v2[i]){
            return false;
        }
    }
    return true;
}


int main(){
    string str1 = "a";
    string str2 = "aa";
    cout << ifStringsClose(str1, str2) << endl;

}