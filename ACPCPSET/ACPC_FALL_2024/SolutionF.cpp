#include <bits/stdc++.h>

using namespace std;

typedef std::vector<int>::iterator iter;
bool contains_sum(iter begin, iter end, int sum)
{
  while (begin != end)
  {
    --end;
    if (*end > sum || *end == -1)
      continue;
    if (contains_sum(begin, end, sum - *end))
      return true;
  }
  return sum == 0;
}

int main(){
    int herbAmt;
    int waves;
    cin >> herbAmt >> waves;
    vector<int> herbs;
    for(int i = 0; i < herbAmt; i++){
        int herb;
        cin >> herb;
        herbs.push_back(herb);
    }
    for(int i = 0; i < waves; i++){
        int strength;
        int useHerbs;
        cin >> strength >> useHerbs;
        for(int j = 0; j < useHerbs; j++){
            int removeHerb;
            cin >> removeHerb;
            herbs[removeHerb-1] = -1;
        }
        if(contains_sum(herbs.begin(),herbs.end(),strength)){
            cout << "YES\n" << flush;
        }else{
            cout << "NO\n" << flush;
        }
    }

}