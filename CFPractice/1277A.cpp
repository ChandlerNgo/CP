#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        string num;
        cin >> num;
        int lowest = 0;
        int highest = static_cast<int>(num[0]-'0');
        bool printed = false;
        for(int j = 1; j < num.size(); j++){
            if(static_cast<int>(num[j]-'0') > highest){
                cout << ((num.size()-1) * 9) + highest << endl;
                printed = true;
                break;
            }else if(static_cast<int>(num[j]-'0') < highest){
                cout << ((num.size()-1) * 9) + (highest - 1) << endl;
                printed = true;
                break;
            }
        }
        if(!printed){
            cout << ((num.size()-1) * 9) + highest << endl;
        }
    }
}