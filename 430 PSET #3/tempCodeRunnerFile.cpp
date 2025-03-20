urrentLeaders.insert(bombs[i]);
        if(currentLeaders.find(bombs[i]+1) != currentLeaders.end()){
            uf.merge(bombs[i],bombs[i]+1);
            currentLeaders.erase(bombs[i]+1);
        }
        if(currentLeaders.find(bombs[i]-1) != currentLeaders.end()){
            uf.merge(bombs[i],bombs[i]-1);
            currentLeaders.erase(bombs[i]-1);
        }