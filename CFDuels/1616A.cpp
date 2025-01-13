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
        set<int> currentNumbers;
        for(int j = 0; j < count; j++){
            int num;
            cin >> num;
            if(currentNumbers.find(num) == currentNumbers.end()){
                currentNumbers.insert(num);
            }else if(currentNumbers.find(-1 * num) == currentNumbers.end()){
                currentNumbers.insert(-1 * num);
            }
        }
        cout << currentNumbers.size() << endl;
    }
}