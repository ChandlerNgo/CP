#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int n;
        cin >> n;
        vector<int> odds;
        for(int j = 0; j < n; j++){
            int number;
            cin >> number;
            if(number % 2 == 1){
                odds.push_back(number);
            }
        }



        if(odds.size() % 2 == 0){
            cout << 0 << endl;
            continue;
        }

        int minVal = 0;

        for(int j = 0; j < odds.size(); j++){
            minVal = (int)log2(odds[j])+1;
        }

        cout << minVal << endl;
    }
}