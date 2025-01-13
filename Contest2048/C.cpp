#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        // find first 0, find largest xor with size of th rest
        int index = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[index] == '0'){
                break;
            }
            index += 1;
        }
        int ones = index;
        int zeros = 0;
        int j = index;
        while(zeros < ones && j < s.size()){
            if(s[j] == '0'){
                zeros++;
                j++;
            }else{
                break;
            }
        }
        if(index >= s.size()){
            // no 0s
            cout << 1 << " " << s.size() << " " << 1 << " " << 1 << "\n";
        }else{
            cout << 1 << " " << s.size() << " " << index - min(zeros,ones) + 1 << " " << index - min(zeros,ones)  + (s.size() - index) << "\n";
        }
    }
}