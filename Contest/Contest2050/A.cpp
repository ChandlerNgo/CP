#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        int m;
        cin >> n >> m;
        int score = 0;
        bool notDone = true;
        for(int i = 0; i < n; i++){
            string s;
            cin >> s;
            if(m >= s.size() && notDone){
                m -= s.size();
                score += 1;
            }else{
                notDone = false;
            }
        }
        cout << score << endl;
    }

}