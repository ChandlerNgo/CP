#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        int k;
        cin >> n >> k;
        vector<int> a(n);
        vector<int> b(n);
        set<int> kVals;
        vector<int> maxVals;
        int maxVal = INT_MAX;
        int maxA = -1;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            maxA = max(maxA, a[i]);
        }
        for(int i = 0; i < n; i++){
            cin >> b[i];
            if(b[i] != -1){
                kVals.insert(a[i] + b[i]);
            }else{
                maxVals.push_back(k+a[i]);
                maxVal = min(maxVal, k+a[i]);
            }
        }

        if(kVals.size() > 1){
            cout << 0 << "\n";
            continue;
        }

        if(kVals.size() == 1){
            
            int onlyK = *kVals.begin();
            bool possible = true;
            for(auto x : maxVals){
                if(x < onlyK){
                    possible = false;
                }
            }

            if(possible && maxA <= onlyK){
                cout << 1 << "\n";
            }else{
                cout << 0 << "\n";
            }
            continue;
        }

        

        if(maxVal < maxA){
            cout << 0 << "\n";
        }else{
            cout << maxVal - maxA + 1 << "\n";
        }
    }
    cout << flush;
}