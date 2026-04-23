#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

auto cmp = [](const bitset<10>& a, const bitset<10>& b) {
    return a.to_ulong() < b.to_ulong();
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<bitset<10>> numbers;
    set<bitset<10>, decltype(cmp)> seen(cmp);
    numbers.push_back(0);
    numbers.push_back(3);
    seen.insert(0);
    seen.insert(3);

    
    for(int i = 2; i <= 500; i++){
        vector<bitset<10>> codes;
        for(int j = 0; j < 10; j++){
            for(int k = j+1; k < 10; k++){
                bitset<10> bs = numbers[i-1];
                bs.flip(j);
                bs.flip(k);
                if(seen.find(bs) == seen.end()){
                    codes.push_back(bs);
                }
            }
        }
        sort(codes.begin(), codes.end(), [](const bitset<10>& a, const bitset<10>& b) {
            return a.to_ulong() < b.to_ulong();
        });
        for(int i = 0; i < codes.size(); i++){
            if(seen.find(codes[i]) == seen.end()){
                numbers.push_back(codes[i]);
                seen.insert(codes[i]);
                break;
            }
        }
    }

    for(int i = 0; i < 12; i++){
        cout << numbers[i] << endl;
    }

    int n;
    cin >> n;

    while(n--){
        int val;
        cin >> val;
        cout << numbers[val] << endl;
    }

}