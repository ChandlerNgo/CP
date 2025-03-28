#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;

    vector<string> grayCode;
    grayCode.push_back("0");
    grayCode.push_back("1");

    for(int i = 1; i < n; i++){
        int s = grayCode.size()-1;
        for(; s >= 0; s--){
            grayCode.push_back(grayCode[s]);
        }

        for(int j = 0; j < grayCode.size(); j++){
            if(j < (grayCode.size()/2)){
                grayCode[j] = "0" + grayCode[j];
            }else{
                grayCode[j] = "1" + grayCode[j];
            }
        }
    }

    for(auto x : grayCode){
        cout << x << endl;
    }
}