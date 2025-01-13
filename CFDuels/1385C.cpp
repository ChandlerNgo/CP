#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int count;
        cin >> count;

        vector<int> currentNumbers;
        for(int j = 0; j < count; j++){
            int num;
            cin >> num;
            currentNumbers.push_back(num);
        }
        int currentMax = 0;
        bool goingDown = false;
        int j;
        for(j = currentNumbers.size()-1; j >= 0; j--){
            if(goingDown){
                if(currentNumbers[j] <= currentMax){
                    currentMax = currentNumbers[j];
                }else{
                    cout << (j+1) << endl;
                    break;
                }
            }else{
                if(currentNumbers[j] >= currentMax){
                    currentMax = currentNumbers[j];
                }else{
                    goingDown = true;
                    currentMax = currentNumbers[j];
                }
            }
            if(j == 0){
                cout << 0 << endl;
            }
        }
    }
}