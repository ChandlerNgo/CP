#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> numbers(6,0);
    for(int i = 0; i < 4; i++){
        int num;
        cin >> num;
        numbers[num] = 1;
    }

    for(int i = 1; i <= 5; i++){
        if(numbers[i] == 0){
            cout << i << endl;
            break;
        }
    }
}