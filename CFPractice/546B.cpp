#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    map<int,int> numbers;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        if(numbers.find(num) == numbers.end()){
            numbers[num] = 1;
        }else{
            numbers[num] += 1;
        }
    }

    int coins = 0;

    for(int i = 1; i <= 2*n+1; i++){
        if(numbers.find(i) != numbers.end()){
            if(numbers[i] > 1){
                if(numbers.find(i+1) == numbers.end()){
                    numbers[i+1] = numbers[i]-1;
                }else{
                    numbers[i+1] += numbers[i]-1;
                }
                coins += numbers[i]-1;
                numbers[i] = 1;
            }
        }
    }
    cout << coins << endl;
}