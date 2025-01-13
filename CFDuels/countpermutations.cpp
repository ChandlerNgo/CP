#include <iostream>

using namespace std;

int main(){
    long long n;
    cin >> n;

    for(int i = 0; i < n; i++){
        long long number;
        cin >> number;

        long long result = 1;
        for(int i = 3; i <= number*2; i++){
            result *= i;
            result =  result % 1000000007;
        }
        cout << result % 1000000007 << "\n";
    }
}