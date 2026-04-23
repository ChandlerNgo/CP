#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;

    if(n <= 2){
        cout << n << endl;
        return 0;
    }
    deque<int> numbers;
    int maxGood = 2;
    int currentGood = 0;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        numbers.push_back(num);
        currentGood += 1;
        if(numbers.size() > 2){
            int first = numbers.front();
            numbers.pop_front();
            int second = numbers.front();
            if(first+second != num){
                maxGood = max(maxGood,currentGood-1);
                currentGood = 0;
            }
        }
    }
    cout << max(maxGood,currentGood) << endl;
}