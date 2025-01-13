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
        for(int j = 0; j < n; j++){
            if(word[j] == '0'){
                zeros += 1;
            }else{
                ones += 1;
            }
        }
        if(ones >= zeros){
            cout << "yes" << endl;
        }else if(zeros > ones){
            cout << "no" << endl;
        }
    }
}