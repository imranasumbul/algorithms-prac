#include <iostream> 
#include <algorithm> 
using namespace std; 
 
bool isPossible(int A, int B, int C) { 
     
    int maxStrips = max({A, B, C}); 
     
   
    int sumOthers = A + B + C - maxStrips; 
     
    
    if (maxStrips > sumOthers + 1) { 
        return false; 
    } 
    return true; 
} 
 
int main() { 
    int T; 
    cin >> T; 
     
    while (T--) { 
        int A, B, C; 
        cin >> A >> B >> C; 
         
        if (isPossible(A, B, C)) { 
            cout << "YES" << endl; 
        } else { 
            cout << "NO" << endl; 
        } 
    } 
     
    return 0; 
} 