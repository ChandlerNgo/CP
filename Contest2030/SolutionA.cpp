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
        vector<int> minimum;
        vector<int> numbers;
        vector<int> maximum;
        int curMin = INT_MAX;
        int curMax = INT_MIN;
        for(int j = 0; j < n; j++){
            int num; cin >> num;
            numbers.push_back(num);
        }
        sort(numbers.begin(),numbers.end());
        
        curMin = min(curMin,numbers[n-1]);
        curMax = max(curMax,numbers[n-1]);
        minimum.push_back(curMin);
        maximum.push_back(curMax);
        for(int j = 0; j < n-1; j++){
            int num = numbers[j];
            curMin = min(curMin,num);
            curMax = max(curMax,num);
            minimum.push_back(curMin);
            maximum.push_back(curMax);
        }
        int score = 0;
        for(int j = 0; j < n; j++){
            score += (maximum[j] - minimum[j]);
        }
        cout << score << endl;
    }
}