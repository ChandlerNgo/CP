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
        vector<pair<int,int>> numbers;
        for(int j = 0; j < n; j++){
            int a;
            int b;
            cin >> a >> b;
            numbers.push_back({a,b});
        }

        sort(numbers.begin(), numbers.end());

        for(int j = 0; j < n; j++){
            cout << numbers[j].first << " " << numbers[j].second << " ";
        }
        cout << endl;
    }
}