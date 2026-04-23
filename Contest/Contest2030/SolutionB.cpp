#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for(int i = 0 ; i < t; i++){
        int n;
        cin >> n;
        string word(n-1,'0');
        word += "1";
        cout << word << endl;
    }
}