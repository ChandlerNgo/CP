#include <iostream>

using namespace std;

int main(){
    long long n;
    cin >> n;
    for(long long i = 1; i <= n; i++){
        cout << ((i * i) * ((i * i) - 1)/2) - (4 * (i-1) * (i-2)) << endl;
        // total knight spots - total knight attacking spots
        // total knight attacking spots are found by finding the amount of 2x3 and 3x2 boxes
        // they each have 4 knights
    }
    return 0;
}