#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for(int k = 0; k < t; k++){
        int n;
        cin >> n;
        vector<int> numbers(2);
        string perfect = "yes\n";
        cin >> numbers[0];
        for(int i = 1; i < n; i++){
            cin >> numbers[1];
            if(abs(numbers[0]-numbers[1]) != 5 && abs(numbers[0]-numbers[1]) != 7){
                perfect = "no\n";
            }
            numbers[0] = numbers[1];
        }
        cout << perfect;
    }
}