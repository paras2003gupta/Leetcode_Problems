class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        // Sabse pehle events ko unke start day ke basis pe sort karte hain
        sort(events.begin(), events.end());

        // Min-heap banate hain to store end days of events
        priority_queue<int, vector<int>, greater<int>> pq;

        int n = events.size();
        int day = events[0][0]; // pehla din jahan se events start ho rahe hain
        int i = 0;
        int cnt = 0; // final count of events jo attend kar paaye

        // Jab tak koi event baaki hai ya heap mein koi event pending hai
        while (!pq.empty() || i < n) {

            // Jitne events current day se start ho rahe hain, unke end days heap mein daal do
            while (i < n && events[i][0] == day) {
                pq.push(events[i][1]); // event ka end day push karo
                i++;
            }

            // Agar koi event attend kar sakte ho, toh sabse pehle us event ko attend karo jiska end day sabse chhota hai
            if (!pq.empty()) {
                pq.pop(); // event attend ho gaya
                cnt++;    // count badhao
            }

            day++; // agle din par chale jao

            // Heap se saare expired events hata do (jin ka end day kal ke pehle tha)
            while (!pq.empty() && pq.top() < day) {
                pq.pop();
            }
        }

        return cnt; // total number of events attended
    }
};
