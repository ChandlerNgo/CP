#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        set<int> s;
        bool found = false;
        for(int i = 0; i < n; i++){
            int num;
            cin >> num;
            if(s.find(num) != s.end()){
                found = true;
            }
            s.insert(num);
        }
        cout << (found ? "YES" : "NO") << "\n";
    }
}