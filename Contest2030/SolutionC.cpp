#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int n;
        string word;
        cin >> n >> word;
        int zeros = 0;
        int ones = 0;
        bool repeat = false;
        for(int j = 0; j < n; j++){
            if(word[j] == '0'){
                zeros += 1;
            }else{
                if(j >= 1 && word[j-1] == '1'){
                    repeat = true;
                }
                ones += 1;
            }
        }
        if(ones >= zeros){
            cout << "yes" << endl;
        }else{
            if(word[0] == '1' || word[n-1] == '1' || repeat){
                cout << "yes" << endl;
                continue;
            }
            cout << "no" << endl;
        }
    }
}