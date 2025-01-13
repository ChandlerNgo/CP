#include <iostream>

using namespace std;

int main(){
    long long tests;
    cin >> tests;
    for(long long i = 0; i < tests; i++){
        long long nums;
        cin >> nums;
        for(long long j = 0; j < nums; j++){
            long long num;
            cin >> num;
            cout << nums-num+1 << " ";
        }
        cout << "\n";
    }
}