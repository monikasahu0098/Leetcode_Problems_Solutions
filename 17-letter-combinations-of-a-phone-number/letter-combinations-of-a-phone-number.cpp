class Solution {
public:
    vector<string>result;
    void solve(int idx,string &digits,string &temp,unordered_map<char,string>&m){
        if(idx>=digits.length()){
            result.push_back(temp);
            return;
        }
        char ch=digits[idx];
        string s=m[ch];

        for(int it=0;it<s.size();it++){
            temp.push_back(s[it]);
            solve(idx+1, digits,temp,m);
            temp.pop_back();
        }

    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0){
            return {};
        }
       
        unordered_map<char,string>m;
        m['2']="abc";
        m['3']="def";
        m['4']="ghi";
        m['5']="jkl";
        m['6']="mno";
        m['7']="pqrs";
        m['8']="tuv";
        m['9']="wxyz";

        string temp="";
        solve(0,digits,temp,m);

        return result;
    }
};