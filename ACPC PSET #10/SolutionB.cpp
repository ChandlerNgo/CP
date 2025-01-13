#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    int upperCase = 0;
    int lowerCase = 0;

    for(int i = 0; i < s.size(); i++){
        if(isupper(s[i])){
            upperCase += 1;
        }else{
            lowerCase += 1;
        }
    }

    if(upperCase > lowerCase){
        transform(s.begin(), s.end(), s.begin(), ::toupper);
        cout << s << endl;
    }else{
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        cout << s << endl;
    }
}