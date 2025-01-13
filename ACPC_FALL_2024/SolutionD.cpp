#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    int k;
    cin >> n >> k;

    int i = 1;
    int time = 0;
    while(i < k){
        i += min(i,k);
        time += 1;
    }
    n -= i;
    time += (n+k-1)/k;
    cout << time << endl;
}