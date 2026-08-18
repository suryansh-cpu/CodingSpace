void processFiles(files: List[File]){
    set<pair<int,pair<int,string>>> smallestSortedTime;
    for(int i = 0;i<files.size();i++){
        if(files[i].peek()!= null){
            smallestSortedTime.insert({files[i].first,{i,files[i].second}});
        }
    }
    while(!smallestSortedTime.empty()){
        int smallestPos = smallestSortedTime.begin().second.first
        files[smallestPos].pop();
        cout << smallestSortedTime.first << " " << smallestSortedTime.second.second << "\n";
        smallestSortedTime.erase(smallestSortedTime.begin());
        if(files[smallestPos].peek()!= null)smallestSortedTime.insert({files[smallestPos].peek().first,{smallestPos,files[smallestPos].peek().second}});
    }
}