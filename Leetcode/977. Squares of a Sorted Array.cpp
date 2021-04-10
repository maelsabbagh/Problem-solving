class Solution {
public:
   
//O(N) two_pointers
    vector<int> sortedSquares(vector<int>& nums)
    {
        int n=nums.size();
        int l=0;
        int r=n-1;
        
        //vector<int>squared;
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            nums[i]=(nums[i]*nums[i]);
        }
        while(l<=r)
        {
            if(nums[l]>nums[r])
            {
                ans.push_back(nums[l]);
                l++;
            }
            else
            {
                ans.push_back(nums[r]);
                r--;
            }
        }
        
        // reverse vector
        l=0,r=n-1;
        while(l<r)
        {
            swap(ans[l],ans[r]);
            l++;
            r--;
        }
        return ans;
    
        
    }
};