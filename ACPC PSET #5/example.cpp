#include <bits/stdc++.h>
typedef long long ll;
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
    sort(numbers.begin(), numbers.end());

    int q;
    cin >> q;
    for(int i = 0; i < q; i++){
        int query;
        cin >> query;

        int l = 0;
        int r = n-1;
        while(l <= r){
            int m = (r + l)/2;
            if(numbers[m] <= query){
                l = m + 1;
            }else{
                r = m - 1;
            }
        }
        cout << l << endl;
    }
}