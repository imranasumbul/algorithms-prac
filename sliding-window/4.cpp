#include<bits/stdc++.h>
using namespace std;
/*grumpy bookstore owner*/
int solution(vector<int> &grumpy, vector<int> &customers, int minCustomershappy, int windowSize){
    int i = 0, j = 0;
    int ansToAdd = 0;
    int temp = 0;
    while(j < customers.size()){
        if(grumpy[j] == 1){
            temp += customers[j];
        }
        if(j - i + 1 == windowSize){
            ansToAdd = max(ansToAdd, temp);
            if(grumpy[i] == 1){
                temp -= customers[i];
            }
            i++;
        }
        
        j++;
    }
    return minCustomershappy+ansToAdd;
}

int main(){

    vector<int> grumpy = {1, 0, 1, 1, 0, 0};
    vector<int> customers = {2, 4, 1, 0, 3, 2};
    int minCustomershappy = 0;
    for(int i = 0; i < grumpy.size(); i++){
        if(grumpy[i] == 0){
            minCustomershappy += customers[i];
        }
        
    }
    cout << minCustomershappy << endl;
    int window = 2;
    cout << solution(grumpy, customers, minCustomershappy, window) << endl;
    
}