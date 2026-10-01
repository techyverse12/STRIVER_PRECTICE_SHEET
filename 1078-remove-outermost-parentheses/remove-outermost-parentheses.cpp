class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        vector<string> primitive;
        string ss;
        int balance=0;
        for(char c:s){
            if(c=='('){
                balance++;
                ss.push_back(c);
            }
            else{
                balance--;
                ss.push_back(c);
            }
            if(balance==0){
             primitive.push_back(ss);
             balance=0;
             ss="";
            }
        }
        for(int i=0;i<primitive.size();i++){
            ans+=primitive[i].substr(1,primitive[i].size()-2);
        }
        return ans;
    }
};