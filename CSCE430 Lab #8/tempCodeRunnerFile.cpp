#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> chairs(n,0);
    for(int i = 0; i < n; i++){
        cin >> chairs[i];
    }

    int clock = 0;

    for(int i = 0; i < n-1; i++){
        int offset = 0;
        for(int tick = 0; tick < chairs[clock]; tick++){
            while(chairs[(tick+offset)%n] != -1){
                offset += 1;
            }
            if(tick == chairs[clock]-1){
                chairs[(tick+offset)%n] = -1;
            }
        }
    }

    for(auto x : chairs){
        if(x != -1){
            cout << x << endl;
            break;
        }
    }
}