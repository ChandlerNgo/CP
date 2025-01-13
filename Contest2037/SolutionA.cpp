#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for(int p = 0; p < t; p++){
        int n;
        cin >> n;
        map<int,int> numbers;
        for(int i = 0; i < n; i++){
            int num;
            cin >> num;
            if(numbers.find(num) == numbers.end()){
                numbers[num] = 1;
            }else{
                numbers[num] += 1;
            }
        }
        int total = 0;
        for(auto i = numbers.begin(); i != numbers.end(); i++){
            total += (i->second/2);
        }
        cout << total << endl;
    }
}