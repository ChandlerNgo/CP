#include <bits/stdc++.h>

using namespace std;

int main(){

    long long t;
    cin >> t;
    for(int i = 0; i < t; i++){
        long long n;
        cin >> n;
        map<long long, long long> monsters;
        long long maxMonster = 0;
        for(int j = 0; j < n; j++){
            long long monster;
            cin >> monster;
            if(monsters.find(monster) == monsters.end()){
                monsters[monster] = 1;
            }else{
                monsters[monster] += 1;                
            }
            maxMonster = max(monster,maxMonster);
        }

        long long spells = 0;

        long long currentNeed = 1;
        for(long long j = 1; j <= maxMonster; j++){
            if(monsters.find(j) != monsters.end()){
                spells += (j - currentNeed);
                monsters[j] -= 1;
                currentNeed += 1;
                if(monsters[j] == 0){
                    monsters.erase(j);
                }else if(currentNeed <= j){
                    j -= 1;
                }
            }
        }
        cout << spells << endl;
    }
}