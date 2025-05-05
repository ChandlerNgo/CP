#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    int q;
    cin >> n >> q;
    vector<int> stacks;
    vector<char> product;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        stacks.push_back(num);
    }
    for(int i = 0; i < n; i++){
        char num;
        cin >> num;
        product.push_back(num);
    }

    for(int k = 0; k < q; k++){
        int action;
        int l,r;
        cin >> action >> l >> r;
        l -= 1;
        r -= 1;
        if(action <= 2){
            vector<pair<int,char>> corn;
            vector<pair<int,char>> wheat;
            for(int i = l; i <= r; i++){
                if(product[i] == 'C'){
                    corn.push_back({stacks[i],product[i]});
                }else{
                    wheat.push_back({stacks[i],product[i]});
                }
                // 1 is corn first
                int index = l;
                if(action == 1){
                    for(int j = 0; j < corn.size(); j++){
                        stacks[index] = corn[j].first;
                        product[index] = corn[j].second;
                        index += 1;
                    }
                    for(int j = 0; j < wheat.size(); j++){
                        stacks[index] = wheat[j].first;
                        product[index] = wheat[j].second;
                        index += 1;
                    }
                }else{
                    // 2 is wheat first
                    for(int j = 0; j < wheat.size(); j++){
                        stacks[index] = wheat[j].first;
                        product[index] = wheat[j].second;
                        index += 1;
                    }
                    for(int j = 0; j < corn.size(); j++){
                        stacks[index] = corn[j].first;
                        product[index] = corn[j].second;
                        index += 1;
                    }
                }
            }
        }else{
            // 3 is seg tree
            int sum = 0;
            for(int i = l; i <= r; i++){
                sum += stacks[i];
            }
            cout << sum << "\n";
        }
    }
    cout << flush;
}