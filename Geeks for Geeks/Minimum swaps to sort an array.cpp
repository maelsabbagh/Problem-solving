//  https://practice.geeksforgeeks.org/problems/minimum-swaps/1#
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{

    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    int n = nums.size();
	    
	    vector<int>sorted(n);
	    unordered_map<int,bool>visited;
	    unordered_map<int,int>correct_index;
	    int min_swaps=0;
	    int current_cycle=0;
	    
	    for(int i=0;i<n;i++)
	    {
	        sorted[i] = nums[i]; 
	        visited[nums[i]]=0;
	    }
	    
	    sort(sorted.begin(),sorted.end());
	    
	    for(int i=0;i<n;i++)
	    {
	        correct_index[sorted[i]]=i;
	    }
	    

	    for(int i=0;i<n;i++)
	    {
	        if(sorted[i]==nums[i] || visited[nums[i]])
	        {
	           
	            visited[nums[i]]=1;
	            continue;
	        }
	        int curr_idx=i;
	       
	        while(visited[nums[curr_idx]]==0) // number is not visited 
	        {
	            
	            int num = nums[curr_idx];
	            visited[num]=1;
	            current_cycle++;
	            
	            curr_idx = correct_index[num];
	          
	            
	            
	        }
	        if(visited[nums[curr_idx]]==1)
	        {
	          
	            min_swaps+=(current_cycle-1);
	            current_cycle=0;
	        }
	   
	    }
	    return min_swaps;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends
