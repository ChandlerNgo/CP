#include <bits/stdc++.h>

using namespace std;

int main(){

    long long t;
    cin >> t;
    for(int i = 0; i < t; i++){
        map<long long,long long> mods;
        long long P;
        cin >> P;
        for(int j = 1; j <= P; j++){
            long long num = P % j;
            if(mods.find(num) != mods.end()){
                cout << mods[num] << " " << j << endl;
                break;
            }else{
                mods[num] = j;
            }
        }
    }
}