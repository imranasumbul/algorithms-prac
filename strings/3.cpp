#include<bits/stdc++.h>
using namespace std;

string intToRoman(int num) {
    vector<int> vi;
    vector<string> vs;
    vi = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
    vs = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
    int n = num;
    string ans="";
    string stnum = to_string(num);
    int times10 = stnum.size()-1;
    while(!(times10 < 0)){
        
    
        int dig = ((n/pow(10, times10)))*pow(10, times10);
        n = n - dig;
        while(dig > 0){
            for(int i = vi.size()-1; i >= 0; i--){
                if(vi[i] <= dig){
                    ans = ans + vs[i];
                    dig = dig - vi[i];
                    break;
                }
            }
        }
        
        
     
        times10 --;
    }
   
    return ans;

}  

int main(){
    int num = 2936;
    cout << intToRoman(114) << endl;
    // cout << intToRoman(2) << endl;
    // cout << intToRoman(3) << endl;
    // cout << intToRoman(4) << endl;
    // cout << intToRoman(5) << endl;
    // cout << intToRoman(6) << endl;
    // cout << intToRoman(7) << endl;
    // cout << intToRoman(8) << endl;
    // cout << intToRoman(9) << endl;
    // cout << intToRoman(10) << endl;
    // cout << intToRoman(11) << endl;
    // cout << intToRoman(12) << endl;
    // cout << intToRoman(13) << endl;
    // cout << intToRoman(14) << endl;

}
