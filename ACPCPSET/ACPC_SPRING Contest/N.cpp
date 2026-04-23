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
    map<int,int> animals;

    for(int i = 1; i <= n; i++){
        animals[i] = 0;
    }
    for(int i = 0;i < m; i++){
        int a;
        int b;
        cin >> a >> b;
        animals[a] += 1;
        animals[b] += 1;
    }

    int score = 0;

    for(auto x : animals){
        cout << x.first << " " << x.second << endl;
        if(x.second >= 2){
            score += 1;
        }else{
            score += (2 - x.second);
        }
    }
    cout << score << endl;
}