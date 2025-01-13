#include <iostream>

using namespace std;

int main(){
    int tests;
    cin >> tests;

    for(int i = 0; i < tests; i++){
        int count;
        cin >> count;
        long long sum = 0;
        for(int j = 0; j < count; j++){
            int num;
            cin >> num;
            if(j % 2 == 0){
                sum += num;
            }else{
                sum -= num;
            }
        }
        cout << sum << "\n";
    }
    return 0;
}