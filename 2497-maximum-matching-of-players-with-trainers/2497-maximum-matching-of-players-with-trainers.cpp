class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        // Dono arrays ko sort kar lo taaki chhoti se chhoti capacity aur skill wale se start kar sakein
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());

        int i = 0, j = 0;
        int matched = 0;
        int n = players.size();
        int m = trainers.size();

        // Jab tak dono arrays ke elements bache hoon
        while (i < n && j < m) {
            // Jab tak trainer ki capacity player ki requirement se chhoti ho, tab tak j badhao
            while (j < m && trainers[j] < players[i]) {
                j++;
            }

            // Agar trainer ki capacity player ke liye sufficient hai
            while (j < m && i < n && trainers[j] >= players[i]) {
                i++;       // next player pe jao
                j++;       // next trainer pe jao
                matched++; // ek match mil gaya
            }
        }

        // Total matches return karo
        return matched;
    }
};
