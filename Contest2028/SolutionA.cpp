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
        int a;
        int b;
        string directions;
        cin >> n >> a >> b >> directions;
        int x = 0;
        int y = 0;
        bool found = false;
        for(int k = 0; k < 20; k++){
            for(int j = 0; j < directions.size(); j++){
                if(directions[j] == 'N'){
                    y += 1;
                }
                if(directions[j] == 'S'){
                    y -= 1;
                }
                if(directions[j] == 'E'){
                    x += 1;
                }
                if(directions[j] == 'W'){
                    x -= 1;
                }
                if (x == a && y == b){
                    found = true;
                    break;
                }
            }
            if(found){
                break;
            }
        }

        if(a == x && b == y){
            cout << "yes\n";
        }else{
            cout << "no\n";
        }
    }
}