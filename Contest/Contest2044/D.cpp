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
        set<int> numbers;
        for(int i = 1; i <= n; i++){
            numbers.insert(i);
        }
        for (int i = 0; i < n; i++){
            int num;
            cin >> num;
            if(numbers.find(num) != numbers.end()){
                numbers.erase(num);
                cout << num << ' ';
            }else{
                int curNum = *numbers.begin();
                cout << curNum << ' ';
                numbers.erase(curNum);
            }
        }
        cout << '\n';
    } 
}