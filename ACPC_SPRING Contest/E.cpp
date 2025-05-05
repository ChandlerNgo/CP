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

    vector<pair<int,int>> difference;

    for(int i = 0; i < n; i++){
        int left = 0;
        int right = 0;
        for(int j = 0; j < i; j++){
            left += numbers[j];
        }
        for(int j = i+1; j < n; j++){
            right += numbers[j];
        }
        difference.push_back({left,right});
    }

    for(auto x : difference){
        cout << x.first << " " << x.second << endl;
    }
}