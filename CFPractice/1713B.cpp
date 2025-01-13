#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for(int k = 0; k < t; k++){
        int n;
        cin >> n;
        vector<int> nums(n);
        for(int i = 0; i < n; i++){
            int num;
            cin >> num;
            nums[i] = num;
        }
        int found = 0;
        for(int i = 1; i < n-1; i++){
            if((nums[i] < nums[i+1] && nums[i] < nums[i-1]) || (nums[i] > nums[i+1] && nums[i] > nums[i-1])){
                found += 1;
            }
        }
        if(found > 1){
            cout << "NO" << endl;
        }else{
            cout << "YES" << endl;
        }
    }
}