#include <iostream>

using namespace std;

int main(){
    int tests;
    cin >> tests;

    for(int i = 0; i < tests; i++){
        for(int j = 0; j < 3; j++){
            string row;
            cin >> row;
            
            int aFound = row.find('A');
            int bFound = row.find('B');
            int cFound = row.find('C');
            if(aFound == string::npos){
                cout << 'A' << endl;
            }else if(bFound == string::npos){
                cout << 'B' << endl;
            }else if(cFound == string::npos){
                cout << 'C' << endl;
            }
        }
    }

    return 0;
}