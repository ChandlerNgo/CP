#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    stack<int> cur;
    stack<int> aux;
    for(int i = 0; i < 2*n; i++){
        int num;
        cin >> num;
        cur.push(num);
    }

    int moves = 0;

    while(!cur.empty()){
        if(aux.empty() || aux.top() != cur.top()){
            aux.push(cur.top());
            cur.pop();
            moves += 1;
        }else if(aux.top() == cur.top()){
            cur.pop();
            aux.pop();
            moves += 1;
        }
    }
    if(!cur.empty() || !aux.empty()){
        cout << "impossible" << endl;
    }else{
        cout << moves << endl;
    }
}