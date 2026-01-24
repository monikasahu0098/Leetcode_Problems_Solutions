class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int countBoat=0;

        sort(begin(people),end(people));
        int i=0;
        int j=people.size()-1;

        while(i<=j){
            if((people[i]+people[j])<=limit){
                i++;
                j--;
            }else if(people[j]<=limit){
                j--;
            }
            countBoat++;
        }
        return countBoat;
    }
};