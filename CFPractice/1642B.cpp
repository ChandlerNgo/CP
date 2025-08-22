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
        map<int,int> nums;
        for(int i = 0; i < n; i++){
            int num;
            cin >> num;
            nums[num] += 1;
        }

        for(int i = 1; i <= n; i++){
            cout << max(i,(int)nums.size()) << " ";
        }
        cout << endl;
    }
}