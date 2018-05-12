class Solution {
public:
    int numDecodings(string s) {
        vector<int> fib;
		int count=0;
		if(s.length()==1&&(int)s[0]!=48)
		return 1;
        if(s.length()==1&&(int)s[0]==48)
        return 0;
		if(s.length()>=2)
		{
			for(int i=0;i<s.length();i++)
			{
                
                
                if((int)s[i]==48&&(int)s[i-1]==48)
                      return 0;
                if((int)s[i]==48&&(int)s[i+1]==48)
                      return 0;
                
                if((int)s[i]==48&&(int)i==0)
                      return 0;
                
                if(((int)s[i]-48+10*(int)s[i-1]-480)>26&&(int)s[i]==48)
                    return 0;
				
				
            
				if((int)s[i]!=48&&i==0)
				{		
					fib.push_back(1);           
                    
					continue;
				}
                
                 if((int)s[i]==48&&i==1)
				{
					fib.push_back(1);  
                     
                    continue;
				}
                
                
                if((int)s[i]!=48&&i==1)
				{
					if(((int)s[i]-48+10*(int)s[i-1]-480)<=26)
					{
                        fib.push_back(2);  
                    }
					else
                    {
                        fib.push_back(1);  
                    }
                    
                    
					continue;
				}
	
             					
				if(((int)s[i]-48+10*(int)s[i-1]-480)<=26&&(int)s[i]!=48&&(int)s[i-1]!=48)
                    //该数不是0.且前面可以与之结合
				{
					int t = fib[0];
                    fib[0]=fib[1];
                    fib[1] = fib[1]+t;
                    
                    continue;
				}
                
                if(((int)s[i]-48+10*(int)s[i-1]-480)>26&&(int)s[i]!=48&&(int)s[i-1]!=48)
                    //该数不是0.前面不可以与之结合
				{
	
                    fib[0] = fib[1];
                    
                    continue;
				}
                
                if((int)s[i]==48)
				{
                    //该数 是0.且前面可以与之结合
					 fib[1]=fib[0];
			    
                    continue;
				}
                 if((int)s[i]==48)
				{
                    //该数前面一位是0
					fib[1]=fib[0];                   
                    continue;
				}
                
				
			}
            
			
    }
      
        return fib[1];
    }
};