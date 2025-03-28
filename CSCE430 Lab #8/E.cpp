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
        while(chairs[clock%n] == -1){
            clock += 1;
            clock = clock % n;
        }
        int offset = 0;
        for(int tick = 0; tick < (chairs[clock]%(n-i+1))+1; tick++){
            while(chairs[(clock+tick+offset)%n] == -1){
                offset += 1;
            }
            if(tick == (chairs[clock]%(n-i+1))){
                chairs[(clock+tick+offset)%n] = -1;
                clock = (clock+tick+offset+1)%n;
            }
        }
        for(auto x : chairs){
            cout << x << " ";
        }
        cout << endl;
    }

    for(int i = 0; i < n; i++){
        if(chairs[i] != -1){
            cout << i+1 << endl;
            break;
        }
    }
}