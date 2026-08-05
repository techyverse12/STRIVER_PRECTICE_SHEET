class Solution {
public:
int longestConsecutive(vector<int>& nums) {
       if(nums.size()==0){
        return 0;
    }
    int longest=1;
set<int> s;
for(int i=0;i<nums.size();i++){
    s.insert(nums[i]);
}
for(auto it:s){
    if(s.find(it-1)==s.end()){
       int coun=1;
       int x=it;
    while(s.find(x+1)!=s.end()){
        x=x+1;
        coun++;
    }
    longest=max(longest,coun);
}}
return longest;
}
};