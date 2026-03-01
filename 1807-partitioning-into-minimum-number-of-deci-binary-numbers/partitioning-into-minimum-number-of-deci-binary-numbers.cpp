class Solution {
public:
    int minPartitions(string n) {
        char count=*max_element(n.begin(),n.end());
        return count-'0';
    }
};