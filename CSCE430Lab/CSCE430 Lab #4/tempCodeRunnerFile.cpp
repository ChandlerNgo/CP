#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int r; int c;
    cin >> r >> c;
    vector<int> eastern;
    vector<int> northern;
    for(int i = 0; i < r; i++){
        int num;
        cin >> num;
        eastern.push_back(num);
    }
    for(int i = 0; i < c; i++){
        int num;
        cin >> num;
        northern.push_back(num);
    }

    sort(eastern.begin(),eastern.end());
    sort(northern.begin(),northern.end());

    if(eastern == northern){
        cout << "possible" << endl;
    }else{
        cout << "impossible" << endl;
    }
}