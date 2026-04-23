#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n; // rows
        int m; // columns
        cin >> n >> m;
        vector<string> numbers;
        for(int i = 0; i < n; i++){
            string s;
            cin >> s;
            numbers.push_back(s);
        }
        int sequences = 0;
        int x1 = 0;
        int x2 = m-1;
        int y1 = 0;
        int y2 = n-1;
        while(x1 < x2 && y1 < y2){
            string currentString = "";
            for(int x = x1; x <= x2; x++){
                currentString += numbers[y1][x];
            }

            for(int y = y1+1; y <= y2; y++){
                currentString += numbers[y][x2];
            }

            for(int x = x2 - 1; x >= x1; x--){
                currentString += numbers[y2][x];
            }

            for(int y = y2 - 1; y >= y1+1; y--){
                currentString += numbers[y][x1];
            }

            // all numbers in the wheel
            for(int i = 0; i < currentString.size(); i++){
                if(currentString[i] == '1' && currentString[(i+1) % currentString.size()] == '5' && currentString[(i+2) % currentString.size()] == '4' && currentString[(i+3) % currentString.size()] == '3'){
                    sequences += 1;
                }
            }
            x1 += 1;
            x2 -= 1;
            y1 += 1;
            y2 -= 1;
        }
        cout << sequences << endl;
    }
}