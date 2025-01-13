#include <iostream>

using namespace std;

int main(){
    long long t;
    cin >> t;
    for(long long i = 0; i < t; i++){
        long long n;
        cin >> n;
        long long positive;
        long long negative;
        long long sum = 0;
        for(long long j = 0; j < n;j++){
            long long num;
            cin >> num;
            if(num % 2 == 0){
                if(num < 0){
                    if(negative == NULL){
                        negative = num;
                    }else{
                        negative = max(num,negative);
                    }
                }else{
                    sum += num;
                }
            }else{
                if(num > 0){
                    sum += num;
                    if(positive == NULL){
                        positive = num;
                    }else{
                        positive = min(num,positive);
                    }
                }
            }
        }
        sum = min(sum-positive,sum + negative);
        cout << sum << endl;
    }
    return 0;
}