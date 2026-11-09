class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int count = 0;
        int rem = 0;
        vector<int> ans;
        for(int i = 0;i<s.size();i++){
            int x = s[i]-'a';
            if(rem == 100){
                rem = 0;
                count++;
            }
            if((rem + widths[x]) > 100){
                rem = widths[x];
                count++;
            }
            else{
                rem += widths[x];
            }
        }
        ans.push_back(count+1);
        ans.push_back(rem);
        return ans;
    }
};