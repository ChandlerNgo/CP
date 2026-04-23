#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    string you;
    string him;
    cin >> you >> him;
    int match = 0;
    for(int i = 0; i < you.size(); i++){
        if(you[i] == him[i]){
            match += 1;
        }
    }
    cout << min(match,n) + min(you.size()-match, you.size()-n) << endl;
}