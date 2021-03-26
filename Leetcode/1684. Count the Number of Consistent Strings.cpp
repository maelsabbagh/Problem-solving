class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words)// not optimized
    {
        int c=0;
        for(int i=0;i<words.size();i++)
        {
            string s = words[i];
            vector<bool>frq;
            for(int j=0;j<s.size();j++)
            {
                frq.push_back(0);
            }
            for(int j=0;j<s.size();j++)
            {
                for(int k=0;k<allowed.size();k++)
                {
                    if(s[j]==allowed[k])
                    {
                        frq[j]=1;
                    }
                }
            }
            bool canBe=true;
            for(int j=0;j<frq.size();j++)
            {
                if(!frq[j])
                {
                    canBe=false;
                }
            }
            if (canBe)c++;
        }
        return c;
    }
};
