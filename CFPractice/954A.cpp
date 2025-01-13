#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    stack<char> s;
    int n;
    string directions;
    cin >> n;
    cin >> directions;
    s.push(directions[0]);
    for(int i = 1; i < n; i++){
        if((s.top() == 'R' && directions[i] == 'U') || (s.top() == 'U' && directions[i] == 'R')){
            s.pop();
            s.push('D');
        }else{
            s.push(directions[i]);
        }
    }
    cout << s.size() << endl;
}
