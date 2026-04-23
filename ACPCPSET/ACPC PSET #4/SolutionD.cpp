#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    for(int i = 0; i < t; i++){
        string alphabet;
        string word;
        cin >> alphabet >> word;
        int time = 0;
        for(int j = 1; j < word.size(); j++){
            int pos_1 = alphabet.find(word[j]);
            int pos_2 = alphabet.find(word[j-1]);
            time += abs(pos_1-pos_2);
        }
        cout << time << endl;
    }
}