#include<bits/stdc++.h>
using namespace std;
/*sort vowels*/

bool isVowel(char c){
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'){
        return true;
    }
    return false;
}
void sortVowels(string& s){
   
    map<char, int> mp;
    for(auto c : s){
        if(isVowel(c) == true){
            mp[c]++;
        }
    }
    auto it = mp.begin();
    for(auto c : s){
        if(isVowel(c) == true){
            while((*it).second == 0){
                it++;
            }
            c = (*it).first;
            (*it).second--;
        }
    }
}
int main(){
    string input = "fuibvceeghAERFiujn";
    cout << input << endl;
    sortVowels(input);
    cout << input << endl;
    
}