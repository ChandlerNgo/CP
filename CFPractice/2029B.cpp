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
        string s;
        string r;
        cin >> n >> s >> r;
        stack<char> seq;
        int rIndex = 0;
        for(int i = 0; i < s.size(); i++){
            char character = s[i];
            while(!seq.empty() && seq.top() != character){
                seq.pop();
                character = r[rIndex];
                rIndex += 1;
            }
            seq.push(character);
        }

        if(seq.size() == 1){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
}