#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a; // mean
    int b; // median
    cin >> a >> b;

    int currentSum = b + 500;
    int currentMean = 3*a;

    cout << 3 << endl;
    cout << b << " " << 500 << " " << currentMean - currentSum << endl;
}

