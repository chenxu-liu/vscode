int trap(vector<int>& height)
{
    int ans = 0;
    stack<int> st;
    for (int i = 0; i < height.size(); i++)
    {
        while (!st.empty() && height[st.top()] < height[i])
        {
            int cur = st.top();
            st.pop();
            if (st.empty()) break;
            int l = st.top();
            int r = i;
            int h = min(height[r], height[l]) - height[cur];
            ans += (r - l - 1) * h;
        }
        st.push(i);
    }
    return ans;
}