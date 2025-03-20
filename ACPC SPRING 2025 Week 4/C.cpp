#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> numbers(n+1,0);
    for(int i = 1; i <= n; i++){
        int num;
        cin >> num;
        numbers[i] = num;
    }

    bool done = false;
    for(int i = 1; i <= n; i++){
        int curVal = numbers[i];
        for(int j = 0; j < 2; j++){
            curVal = numbers[curVal];
        }
        if(curVal == i){
            done = true;
            break;
        }
    }
    if(done){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
}