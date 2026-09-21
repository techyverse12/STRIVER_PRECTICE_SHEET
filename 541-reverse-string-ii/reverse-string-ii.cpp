class Solution {
public:
    void reverse(string& s,int j,int k){
        int z=j+k-1;
        for(int i=j;i<z;i++){
            swap(s[i],s[z]);
            z--;
        }
    }
    string reverseStr(string s, int k) {
            for(int j = 0; j < s.size(); j += 2*k) {
        int remaining = s.size() - j;
        if(remaining >= k) {
            reverse(s, j, k);
        }
        else {
            reverse(s, j, remaining);
        }
    }
    return s;
}
};