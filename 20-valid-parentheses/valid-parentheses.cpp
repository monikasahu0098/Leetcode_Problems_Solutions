class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
       
        int n=s.length();

        for(int i=0;i<n;i++){
            char ch=s[i];
            if(ch=='(' || ch=='{' || ch=='['){   // cose of opening brackets
                stk.push(ch);
            }else{
                if(stk.size()==0){
                    return false;
                }
                if((stk.top()=='(' && ch==')')||
                    (stk.top()=='{' && ch=='}')||
                    (stk.top()=='[' && ch==']')){
                        stk.pop();
                }else{
                    return false;
                    
                }
                
            }
            

        }
        return stk.size()==0;

    }
};