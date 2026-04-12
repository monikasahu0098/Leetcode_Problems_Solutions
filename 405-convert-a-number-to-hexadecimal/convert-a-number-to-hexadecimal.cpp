class Solution {
public:
    string toHex(int num) {
        if(num==0){
            return "0";
        }
        string result="";
        char hexChars[]="0123456789abcdef";
        
        while(num!=0 && result.length()<8){
            int last4bits=num&15;
            result=hexChars[last4bits]+result;
            num >>=4;             
        }
        return result;
    }
};