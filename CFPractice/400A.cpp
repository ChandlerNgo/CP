#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    vector<int> factors = {12,6,4,3,2,1};
    vector<string> stringFactors = {"1x12","2x6","3x4","4x3","6x2","12x1"};
    for(int i = 1; i <= t; i++){
        string row;
        cin >> row;

        vector<bool> foundFactors = {false,false,false,false,false,false};

        int curFactor = 0;
        for(int j = 0; j < factors.size(); j++){
            for(int l = 0; l < factors[j];l++){
                bool found = true;
                for(int k = l; k < row.size();k += factors[j]){
                    if(row[k] != 'X'){
                        found = false;
                        break;
                    }
                }
                if(found){
                    foundFactors[j] = true;
                    curFactor += 1;
                    break;
                }
            }
        }
        
        cout << curFactor << " ";
        for(int j = 0; j < foundFactors.size();j++){
            if(foundFactors[j]){
                cout << stringFactors[j] << " ";
            }
        }
        cout << "\n";
    }
}

/*
1x12
OXXXOXOOXOOX

2x6
OXXXOX
OOXOOX

3x4
OXXX
OXOO
XOOX

4x3
OXX
XOX
OOX
OOX

6x2
OX
XX
OX
OO
XO
OX

12x1
O
X
X
X
O
X
O
O
X
O
O
X

*/