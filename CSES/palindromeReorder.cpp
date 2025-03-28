#include <iostream>
#include <map>

using namespace std;

int main(){
    string w;
    cin >> w;

    map<char,int> letters;

    for(int i = 0; i < w.size(); i++){
        if(letters.find(w[i]) == letters.end()){
            letters[w[i]] = 1;
        }else{
            letters[w[i]] += 1;
        }
    }

    char oddLetter = ' ';

    for(auto itr = letters.begin(); itr != letters.end(); itr++){
        if(itr->second % 2 == 1){
            if(oddLetter != ' '){
                cout << "NO SOLUTION\n";
                return 0;
            }else{
                oddLetter = itr->first;
            }
        }
    }

    
    string left;
    for(auto x: letters){
        if(x.first != oddLetter){
            left += string((x.second/2),x.first);
        }
    }
    cout << left;
    string a = string(letters[oddLetter],oddLetter);
    cout << a;
    for(int i = left.size()-1; i >= 0; i--){
        cout << left[i];
    }

    cout << endl;
    return 0;
}