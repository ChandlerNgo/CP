#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int n; // number of quests
        int k; // max quests
        cin >> n >> k;
        vector<int> firstQuests(n);
        vector<int> nextQuests(n);
        for(int j = 0; j < n; j++){
            int num;
            cin >> num;
            firstQuests[j] = num;
        }
        for(int j = 0; j < n; j++){
            int num;
            cin >> num;
            nextQuests[j] = num;
        }
        
        
    }
}