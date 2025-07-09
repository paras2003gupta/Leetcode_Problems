class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        vector<int>gaps;
        int n = startTime.size();
        int st = 0;
        int end = eventTime;
        gaps.push_back(startTime[0]-0);
        for(int i = 0;i<n-1 ; i++){
            int stime = startTime[i+1];
            int etime = endTime[i];
            gaps.push_back(stime-etime);

        }
        gaps.push_back(end-endTime[n-1]);
        int maxi = 0;
        int sum = 0;
        int s = gaps.size();
        for(int i = 0;i<min(k+1,s) ; i++){
            sum+=gaps[i];        
        }
        maxi = max(maxi,sum);
        if(k+1>gaps.size()){
            return maxi;
        }
        for(int i = k+1 ; i< gaps.size() ; i++){
            sum+=gaps[i];
            sum-=gaps[i-(k+1)];
            maxi = max(maxi,sum);
        }   
        return maxi;

    }
};