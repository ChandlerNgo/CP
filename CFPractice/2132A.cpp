#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // v = beginnning
    // d == end

    int t;
    cin >> t;
    while(t--){
        int n;
        string s;
        cin >> n >> s;
        int d;
        string newS;
        string in;
        cin >> d >> newS >> in;

        for(int i = 0; i < in.size(); i++){
            if(in[i] == 'D'){
                s += newS[i];
            }else{
                s = newS[i] + s;
            }
        }
        cout << s << "\n";
    }
}