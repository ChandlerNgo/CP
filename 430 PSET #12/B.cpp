#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> numbers;

    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        numbers.push_back(num);
    }

    vector<int> current;

    for(auto x : numbers){
        auto it = lower_bound(current.begin(), current.end(), x, greater<int>());

        if(it == current.end()){
            current.push_back(x);
        }else{
            *it = x;
        }
    }

    cout << current.size() << endl;
}