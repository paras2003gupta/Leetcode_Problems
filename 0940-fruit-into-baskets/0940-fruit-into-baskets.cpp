class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        map<int,int>mp;
        int n = fruits.size();
        int i = 0,j= 0;
        int size = 0;
        while(j<n){
            mp[fruits[j]]++;
            while(mp.size()>2){
                mp[fruits[i]]--;
                if(mp[fruits[i]]==0){
                    auto it = mp.find(fruits[i]);
                    mp.erase(fruits[i]);
                }
                i++;
            }
            size = max(j-i+1,size);
            j++;
        }
        return size;
    }
};