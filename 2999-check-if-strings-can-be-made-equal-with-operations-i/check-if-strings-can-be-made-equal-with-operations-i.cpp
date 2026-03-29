class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        if(s1==s2){
            return true;
        }
        string temp=s2;
        swap(temp[0],temp[2]);
        if(temp==s1){
            return true;
        }
        temp=s2;
        swap(temp[1],temp[3]);
        if(temp==s1){
            return true;
        }

        temp=s2;
        swap(temp[0],temp[2]);
        swap(temp[1],temp[3]);
        if(temp==s1){
            return true;
        }
        return false;
    }
};