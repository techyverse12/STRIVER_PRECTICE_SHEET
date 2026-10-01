class Solution {
public:
    int expand(string s,int left,int right){
        while(left>=0 && right<s.size() && s[left]==s[right]){
            left--;
            right++;
        }
        return right-left-1;
    }
    string longestPalindrome(string s) {
        //it is optinal here we assume every index as centre and expand and found max palindrome sustring T.C O(n^2)
        int n=s.size();
        int length=INT_MIN;
        int maxlen=INT_MIN;
        int start;
        for(int i=0;i<n;i++){
            int foreven=expand(s,i,i+1);
            int forodd=expand(s,i,i);
            length=max(foreven,forodd);
            if(length>maxlen){
                maxlen=length;
                start=i-(length-1)/2;
            }
        }
        return s.substr(start,maxlen);
    }
};