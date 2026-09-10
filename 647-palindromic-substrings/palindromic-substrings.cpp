class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int count = 0;
        vector<vector<int>> memo(n, vector<int>(n, -1));
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                if(isPalindrome(s, i, j,memo)) {
                    count++;
                }
            }
        }
        return count;
    }
    bool isPalindrome(const string& s, int left, int right,vector<vector<int>>& memo) {
        if(left>=right){
            return 1;
        }
        if(memo[left][right]!=-1){
            return memo[left][right];
        }
        if(s[left]==s[right]){
           memo[left][right] = isPalindrome(s, left + 1, right - 1, memo);
        } 
        else {
            memo[left][right] = 0;
        }
        return memo[left][right];
    }
}; 