#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    priority_queue<int> towers;
    for(int i = 0;i < n; i++){
        int num;
        cin >> num;
        towers.push(num);
    }
    int destroyed = 0;
    int minScore = INT_MAX;
    while(!towers.empty()){
        int current = towers.top();
        towers.pop();
        minScore = min({minScore,destroyed + current});
        destroyed += 1;
    }
    cout << min(minScore,destroyed) << endl;
}