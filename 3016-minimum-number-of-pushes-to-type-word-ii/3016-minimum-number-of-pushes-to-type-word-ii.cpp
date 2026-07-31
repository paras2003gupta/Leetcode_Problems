class Solution {
public:
    int minimumPushes(string word) {
        map<char,int>uniquecharcount;
        for(auto it:word){
            uniquecharcount[it]++;
        }
        if(uniquecharcount.size()<=8){
            return word.size();
        }
        else{
            priority_queue<int>pq;
            for(auto it:uniquecharcount){
                pq.push(it.second);
            }
        int totalPushes = 0;
        int index = 0;

        // Calculate total number of presses
        while (!pq.empty()) {
            totalPushes += (1 + (index / 8)) * pq.top();
            pq.pop();
            index++;
        }
        return  totalPushes;
        
    }
    }
};