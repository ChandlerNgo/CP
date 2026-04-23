#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int a;
        int b;
        cin >> a >> b;
        int minScore = 100000000;
        for(int c = a; c <= b; c++){
            minScore = min(minScore, (c-a)+(b-c));
        }
        cout << minScore << endl;
    }
}