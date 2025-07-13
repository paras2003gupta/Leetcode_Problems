class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());

        int i = 0,j=0;
        int matched = 0;
        int n = players.size();
        int m = trainers.size();
        while(i<n&&j<m){
            while(j<m&&trainers[j]<players[i]){
                j++;
            }
            while(j<m&&i<n&&trainers[j]>=players[i]){
                i++;
                j++;
                matched++;
            }

        }
        return matched;
    }
};