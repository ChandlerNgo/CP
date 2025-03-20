#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int num1;
    char slash;
    int num2;
    while(cin >> num1 >> slash >> num2){
        int num = num2;
        int target = num*num;
        int total = 0;

        if(num1 == num2){
            cout << "1" << endl;
            continue;
        }

        set<pair<int,int>> pairs;

        for(int i = 1; i <= num; i++){
            if(target % i == 0){
                int a = i;
                int b = target/i;
                if(b < a){
                    swap(a,b);
                }
                if(pairs.find({a,b}) == pairs.end()){
                    pairs.insert({a,b});
                    total += 1;
                }
            }
        }
        
        cout << total << endl;
    }
}