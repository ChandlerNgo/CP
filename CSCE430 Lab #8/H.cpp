#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

bool cmp(pair<string, int>& a, 
    pair<string, int>& b) 
{ 
    if(a.second != b.second){
        return a.second > b.second; 
    }

    return a.first < b.first;
} 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        map<string,int> toys;
        for(int i = 0; i < n; i++){
            string s;
            cin >> s;
            int amount;
            cin >> amount;
            toys[s] += amount;
        }

        vector<pair<string,int>> sorted;
        for(auto toy : toys){
            sorted.push_back(toy);
        }

        sort(sorted.begin(),sorted.end(),cmp);

        cout << sorted.size() << "\n";
        for(auto toy : sorted){
            cout << toy.first << " " << toy.second << "\n";
        }
    }
    cout << flush;
}