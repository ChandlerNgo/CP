#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    int c;
    cin >> n >> c;
    vector<int> a;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        a.push_back(num);
    }

    if(c == 2 && (n%2 == 1)){
        cout << -1 << endl;
        return 0;
    }

    for(int i = 0; i < n; i++){
        a[i] -= 1;
    }

    int answer = 0;

    for(int i = 0; i < n; i++){
        int prev = a[i-1];
        int cur = a[i];
        int next = a[(i + 1) % n];

        if(a[i] == prev || a[i] == next){
            answer += 1;
            while((a[i] == prev || a[i] == next) && (a[i] + 1) % c != cur){
                a[i] = (a[i] + 1) % c;
            }
        }
    }
    for(auto x : a){
        cout << x << " ";
    }
    cout << endl;
}