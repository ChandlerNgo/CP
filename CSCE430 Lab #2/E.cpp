#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int year;
    cin >> year;
    int currentYear = 2018;
    int month = 3;
    while(currentYear < year){
        month += 26;
        currentYear += (month/12);
        month = month % 12;
    }

    if(year == currentYear){
        cout << "yes" << endl;
    }else{
        cout << "no" << endl;
    }
}