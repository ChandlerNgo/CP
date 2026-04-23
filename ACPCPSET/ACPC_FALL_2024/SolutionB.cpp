#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    bool isFlipped = false;
    int answer = 0;
    for(int i = 0; i < n; i++){
        string val;
        cin >> val;
        bool cur;
        if(val == "OFF"){
            cur = false;
        }else{
            cur = true;
        }
        if(isFlipped){
            cur = !cur;
        }

        if(!cur){
            isFlipped = !isFlipped;
            answer += 1;
        }
    }
    cout << answer << endl;
}