#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

void tower(vector<pair<int,int>>& moves, int n, int start, int end){
    if(n == 1){
        moves.push_back({start,end});
        return;
    }

    int other = 1;
    if(other == start || other == end){
        other += 1;
    }
    if(other == start || other == end){
        other += 1;
    }
    // move towers n-1 to otherNum
    tower(moves, n-1, start, other);
    // move tower n to end
    moves.push_back({start,end});
    // move towers n-1 from otherNum to end
    tower(moves, n-1, other, end);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<pair<int,int>> moves;
    tower(moves, n, 1, 3);
    cout << moves.size() << endl;
    for(auto x : moves){
        cout << x.first << " " << x.second << endl;
    }
}