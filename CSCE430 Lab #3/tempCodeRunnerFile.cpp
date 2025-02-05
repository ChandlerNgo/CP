#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
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
        bool found = true;
        int factor = numbers[1]-numbers[0];
        for(int i = 1; i < n-1; i++){
            if(factor != numbers[i+1]-numbers[i]){
                found = false;
            }
        }

        if(found){
            cout << "arithmetic" << endl;
            continue;
        }

        sort(numbers.begin(),numbers.end());

        factor = numbers[1]-numbers[0];
        for(int i = 1; i < n-1; i++){
            if(factor != numbers[i+1]-numbers[i]){
                found = false;
            }
        }

        if(found){
            cout << "permuted arithmetic" << endl;
        }else{
            cout << "non-arithmetic" << endl;
        }

    }
}