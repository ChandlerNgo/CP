#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(){
    long long tests;
    cin >> tests;
    
    for(int i = 0; i < tests; i++){
        long long blocks;
        cin >> blocks;
        long long max = -1;
        long long perimeter = 0;
        for(int j = 0; j < blocks; j++){
            long long a;
            long long b;
            cin >> a >> b;
            if(b > a){
                long long tmp = a;
                a = b;
                b = tmp;
            }
            if(max == -1){
                max = a;
                perimeter = (a * 2) + (b * 2);
            }else{
                if(a > max){
                    perimeter += (2*(a-max));
                    max = a;
                }
                perimeter += (2*b);
            }
        }
        cout << perimeter << endl;
    }


    return 0;
}