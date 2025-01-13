#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string one;
    string two;
    cin >> one >> two;
    if(one.size() != two.size()){
        cout << "NO" << endl;
        return 0;
    }
    for(int i = 0; i < one.size(); i++){
        if(one[i] != two[one.size()-1-i]){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
}