#include <bits/stdc++.h>

using namespace std;

long long summation(long long top, long long bottom){
    return top*(top+1)/2 - bottom*(bottom+1)/2;
}

int main(){
    // find how many times x & y pass the same element within n
    int t;
    cin >> t;


    for(int i = 0; i < t; i++){
        long long n;
        long long x;
        long long y;
        cin >> n >> x >> y;
        
        long long xAmt = n/x;
        long long yAmt = n/y;
        long long LCMAmt = n/lcm(x,y);
        xAmt = max((long long)0, xAmt-LCMAmt);
        yAmt = max((long long)0, yAmt-LCMAmt);
        
        // x is the higher numbers
        // y is the lower numbers
        // x - y
        long long xTotal = summation(n,n-xAmt);
        long long yTotal = summation(yAmt,0);
        
        cout << xTotal - yTotal << endl;
    }
}
