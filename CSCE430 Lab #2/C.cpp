#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    while(getline(cin,s)){
        stringstream ss(s);
        char c;
        ss >> c;
        vector<int> holding;

        if(isdigit(c)){
            auto it = lower_bound(holding.begin(), holding.end(), c);
            holding.insert(it, c);
        }else{
            if(holding.size() % 2 == 0){
                auto it = lower_bound(holding.begin(), holding.end(), holding[(holding.size()/2) + 1]);
                cout << holding[(holding.size()/2) + 1] << endl;
                holding.erase(it);
            }else{
                auto it = lower_bound(holding.begin(), holding.end(), holding[(holding.size()+1)/2]);
                cout << holding[(holding.size()+1)/2] << endl;
                holding.erase(it);
            }
        }
    }
}