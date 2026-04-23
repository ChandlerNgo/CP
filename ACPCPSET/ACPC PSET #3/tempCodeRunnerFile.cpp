#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int length;
    int queries;
    cin >> length >> queries;
    string word;
    cin >> word;

    vector<int> prefixSum;
    prefixSum.push_back(0);
    prefixSum.push_back(0);
    for(int i = 1; i < length; i++){
        if(word[i] == word[i-1]){
            prefixSum.push_back(prefixSum[i]+1);
        }else{
            prefixSum.push_back(prefixSum[i]);
        }
    }

    for(int i = 0; i < queries; i++){
        int l;
        int r;
        cin >> l >> r;
        cout << prefixSum[r] - prefixSum[l-1] << endl;
    }
}