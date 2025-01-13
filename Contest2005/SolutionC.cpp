#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(){

    int tests;
    cin >> tests;
    for(int i = 0;i < tests;i++){
        int n;
        int m;
        cin >> n >> m;
        vector<string> words;
        for(int j = 0; j < n; j++){
            string word;
            cin >> word;
            words.push_back(word);
        }
        size_t maxScore = 0;
        for(int j = 0; j < n; j++){
            for(int k = j+1; k < n; k++){
                size_t curScore = 0;
                set<char> narek;
                size_t letters = 0;
                string curWord = words[j] + words[k];
                for(int l = 0; l < curWord.size();l++){
                    if(narek.size() == 5){
                        curScore += 5;
                        narek.clear();
                    }

                    if(curWord[l] == 'n'){
                        if(narek.find('n') != narek.end()){
                            letters += 1;
                        }
                        narek.insert('n');
                    }
                    if(curWord[l] == 'a'){
                        if(narek.find('a') != narek.end()){
                            letters += 1;
                        }
                        narek.insert('a');
                    }
                    if(curWord[l] == 'r'){
                        if(narek.find('r') != narek.end()){
                            letters += 1;
                        }
                        narek.insert('r');
                    }
                    if(curWord[l] == 'e'){
                        if(narek.find('e') != narek.end()){
                            letters += 1;
                        }
                        narek.insert('e');
                    }
                    if(curWord[l] == 'k'){
                        if(narek.find('k') != narek.end()){
                            letters += 1;
                        }
                        narek.insert('k');
                    }
                }

                if(narek.size() == 5){
                    curScore += 5;
                    narek.clear();
                }

                if(letters < curScore){
                    maxScore = max(maxScore,curScore-letters-narek.size());
                }
            }
        }
        for(int k = 0; k < n; k++){
            size_t curScore = 0;
            set<char> narek;
            size_t letters = 0;
            string curWord = words[k];
            for(int l = 0; l < curWord.size();l++){

                if(narek.size() == 5){
                    curScore += 5;
                    narek.clear();
                }

                if(curWord[l] == 'n'){
                    if(narek.find('n') != narek.end()){
                        letters += 1;
                    }
                    narek.insert('n');
                }
                if(curWord[l] == 'a'){
                    if(narek.find('a') != narek.end()){
                        letters += 1;
                    }
                    narek.insert('a');
                }
                if(curWord[l] == 'r'){
                    if(narek.find('r') != narek.end()){
                        letters += 1;
                    }
                    narek.insert('r');
                }
                if(curWord[l] == 'e'){
                    if(narek.find('e') != narek.end()){
                        letters += 1;
                    }
                    narek.insert('e');
                }
                if(curWord[l] == 'k'){
                    if(narek.find('k') != narek.end()){
                        letters += 1;
                    }
                    narek.insert('k');
                }
                
            }

            if(narek.size() == 5){
                curScore += 5;
                narek.clear();
            }

            if(letters < curScore){
                maxScore = max(maxScore,curScore-letters-narek.size());
            }
        }
        cout << maxScore << endl;
        // nrrareknkarekz
    }
}