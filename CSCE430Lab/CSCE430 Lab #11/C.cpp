#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;

    vector<char> answers(n,' ');

    for(int i = 0; i < n; i++){
        char a;
        cin >> a;
        answers[i] = a;
    }

    int score = 0;
    for(int i = 1; i < n; i++){
        if(answers[i] == answers[i-1]){
            score += 1;
        }
    }
    cout << score << endl;
}