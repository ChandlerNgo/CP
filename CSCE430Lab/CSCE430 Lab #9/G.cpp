#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> numbers(16,0);
    numbers[0] = 2;
    numbers[1] = 3;
    numbers[2] = 5;
    for(int i = 3; i <= 15; i++){
        numbers[i] = (numbers[i-1]*2)-1;
    }

    cout << numbers[n]*numbers[n] << endl;
}