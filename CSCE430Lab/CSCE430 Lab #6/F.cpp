#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<string> words(n+1,"");
    for(int i = 1; i <= n; i++){
        string s;
        cin >> s;
        words[i] = s;
    }
    if(n == 1){
        cout << words[1] << endl;
    }
    int a;
    for(int i = 0; i < n-1; i++){
        int b;
        cin >> a >> b;
    }
    cKout << val << endl;
}