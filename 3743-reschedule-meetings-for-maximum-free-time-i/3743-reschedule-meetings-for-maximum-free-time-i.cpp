class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        vector<int> gaps;  // Meetings ke beech ka free time store karne ke liye
        int n = startTime.size();
        int st = 0;
        int end = eventTime;

        // Pehle meeting ke start tak ka gap (0 se startTime[0])
        gaps.push_back(startTime[0] - 0);

        // Har do meetings ke beech ka gap (start of next - end of current)
        for(int i = 0; i < n - 1; i++) {
            int stime = startTime[i + 1];
            int etime = endTime[i];
            gaps.push_back(stime - etime);
        }

        // Last meeting ke baad ka free time (event endTime tak)
        gaps.push_back(end - endTime[n - 1]);

        int maxi = 0; // Maximum free time store karne ke liye
        int sum = 0;
        int s = gaps.size();

        // Pehle k+1 gaps ka sum nikal lo (kyunki k meetings reschedule kar sakte hain)
        for(int i = 0; i < min(k + 1, s); i++) {
            sum += gaps[i];        
        }

        // Initial max assign karo
        maxi = max(maxi, sum);

        // Agar k+1 gaps hi nahi hain to wahi max hai
        if(k + 1 > gaps.size()) {
            return maxi;
        }

        // Sliding window lagao size k+1 ka to find max free time window
        for(int i = k + 1; i < gaps.size(); i++) {
            sum += gaps[i]; // new gap add karo
            sum -= gaps[i - (k + 1)]; // old gap hatao
            maxi = max(maxi, sum); // max update karo
        }
        //ye jo maximum hai vo ensure krega ki k meetings ke beech ka freetime jayada 
        //se jayada ho.
        return maxi;
    }
};
