class Solution {
public:
    int maxDepth(string s) {
      int balance=0;
      int ans=0;
     for(char c:s){
        if(c=='('){
            balance++;
        }
        else if(c==')'){
            balance--;
        }
        ans=max(ans,balance);
     }
     return ans;
    }
};