class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n=score.size();
        vector<pair<int,int>>athletes;
        for(int i=0;i<n;i++){
            athletes.push_back({score[i],i});
        }
        vector<string>answer(n);
        sort(athletes.begin(),athletes.end(),greater<>());
        for(int i=0;i<n;i++){
            int originalIndex=athletes[i].second;
            if(i==0){
                answer[originalIndex]="Gold Medal";
            }else if(i==1){
                answer[originalIndex]="Silver Medal";
            }else if(i==2){
                answer[originalIndex]="Bronze Medal";
            }else{
                answer[originalIndex]=to_string(i+1);
            }
        }
        return answer;

        

    }
};