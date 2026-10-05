class Solution {
public:
    void solve(int n,vector<string> &ans,int start,int close,string s){
        //T.c-O(n*catalan number)
        if(s.size()==2*n){
            ans.push_back(s);
            return;
        }
        if(close<start){
            solve(n,ans,start,close+1,s+")");
        }
        if(start<n){
            solve(n,ans,start+1,close,s+"(");
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> s;
        solve(n,s,0,0,"");
        return s;
    }
};