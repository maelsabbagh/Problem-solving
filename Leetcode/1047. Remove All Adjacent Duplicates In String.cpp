#includebitsstdc++.h
class Solution {
public
    string removeDuplicates(string S) 
    {
        stackcharst;
        int n=S.size();
        for(int i=0;in;i++)
        {
            if(!st.empty() &&S[i]==st.top())
            {
                st.pop();
            }
            else
            {
                st.push(S[i]);
            }
        }
        string ans;
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};