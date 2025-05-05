#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    int m;
    cin >> n >> m;
    set<int> movements;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        int dwarf = -1;
        int candy = -1;
        for(int j = 0; j < s.size(); j++){
            if(s[j] == 'G'){
                dwarf = j;
            }else if(s[j] == 'S'){
                candy = j;
            }
        }

        // cout << candy << " " << dwarf << endl;

        if(dwarf >= candy){
            movements.insert(m - dwarf - 1);
        }else{
            movements.insert(candy - dwarf);
        }
    }
    int answer = -1;
    int count = 0;
    for(auto x : movements){
        if(x > 0){
            answer = max(answer,x);
            count += 1;
        }
    }
    cout << (answer == -1 ? answer : count) << endl;
}