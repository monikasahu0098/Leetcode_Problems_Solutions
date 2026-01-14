class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        int n = squares.size();
        
        // Events: {y, type, x1, x2}
        vector<tuple<long long, int, long long, long long>> events;
        for (auto& sq : squares) {
            long long x1 = sq[0];
            long long y1 = sq[1];
            long long len = sq[2];
            long long x2 = x1 + len;
            long long y2 = y1 + len;
            
            events.emplace_back(y1, 1, x1, x2);  // bottom edge
            events.emplace_back(y2, -1, x1, x2); // top edge
        }
        
        sort(events.begin(), events.end());
        
        // Active intervals
        multiset<pair<long long, long long>> active; // {x1, x2}
        
        // Compute total area and track cumulative area
        double total_area = 0;
        double cumulative_area = 0;
        long long prev_y = get<0>(events[0]);
        long long prev_width = 0;
        
        // First pass to compute total area
        int m = events.size();
        for (int i = 0; i <= m; i++) {
            long long current_y = (i < m) ? get<0>(events[i]) : prev_y;
            
            // Add area for segment [prev_y, current_y]
            if (i > 0 && current_y > prev_y && prev_width > 0) {
                total_area += (double)(current_y - prev_y) * prev_width;
            }
            
            if (i == m) break;
            
            // Process all events at this y
            long long y = get<0>(events[i]);
            vector<tuple<long long, int, long long, long long>> same_y_events;
            same_y_events.push_back(events[i]);
            
            while (i + 1 < m && get<0>(events[i + 1]) == y) {
                i++;
                same_y_events.push_back(events[i]);
            }
            
            // Update active intervals
            for (auto& ev : same_y_events) {
                long long y_val = get<0>(ev);
                int type = get<1>(ev);
                long long x1 = get<2>(ev);
                long long x2 = get<3>(ev);
                
                if (type == 1) {
                    // Add interval
                    active.insert({x1, x2});
                } else {
                    // Remove interval
                    auto it = active.find({x1, x2});
                    if (it != active.end()) active.erase(it);
                }
            }
            
            // Compute new width
            prev_width = 0;
            if (!active.empty()) {
                vector<pair<long long, long long>> intervals(active.begin(), active.end());
                sort(intervals.begin(), intervals.end());
                
                long long cur_l = -1, cur_r = -1;
                for (auto& iv : intervals) {
                    if (iv.first > cur_r) {
                        prev_width += (cur_r - cur_l);
                        cur_l = iv.first;
                        cur_r = iv.second;
                    } else {
                        cur_r = max(cur_r, iv.second);
                    }
                }
                prev_width += (cur_r - cur_l);
                if (cur_l == -1) prev_width = 0;
            }
            
            prev_y = y;
        }
        
        // Reset for second pass to find y where cumulative_area = total_area/2
        double target = total_area / 2.0;
        cumulative_area = 0;
        active.clear();
        prev_y = get<0>(events[0]);
        prev_width = 0;
        
        for (int i = 0; i <= m; i++) {
            long long current_y = (i < m) ? get<0>(events[i]) : prev_y;
            
            // Check if target is reached in segment [prev_y, current_y]
            if (i > 0 && current_y > prev_y && prev_width > 0) {
                double segment_area = (double)(current_y - prev_y) * prev_width;
                
                if (cumulative_area + segment_area >= target - 1e-12) {
                    // Target reached in this segment
                    double remaining = target - cumulative_area;
                    return prev_y + remaining / prev_width;
                }
                cumulative_area += segment_area;
            }
            
            if (i == m) break;
            
            // Process all events at this y
            long long y = get<0>(events[i]);
            vector<tuple<long long, int, long long, long long>> same_y_events;
            same_y_events.push_back(events[i]);
            
            while (i + 1 < m && get<0>(events[i + 1]) == y) {
                i++;
                same_y_events.push_back(events[i]);
            }
            
            // Update active intervals
            for (auto& ev : same_y_events) {
                long long y_val = get<0>(ev);
                int type = get<1>(ev);
                long long x1 = get<2>(ev);
                long long x2 = get<3>(ev);
                
                if (type == 1) {
                    active.insert({x1, x2});
                } else {
                    auto it = active.find({x1, x2});
                    if (it != active.end()) active.erase(it);
                }
            }
            
            // Compute new width
            prev_width = 0;
            if (!active.empty()) {
                vector<pair<long long, long long>> intervals(active.begin(), active.end());
                sort(intervals.begin(), intervals.end());
                
                long long cur_l = -1, cur_r = -1;
                for (auto& iv : intervals) {
                    if (iv.first > cur_r) {
                        prev_width += (cur_r - cur_l);
                        cur_l = iv.first;
                        cur_r = iv.second;
                    } else {
                        cur_r = max(cur_r, iv.second);
                    }
                }
                prev_width += (cur_r - cur_l);
                if (cur_l == -1) prev_width = 0;
            }
            
            prev_y = y;
        }
        
        return prev_y;
    }
};