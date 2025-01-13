#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> numbers;
        for(int i = 0; i < n; i++){
            int num;
            cin >> num;
            numbers.push_back(num);
        }

        int curMin = INT_MAX;
        for(int i = 0; i < n; i++){
            int numbersGreater = 0;
            for(int j = i + 1; j < n; j++){
                if(numbers[j] > numbers[i]){
                    numbersGreater += 1;
                }
            }
            curMin = min(curMin, numbersGreater+i);
        }
        cout << curMin << endl;
    }
}