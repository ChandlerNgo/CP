#include <iostream>

using namespace std;

int main(){
    int tests;
    cin >> tests;

    for(int i = 0; i < tests;i++){
        int a;
        int b;
        cin >> a >> b;
        int minVal = b - a;
        for(int curC = a+1; curC <= b; curC++){
            int sum = (curC-a) + (b-curC);
            if(sum < minVal){
                minVal = sum;
            }
        }
        cout << minVal << "\n";
    }
    return 0;
}