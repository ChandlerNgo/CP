#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    while(n != 0){
        int pile1 = 0;
        int pile2 = 0;
        while(n--){
            string command;
            int amount;
            cin >> command >> amount;
            if(command == "DROP"){
                // drop on empty table and switch tables
                cout << "DROP 2 " << amount << endl;
                pile2 += amount;
            }else{
                if(pile1 >= amount){
                    cout << "TAKE 1 " << amount << endl;
                    pile1 -= amount;
                }else{
                    if(pile1 == 0){
                        cout << "MOVE 2->1 " << pile2 << endl;
                        pile1 = pile2;
                        pile2 = 0;
                        cout << "TAKE 1 " << amount << endl;
                        pile1 -= amount;
                    }else{
                        int temp = pile1;
                        cout << "TAKE 1 " << pile1 << endl;
                        pile1 -= pile1;
                        cout << "MOVE 2->1 " << pile2 << endl;
                        pile1 = pile2;
                        pile2 = 0;
                        cout << "TAKE 1 " << amount-temp << endl;
                        pile1 -= amount-temp;
                    }
                }
            }
        }
        cin >> n;
        if(n != 0){
            cout << endl;
        }
    }
}