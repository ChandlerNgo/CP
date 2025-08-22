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
        string s;
        cin >> s;
        string answer;
        cin >> answer;
        vector<pair<int,char>> key;
        int size = 0;
        char current = s[0];
        for(int i = 0; i < s.size(); i++){
            if(s[i] == current){
                size += 1;
            }else{
                key.push_back({size,current});
                size = 1;
                current = s[i];
            }
        }
        if(size > 0){
            key.push_back({size,current});
        }
        vector<pair<int,char>> answerKey;
        size = 0;
        current = answer[0];
        for(int i = 0; i < answer.size(); i++){
            if(answer[i] == current){
                size += 1;
            }else{
                answerKey.push_back({size,current});
                size = 1;
                current = answer[i];
            }
        }
        if(size > 0){
            answerKey.push_back({size,current});
        }

        // for(auto x : key){
        //     cout << x.first << x.second << endl;
        // }
        // cout << endl;
        // for(auto x : answerKey){
        //     cout << x.first << x.second << endl;
        // }

        // cout << answerKey.size() << " " << key.size() << "\n";
        
        if(answerKey.size() == key.size()){
            int possible = true;
            for(int i = 0; i < key.size(); i++){
                // cout << key[i].first << " " << answerKey[i].first << "\n";
                if(!(key[i].first <= answerKey[i].first && answerKey[i].first <= key[i].first*2 && key[i].second == answerKey[i].second)){
                    possible = false;
                    break;
                }
            }
            if(possible){
                cout << "YES\n";
            }else{
                cout << "NO\n";
            }
        }else{
            cout << "NO\n";
        }
    }
}