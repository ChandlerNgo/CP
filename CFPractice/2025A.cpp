#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        string first;
        string second;
        cin >> first >> second;
        int seconds = first[0] == second[0];
        int j = 0;
        for(j = 0; j < min(first.size(),second.size()); j++){
            if(first[j] == second[j]){
                seconds += 1;
            }else{
                break;
            }
        }
        cout << seconds + first.size()-j + second.size()-j << endl;
    }
    


}