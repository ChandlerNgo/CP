#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int answer = 0;

    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        answer += num;
    }
    cout << answer << endl;
}