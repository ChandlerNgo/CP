#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int n;
        cin >> n;
        map<int,int> numbers;
        for(int j = 0; j < n; j++){
            int num;
            cin >> num;
            if(numbers.find(num) == numbers.end()){
                numbers[num] = 1;
            }else{
                numbers[num] += 1;
            }
        }
        bool found = false;

        for(int j = 1; j <= n; j++){
            for(int k = j; k <= n; k++){
                if(j * k == (n-2) && numbers.find(j) != numbers.end() && numbers.find(k) != numbers.end()){
                    cout << j << " " << k << endl;
                    found = true;
                    break;
                }
            }
            if(found){
                break;
            }
        }
    }   
}