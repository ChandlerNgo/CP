#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){

    // y > x bottom left
    // y == x diagonal
    // y < x top right

    long long tests;
    cin >> tests;

    for(long long i = 0; i < tests; i++){
        long long y;
        long long x;
        cin >> y >> x;
        if(y > x){
            long long innerSquare = (y - 1) * (y - 1);
            // lesser values to the left
            if(y % 2 == 0){
                cout << innerSquare + (2 * y) - x << endl;
            }else{
                // greated values to the left
                cout << innerSquare + x << endl;
            }
        }else{
            long long innerSquare = (x - 1) * (x - 1);
            if(x % 2 == 0){
                cout << innerSquare + y << endl;
            }else{
                cout << innerSquare + (2 * x) - y << endl;
            }
        }
    }


    return 0;
}