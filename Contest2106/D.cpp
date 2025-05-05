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
        int m;
        cin >> n >> m;
        vector<int> flowers;
        for(int i = 0; i < n; i++){
            int num;
            cin >> num;
            flowers.push_back(num);
        }

        vector<int> beauty;
        for(int i = 0; i < m; i++){
            int num;
            cin >> num;
            beauty.push_back(num);
        }

        int minVal = INT_MAX;
        for(int i = -1; i < m; i++){
            vector<int> newBeauty;
            int val = 0;
            for(int j = 0; j < m; j++){
                if(i == j){
                    val = beauty[j];
                    continue;
                }
                newBeauty.push_back(beauty[j]);
            }
            
            int j = 0;
            for(int k = 0; k < n; k++){
                if(j >= newBeauty.size()){
                    break;
                }
                if(flowers[k] >= newBeauty[j]){
                    j += 1;
                }
            }
            if(j >= newBeauty.size()){
                minVal = min(minVal,val);
            }
        }

        if(minVal == INT_MAX){
            cout << -1;
        }else{
            cout << minVal;
        }
        cout << "\n";
    }   
    cout << flush;
}