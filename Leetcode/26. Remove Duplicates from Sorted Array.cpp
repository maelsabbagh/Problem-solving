class Solution { //C++ two pointers: Time O(N), Space O(1)

public:
    int removeDuplicates(vector<int>& nums)
    {
        if(nums.size()==0) return 0;
        int i=0,j=1;
        int n=nums.size();
        while(j<n)
        {
            if(nums[j]==nums[i])
            {
                j++;
            }
            else
            {
                nums[i+1]=nums[j];
                i++;
                j++;
            }
        }
        return i+1;
        
    }
};