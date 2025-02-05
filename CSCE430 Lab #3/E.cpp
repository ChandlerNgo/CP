#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int sumSecond = 0;
    int sumMinute = 0;
    for(int i = 0; i < n; i++){
        int minute;
        int second;
        cin >> minute >> second;
        sumSecond += second;
        sumMinute += minute*60;
    }
    double answer = (double)sumSecond/(double)sumMinute;
    if(answer <= 1){
        cout << "measurement error" << endl;
    }else{
        cout << fixed << setprecision(9) << answer << endl;
    }
}