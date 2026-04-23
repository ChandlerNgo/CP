#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int val;
    cin >> val;
    map<pair<int,int>, int> cubes;
    map<int, int> amount;
    int maxNum = INT_MIN;
    for(int i = 1; i <= 80; i++){
        for(int j = i+1; j <= 80; j++){
            int cubeVal = i*i*i + j*j*j;
            cubes[{i,j}] = cubeVal;
            amount[cubeVal] += 1;
            if(cubeVal <= val && cubeVal > maxNum && amount[cubeVal] >= 2){
                maxNum = cubeVal;
            }
        }
    }

    cout << (maxNum == INT_MIN ? "none" : to_string(maxNum)) << endl;
}