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

    bool beautiful = true;

    for(auto itr = letters.begin(); itr != letters.end(); itr++){
        if(itr->second % 2 == 1){
            beautiful = false;
            break;
        }
    }

    if(beautiful){
        cout << "Yes\n";
    }else{
        cout << "No\n";
    }
}