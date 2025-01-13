#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int num;
        cin >> num;
        stringstream ss;
        ss << num;
        string str = ss.str();

        if(num % 2 == 0){
            cout << 0 << endl;
            continue;
        }else if(str[0] == '0' || str[0] == '2' || str[0] == '4' || str[0] == '6' || str[0] == '8'){
            cout << 1 << endl;
        }else{
            bool evenFound = false;
            for(int j = 1; j < str.size()-1; j++){
                
                if(str[j] == '0' || str[j] == '2' || str[j] == '4' || str[j] == '6' || str[j] == '8'){
                    evenFound = true;
                    break;
                }
            }
            if(evenFound){
                cout << 2 << endl;
            }else{
                cout << -1 << endl;
            }
        }

    }
}