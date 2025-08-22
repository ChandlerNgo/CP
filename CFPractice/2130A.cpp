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

        int score = 0;

        if(nums.find(0) != nums.end() && nums.find(1) != nums.end()){
            score += (2*min(nums[0],nums[1]));
            nums[1] = max(0, nums[1]-(score/2));
            nums[0] = max(0, nums[0]-(score/2));
        }
        if(nums.find(0) != nums.end()){
            score += nums[0];
            nums.erase(0);
        }

        for(auto num : nums){
            score += num.first*num.second;
        }
        cout << score << "\n";
    }   
}