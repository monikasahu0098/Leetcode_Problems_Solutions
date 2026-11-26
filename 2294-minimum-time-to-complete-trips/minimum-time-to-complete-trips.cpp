class Solution {
public:
    bool canMakeTrip(vector<int>& time, long long given_time, int totalTrips) {
        long long actualTrip = 0;

        for (int &x : time) {
            actualTrip += given_time / x;
        }
        return actualTrip >= totalTrips;
    }

    long long minimumTime(vector<int>& time, int totalTrips) {
        long long l = 1;
        long long r = (long long)*min_element(begin(time), end(time)) * totalTrips;

        while (l < r) {
            long long mid_time = l + (r - l) / 2;

            if (canMakeTrip(time, mid_time, totalTrips)) {
                r = mid_time;
            } else {
                l = mid_time + 1;
            }
        }
        return l;
    }
};
