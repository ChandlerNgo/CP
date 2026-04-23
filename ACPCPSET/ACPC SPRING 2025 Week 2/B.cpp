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
        for(int i = 0 ; i < n; i++){
            int num;
            cin >> num;
            numbers.push_back(num);
        }

        int firstIndex = 0;
        int lastIndex = n-1;

        while(firstIndex <= n-1 && numbers[firstIndex] == 0){
            firstIndex += 1;
        }
        while(lastIndex >= 0 && numbers[lastIndex] == 0){
            lastIndex -= 1;
        }

        if(firstIndex > lastIndex){
            cout << 0 << endl;
        }else if(firstIndex == lastIndex){
            cout << 1 << endl;
        }else{
            bool found = false;
            for(int i = firstIndex; i <= lastIndex; i++){
                if(numbers[i] == 0){
                    found = true;
                }
            }
            if(found){
                cout << 2 << endl;
            }else{
                cout << 1 << endl;
            }
        }
    }
}