#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> left;
    vector<int> right;
    for(int i = 0; i < n; i++){
        char hand;
        int val;
        cin >> val >> hand;
        if(hand == 'L'){
            left.push_back(val);
        }else{
            right.push_back(val);
        }
    }

    int energy = 0;
    for(int i = 1; i < left.size(); i++){
        energy += abs(left[i] - left[i-1]);
    }
    for(int i = 1; i < right.size(); i++){
        energy += abs(right[i] - right[i-1]);
    }
    cout << energy << endl;
}