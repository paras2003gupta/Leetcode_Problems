class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        vector<int>gaps; // har do meeting ke beech ka gap store karne ke liye
        int n = startTime.size();
        int end = eventTime;
        int start = 0;

        // Pehla gap: event ke start se pehli meeting tak ka
        gaps.push_back(startTime[0] - start);

        // Beech ke gaps: har 2 consecutive meetings ke beech ka
        for(int i = 0 ; i < n - 1 ; i++){
            gaps.push_back(startTime[i + 1] - endTime[i]);
        }

        // Aakhri gap: last meeting ke baad se event end hone tak
        gaps.push_back(end - endTime[n - 1]);

        int maxi = INT_MIN;

        // Copy of gaps banaya jise sort karenge later
        vector<int>sorted_gaps = gaps;
        sort(sorted_gaps.begin(), sorted_gaps.end()); // O(n log n)

        // Har 2 consecutive gaps ke upar loop
        for(int i = 0; i < gaps.size() - 1; i++){
            int sum = gaps[i] + gaps[i + 1]; // current 2 gaps ka sum

            int toAdjust = endTime[i] - startTime[i]; // jis meeting ko shift karna hai uski duration
            int cnt = gaps.size() - (lower_bound(sorted_gaps.begin(), sorted_gaps.end(), toAdjust) - sorted_gaps.begin());

            // Agar current gap hi duration se bada hai toh count se hatao (kyunki wahi use ho gaya hoga)
            if(toAdjust <= gaps[i]){
                cnt--;
            }
            if(toAdjust <= gaps[i + 1]){
                cnt--;
            }

            // Agar koi aur gap bacha hai jisme ye meeting aa sakti hai
            if(cnt > 0){
                sum += toAdjust; // duration ko add karo kyunki reschedule possible hai
            }

            // Maximum free time update karo
            maxi = max(maxi, sum);
        }

        return maxi;
    }
};
