#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,k;
    cin >> n >> m >> k;
    vector<int> plots(n);
    for(int i = 0; i < n; i++){
        cin >> plots[i];
    }   
    set<int> homes;
    for(int i = 0; i < m; i++){
        int num;
        cin >> num;
        homes.insert(num);   
    }

    for(int i = 0; i < k; i++){
        int num;
        cin >> num;
        homes.insert(num/sqrt(2));
    }

    vector<int> arrayHomes;
    

    for(auto x : homes){
        arrayHomes.push_back(x);
    }

    sort(arrayHomes.begin(),arrayHomes.end());
    int maxHomesPaired = -1;

    vector<int> paired(plots.size(), false);
    int amtPaired = 0;
    for(int i = arrayHomes.size()-1; i >= 0; i--){
        for(int j = n-1; j >= 0; j--){
            if(arrayHomes[i] < plots[j] && !paired[j]){
                paired[j] = true;
                amtPaired += 1;
                break;
            }
        }
    }

    cout << amtPaired << endl;
}