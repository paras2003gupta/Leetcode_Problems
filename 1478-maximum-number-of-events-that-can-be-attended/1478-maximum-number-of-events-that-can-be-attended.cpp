class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
    sort(events.begin(), events.end()); // sort by start day
    priority_queue<int, vector<int>, greater<int>> pq; // min-heap on end day
    
    int n = events.size(), i = 0, res = 0;
    int day = 1;

    while (!pq.empty() || i < n) {
        // Add all events that start today
        while (i < n && events[i][0] == day) {
            pq.push(events[i][1]);
            i++;
        }

        // Remove events that already ended
        while (!pq.empty() && pq.top() < day) {
            pq.pop();
        }

        // Attend event with earliest end day
        if (!pq.empty()) {
            pq.pop();
            res++;
        }

        day++;
    }

    return res;
}

};