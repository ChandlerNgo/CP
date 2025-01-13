#include <iostream>
#include <vector>

using namespace std;

int main(){
    long long tests;
    cin >> tests;
    for(int i = 0; i < tests; i++){
        long long logAmount;
        cin >> logAmount;
        long long chops = 0;
        for(long long j = 0; j < logAmount; j++){
            long long log;
            cin >> log;
            chops += ((log-1) % 2);
        }
        if(chops % 2 == 0){
            cout << "maomao90\n";
        }else{
            cout << "errorgorn\n";
        }
    }
    // odd number of chops is errorgorn
    // even number of chops is maomao90
}