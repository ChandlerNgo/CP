#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int currentSum = 0;
        int happyDays = 0;
        for(int i = 0; i < n; i++){
            int num;
            cin >> num;
            currentSum += num;
            int numSqrt = sqrt(currentSum);
            if((numSqrt*numSqrt == currentSum) && numSqrt % 2 == 1){
                happyDays += 1;
            }
        }
        cout << happyDays << endl;
    }
}