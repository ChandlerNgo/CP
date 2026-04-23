#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        string n;
        cin >> n;
        if(n[n.size()-1] == '2' || n[n.size()-1] == '4' || n[n.size()-1] == '6' || n[n.size()-1] == '8'){
            cout << 0 << endl;
        }else if(n[0] == '2' || n[0] == '4' || n[0] == '6' || n[0] == '8'){
            cout << 1 << endl;
        }else if(n.find("2") != string::npos || n.find("4") != string::npos || n.find("6") != string::npos || n.find("8") != string::npos){
            cout << 2 << endl;
        }else{
            cout << -1 << endl;
        }
    }
}