#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while(t--){
        ll l; ll m;
        cin >> l >> m;
        l *= 100; // meter to cm
        queue<pair<ll,string>> carsLeft;
        queue<pair<ll,string>> carsRight;
        for(ll i = 0; i < m; i++){
            ll length;
            string direction;
            cin >> length >> direction;
            if(direction == "left"){
                carsLeft.push({length,direction});
            }else{
                carsRight.push({length,direction});
            }
        }
        ll trips = 0;
        string currentDirection = "left";
        while(!carsLeft.empty() || !carsRight.empty()){
            if(currentDirection == "left"){
                if(!carsLeft.empty()){
                    ll currentLength = 0;
                    ll carLength = carsLeft.front().first;
                    string direction = carsLeft.front().second;
                    while(!carsLeft.empty() && currentLength + carLength <= l){
                        currentLength += carLength;
                        carsLeft.pop();
                        if(!carsLeft.empty()){
                            carLength = carsLeft.front().first;
                            direction = carsLeft.front().second;
                        }
                    }
                }
                currentDirection = "right";
            }else{
                if(!carsRight.empty()){
                    ll currentLength = 0;
                    ll carLength = carsRight.front().first;
                    string direction = carsRight.front().second;
                    while(!carsRight.empty() && currentLength + carLength <= l){
                        currentLength += carLength;
                        carsRight.pop();
                        if(!carsRight.empty()){
                            carLength = carsRight.front().first;
                            direction = carsRight.front().second;
                        }
                    }
                }
                currentDirection = "left";
            }
            trips += 1;
        }
        cout << trips << "\n";
    }
    cout << flush;
}