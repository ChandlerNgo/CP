using namespace std;
#include <iostream>

int main(){
    long long n;
    cin >> n;
    
    long long trailingZeros = 0;
    while(n != 0){
        trailingZeros += n/5;
        n = n/5;
    }

    cout << trailingZeros << endl;

    return 0;
}