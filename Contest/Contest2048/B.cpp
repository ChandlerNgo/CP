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
        int k;
        cin >> n >> k;
        vector<int> numbers(n+1, 0);
        int num = 1;
        int numDown = n;
        for(int i = 1; i <= n; i++){
            if(i % k == 0){
                numbers[i] = num;
                num += 1;
            }else{
                numbers[i] = numDown;
                numDown -= 1;
            }
        }
        for(int i = 1; i <= n; i++){
            cout << numbers[i] << ' ';
        }
        cout << '\n';
    }
}