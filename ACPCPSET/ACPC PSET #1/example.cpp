#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        string word;
        cin >> word;
        vector<int> lowercase;
        vector<int> uppercase;
        for(int i = 0; i < word.size(); i++){
            if(word[i] == 'b' && lowercase.size() != 0){
                word[lowercase[lowercase.size()-1]] = '0';
                lowercase.pop_back();
            }else if(word[i] == 'B' && uppercase.size() != 0){
                word[uppercase[uppercase.size()-1]] = '0';
                uppercase.pop_back();
            }else{
                if(islower(word[i])){
                    lowercase.push_back(i);
                }else{
                    uppercase.push_back(i);
                }
            }
        }
        for(int i = 0; i < word.size(); i++){
            if(word[i] != '0' && word[i] != 'b' && word[i] != 'B'){
                cout << word[i];
            }
        }
        cout << '\n';
    }
    return 0;
}