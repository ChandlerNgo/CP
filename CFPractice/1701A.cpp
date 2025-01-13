#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        vector<int> numbers;
        int count = 0;
        for(int j = 0; j < 4; j++){
            int num;
            cin >> num;
            if(num == 1){
                count += 1;
            }
            numbers.push_back(num);
        }
        // 23 14
        if(count == 4){
            cout << 2 << endl;
        }else if(count < 4 && count > 0){
            cout << 1 << endl;
        }else{
            cout << 0 << endl;
        }
    }
}