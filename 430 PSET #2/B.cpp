#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    map<int, priority_queue<int>> quests;
    for(int i = 0; i < n; i++){
        string query;
        cin >> query;
        if(query == "add"){
            int energy;
            int gold;
            cin >> energy >> gold;
            if(quests.find(energy) == quests.end()){
                quests[energy] = priority_queue<int>();
            }
            quests[energy].push(gold);
        }else{
            int x;
            cin >> x;
            ll score = 0;
            while(x > 0 && !quests.empty()){
                auto i = quests.lower_bound(x);
                if(i == quests.end()){ // move to first possible element
                    i--;
                }
                while(i != quests.begin() && i->first > x){ // move to first possible element
                    i--;
                }
                if(i->first > x){ // break if no element < x
                    break;
                }

                score += i->second.top();
                x -= i->first;
                i->second.pop();
                if(i->second.empty()){
                    quests.erase(i->first);
                }
            }
            cout << score << endl;
        }
    }
}