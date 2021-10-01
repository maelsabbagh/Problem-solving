// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    
    bool canPlace(int books[],int n, int students,int barrier)
    {
        int selected_students=1;
        int pages=0;
        
        for(int i=0;i<n;)
        {
            if(books[i]>barrier)return false;
            if(pages + books[i]<=barrier)
            {
                pages = pages + books[i];
                i++;
            }
            else
            {
                selected_students++;
                pages=0;
                if(selected_students>students)return false;
                
            }
        }
        return true;
    }
    
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        //code here
        
        // creat a search space
        int start=0;
        int end=0;
        for(int i=0;i<N;i++)
        {
            end = end + A[i];
        }
        
        int ans=-1;
        while(start<=end)
        {
            int middle = (start+end)/2;
            
            if(canPlace(A,N,M,middle))
            {
                ans= middle;
                end = middle-1;
            }
            else
            {
                start = middle+1;
            }
        }
        
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends