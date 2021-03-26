class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) 
    {
    
     
	int n = nums.size();
	vector<int>target;
	vector<int>tmp;
	for (int i = 0; i < n; i++)
	{
		if (index[i] == i)
		{
			target.push_back(nums[i]);
		}
		else if (index[i] < i)
		{
			int stop = index[i];
			for (int j = 0; j < stop; j++)
			{
				tmp.push_back(target[j]);
			}
			tmp.push_back(nums[i]);
			for (int j = stop ; j < target.size(); j++)
			{
				tmp.push_back(target[j]);
			}
			target = tmp;
			tmp.clear();
		}
	}
	return target;
        
    }
};