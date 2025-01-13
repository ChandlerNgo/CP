#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    vector<int> numbers(51);
    numbers[0] = -1;
    for(int i = 1; i <= 50; i++){
        numbers[i] = numbers[i-1]+2;
    }

    while(t--){
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++){
            cout << numbers[i] << " ";
        }
        cout << endl;
    }
}