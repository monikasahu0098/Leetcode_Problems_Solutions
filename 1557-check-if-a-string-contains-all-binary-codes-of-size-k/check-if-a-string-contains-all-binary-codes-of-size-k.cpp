class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n=s.size();
        int total_code=1<<k;
        unordered_set<string>st;

        for(int i=k;i<=n;i++){
            string sub=s.substr(i-k,k);

            if(!st.count(sub)){
                st.insert(sub);
                total_code--;
            }
            if(total_code==0){
                return true;
            }
        }
        return false;
    }
};