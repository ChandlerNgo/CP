#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int days;
    int visitingDays;
    cin >> days >> visitingDays;
    vector<int> messes(days+1,0);
    vector<int> cleans(days+1,0);
    for(int i = 1; i <= days; i++){
        cin >> messes[i] >> cleans[i];
    }
    vector<int> visits(visitingDays+1,0);
    for(int i = 1; i <= visitingDays; i++){
        cin >> visits[i];
    }

    int totalCleans = 0;

    for(int i = 1; i <= visitingDays; i++){
        int mess = 0;
        for(int j = visits[i-1]+1; j <= visits[i]; j++){
            mess += messes[j];
        }
        // pick the days that will clean mess

        // cout << mess << endl;
    }

    cout << totalCleans << endl;
    // count the mess needed to clean up before the visit
    // greedily pick the highest amount one by one til mess is clean

}