class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        int sum = 0;
        for(int i=0;i<operations.size();i++){
            if(operations[i]=="+"){
                int x=st.top();
                st.pop();
                sum = st.top() + x;
                st.push(x);
                st.push(sum);
            }
            else if(operations[i]=="C") st.pop();
            else if(operations[i]=="D") st.push(st.top()*2);
            else{
                st.push(stoi(operations[i]));
            }
        }
        int ans = 0;
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};