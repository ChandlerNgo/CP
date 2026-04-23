#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;

    for(int i = 0; i < t; i++){
        int n;
        cin >> n;
        int remainder = n%5;
        int div = n/5;
        string word = "aeiou";
        string curWord = "";
        for(int j = 0; j < 5; j++){
            int mult;
            if(remainder > 0){
                mult = div+1;
                remainder -= 1;
            }else{
                mult = div;
            }
            if(mult != 0){
                for(int k = 0; k < mult; k++){
                    curWord += word[j];
                }
            }
        }
        cout << curWord << endl;
    }
    
    return 0;
}