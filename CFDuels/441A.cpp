#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int sellers;
    int amount;
    cin >> sellers >> amount;
    vector<int> boughtItems;
    for(int i = 0; i < sellers; i++){
        int sales;
        cin >> sales;
        bool found = false;
        for(int j = 0; j < sales; j++){
            int num;
            cin >> num;
            if(amount > num){
                found = true;
            }
        }
        if(found){
            boughtItems.push_back(i + 1);
        }
    }

    cout << boughtItems.size() << endl;
    for(int i = 0; i < boughtItems.size(); i++){
        cout << boughtItems[i] << " ";
    }

    cout << endl;

}