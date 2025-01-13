#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;

    cin >> n;

    for(int i = 0; i < n; i++){
        string word;
        cin >> word;
        if(word.size() > 10){
            cout << word[0] << word.size()-2 << word[word.size()-1] << endl;
        }else{
            cout << word << endl;
        }
    }
}