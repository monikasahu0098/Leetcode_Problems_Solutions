class Solution {
public:
    bool isPalin(string s){
        string s2=s;
        reverse(s2.begin(),s2.end());
        return s==s2;
    }
    void getAllparts(string s,vector<string>&partitions,vector<vector<string>>&result){
        if(s.size()==0){
            result.push_back({partitions});
            return;
        }
        for(int i=0;i<s.size();i++){
            string part=s.substr(0,i+1);
            if(isPalin(part)){
                partitions.push_back(part);
                getAllparts(s.substr(i+1),partitions,result);
                partitions.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>result;
        vector<string>partitions;
        getAllparts(s,partitions,result);
        return result;
    }
};