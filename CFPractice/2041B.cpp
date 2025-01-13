#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int w;
        int b;
        cin >> w >> b;
        queue<tuple<int,int,int>> pins;
        set<tuple<int,int,int>> seen;
        pins.push({w,b,1});
        int maxLength = 0;
        int repeats = 0;
        while(!pins.empty()){
            tuple<int,int,int> pinSet = pins.front();
            pins.pop();
            if(seen.find(pinSet) == seen.end()){
                seen.insert(pinSet);
            }else{
                // repeats += 1;
                // cout << repeats << endl;
                continue;
            }
            // cout << get<0>(pinSet) << " " << get<1>(pinSet) << " " << get<2>(pinSet) << endl;
            if(get<0>(pinSet) < get<2>(pinSet) && get<1>(pinSet) < get<2>(pinSet)){
                maxLength = max(maxLength, get<2>(pinSet) - 1);
                continue;
            }

            if(get<0>(pinSet) >= get<2>(pinSet)){
                pins.push({get<0>(pinSet)-get<2>(pinSet), get<1>(pinSet), get<2>(pinSet)+1});
            }

            if(get<1>(pinSet) >= get<2>(pinSet)){
                pins.push({get<0>(pinSet), get<1>(pinSet)-get<2>(pinSet), get<2>(pinSet)+1});
            }
        }

        cout << maxLength << endl;
    }
}