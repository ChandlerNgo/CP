#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int cs;
        int econ;
        cin >> cs >> econ;
        vector<int> csKids;
        ll csTotal = 0;
        ll econTotal = 0;
        for(ll i = 0; i < cs; i++){
            ll num;
            cin >> num;
            csTotal += num;
            csKids.push_back(num);
        }
        for(ll i = 0; i < econ; i++){
            ll num;
            cin >> num;
            econTotal += num;
        }
        float csavg = static_cast<float>(csTotal)/cs;
        float econavg = static_cast<float>(econTotal)/econ;
        int kids = 0;
        for(int i = 0; i < cs; i++){
            if(csKids[i] < csavg && csKids[i] > econavg){
                kids += 1;
            }
        }
        cout << kids << endl;

        // kids below avg iq in cs
        // above the avg in econ

    }
}