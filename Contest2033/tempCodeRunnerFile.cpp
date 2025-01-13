#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        map<int,int> lakes;
        int n;
        cin >> n;
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                int num;
                cin >> num;
                if(lakes.find(j-k) == lakes.end()){
                    lakes[j-k] = num;
                }else{
                    lakes[j-k] = min(lakes[j-k],num);
                }
            }
        }
        int holes = 0;
        for (auto i = lakes.begin(); i != lakes.end(); ++i) {
            if(i->second < 0){
                holes += i->second;
            }
        }
        cout << holes << endl;
    }
    
}