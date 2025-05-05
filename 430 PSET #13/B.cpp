#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;

    if(s.size() < 6){
        int n = stoi(s);
        if(n == 1){
            cout << 1 << endl;
            return 0;
        }
        int i = 1;
        int factorial = 1;
        while(factorial != n){
            factorial *= i;
            i += 1;
        }
        cout << i - 1 << endl;
        return 0;
    }

    int n = 1;
    
    double answer = 1;
    while(floor(answer) != s.size()){
        answer += log10(n);
        n += 1;
    }
    cout << n-1 << endl;
}