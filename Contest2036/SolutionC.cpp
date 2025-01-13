#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for(int l = 0; l < t; l++){
        string s;
        int q;
        cin >> s >> q;

        int sequences = 0;

        for(int i = 0; i < s.size()-3; i++){
            if(s[i] == '1' && s[i+1] == '1' && s[i+2] == '0' && s[i+3] == '0'){
                sequences += 1;
            }
        }

        for(int i = 0; i < q; i++){
            int index;
            char value;
            cin >> index >> value;
            // found amount in original string vs new string
            // look at the left 3 indexes and right 3 indexes

            int original = 0;
            
            for(int j = max(index-4,0); j < index; j++){
                if(s[j] == '1' && s[j+1] == '1' && s[j+2] == '0' && s[j+3] == '0'){
                    original += 1;
                }
            }

            s[index-1] = value;

            int newSequences = 0;

            for(int j = max(index-4,0); j < index; j++){
                if(s[j] == '1' && s[j+1] == '1' && s[j+2] == '0' && s[j+3] == '0'){
                    newSequences += 1;
                }
            }

            sequences += (newSequences - original);

            if(sequences == 0){
                cout << "no" << endl;
            }else{
                cout << "yes" << endl;
            }
        }
    }
}