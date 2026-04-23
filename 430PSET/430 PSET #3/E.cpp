#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        map<string,set<string>> translations;
        vector<set<string>> italianNames;
        vector<set<string>> englishNames;
        for(int i = 0; i < n; i++){
            string pizzaName;
            cin >> pizzaName;

            int a;
            cin >> a;
            set<string> italianName;
            for(int j = 0;j < a; j++){
                string italian;
                cin >> italian;
                italianName.insert(italian);
            }
            italianNames.push_back(italianName);
            cin >> a;
            set<string> englishName;
            for(int j = 0;j < a; j++){
                string english;
                cin >> english;
                englishName.insert(english);
            }
            englishNames.push_back(englishName);
        }
        for(int k = 0; k < 2; k++){
            for(int i = 0; i < n; i++){
                for(auto italianItem : italianNames[i]){
                    if(translations.find(italianItem) == translations.end()){
                        // not found
                        translations[italianItem] = englishNames[i];
                    }else{
                        for(auto italianIter : translations){

                            if(italianNames[i].find(italianIter.first) == italianNames[i].end()){
                                // pizza does not have topping
                                set<string> result;
                                set_difference(translations[italianIter.first].begin(), translations[italianIter.first].end(), englishNames[i].begin(), englishNames[i].end(),inserter(result, result.begin()));
                                translations[italianIter.first] = result;
                            }else{
                                set<string> result;
                                set_intersection(translations[italianIter.first].begin(), translations[italianIter.first].end(), englishNames[i].begin(), englishNames[i].end(),inserter(result, result.begin()));
                                translations[italianIter.first] = result;
                            }
                        }
                    }
                }
            }
        }

        vector<string> sortedItalianWords;
        for(auto x: translations){
            sortedItalianWords.push_back(x.first);
        }
        sort(sortedItalianWords.begin(),sortedItalianWords.end());

        for(auto word : sortedItalianWords){
            vector<string> sortEnglishWords;
            for(auto x: translations[word]){
                sortEnglishWords.push_back(x);
            }
            sort(sortEnglishWords.begin(),sortEnglishWords.end());

            for(int i = 0; i < sortEnglishWords.size(); i++){
                cout << "(" << word << ", " << sortEnglishWords[i] << ")" << endl;
            }
        }
        cout << endl;
    }
}

// for every italian item, if it doesnt exist, add all english item, else intersection, current items