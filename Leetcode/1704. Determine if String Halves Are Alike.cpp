class Solution {
public:
    bool halvesAreAlike(string s) 
    {
        int i=0;
        int j=s.length()/2;
        string cmp="aeiouAEIOU";
        int c1=0,c2=0;
        for(i,j;i<j,j<s.length();i++,j++)
        {
            for(int k=0;k<cmp.size();k++)
            {
                if(s[i]==cmp[k])c1++;
                if(s[j]==cmp[k])c2++;
            }
        }
      
                     return c1==c2;
                     
    }
};