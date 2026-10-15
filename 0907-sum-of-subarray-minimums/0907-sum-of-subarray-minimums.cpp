
class Solution {
private:
    vector<int> NSE(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        return nse;
    }

    vector<int> PSEE(vector<int>& arr) {
        int n = arr.size();
        vector<int> psee(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }

            psee[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        return psee;
    }

public:
    int sumSubarrayMins(vector<int>& arr) {
        const long long mod = pow(10,9)+7;
        vector<int> nse = NSE(arr);
        vector<int> pse = PSEE(arr);

        long long total = 0;

        for (int i = 0; i < arr.size(); i++) {
            long long left = i - pse[i];
            long long right = nse[i] - i;

            total = (total + left * right * arr[i]) % mod;
        }

        return total;
    }
};
