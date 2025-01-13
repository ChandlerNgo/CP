#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    

    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        string s;
        cin >> s;
        if(s.size() % 2 == 0){
            int score = 0;
            for(int j = 0; j < s.size(); j++){
                score += s[j] - 96;
            }
            cout << "Alice " << score << endl;
        }else{
            int score = 0;
            int bobScore;
            if(s[0] > s[s.size()-1]){
                for(int j = 0; j < s.size()-1; j++){
                    score += s[j] - 96;
                }
                bobScore = s[s.size()-1]-96;
            }else{
                for(int j = s.size()-1; j > 0; j--){
                    score += s[j] - 96;
                }
                bobScore = s[0]-96;
                
            }
            if(score > bobScore){
                cout << "Alice " << score-bobScore << endl;
            }else{
                cout << "Bob " << bobScore-score << endl;
            }
        }
    }
}