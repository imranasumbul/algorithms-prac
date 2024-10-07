#include<bits/stdc++.h>
using namespace std;
/*potions and spells*/

void swap(int &a, int &b){
    int c = a;
    a = b;
    b = c;
    return;
}
int partition(int arr[], int low, int high){
    int partition = low;
    int elem = arr[high];
    for(int i = low; i < high; i++){
        if(arr[i] < elem){
            swap(arr[partition], arr[i]);
            partition++;
        }
    }
    swap(arr[high], arr[partition]);
    return partition;
}
void quickSort(int arr[], int low, int high){
    if(high < low){
        return;
    }
    int part_index = partition(arr, low, high);
    quickSort(arr, low, part_index-1);
    quickSort(arr, part_index+1, high);
}

void lowerBound(int arr[], int target, int low, int high, int& ans){ // for lower bound (a >= target)

    if(low > high){
        return ;
    }
    int mid = (low+high)/2;
    if(arr[mid] < target){
       return lowerBound(arr, target, mid+1, high, ans);
    }
    if(arr[mid] >= target){
        ans = mid;
        return lowerBound(arr, target, low, mid-1, ans);
    }
}
int main(){
    vector<int> spellStrength = {3,1,2};
    int potionStrength[] = {8,5,8};
    int success = 16;
    int potionSize = sizeof(potionStrength)/sizeof(potionStrength[0]);
    quickSort(potionStrength, 0, potionSize-1);
    vector<int> anss;
    for(int i = 0; i < spellStrength.size(); i++){
        int ans = potionSize;
        int target = (success+spellStrength[i]-1)/spellStrength[i];
        lowerBound(potionStrength, target, 0, potionSize-1,ans);
        int answer = potionSize  - ans;
        anss.push_back(answer);
    }
   for(auto m : anss){
        cout << m << " ";
   }
   cout << endl;

}