class Solution {
public:
    
/*

Explaination for the solution below

   find the root of node x. 
    here we are not using v[x],
    because it may not contain the updated value of the connected component that x belongs to. 
    therefore, we walk the ancestors of the vertex until we reach the root.
    
     the idea is to put all characters in the same group if they are equal
    in order to do that, we can use Disjoint Set Union (dsu) aka Union Find
    
    
    at the beginning, put each character index in its own group
     so we will have 26 groups with one character each
     i.e. 'a' in group 0, 'b' in group 1, ..., 'z' in group 25
     
*/     
    
    
    
    int v[26] = {-1};
    
    int Find(int x)
    {
        if(v[x] == x)
        {
            return x;
        }
       return v[x] = Find(v[x]);
        
       
    }
    
    
    
    bool equationsPossible(vector<string>& equations) {
        
        for(int i=0;i<26;i++) v[i] = i;
        
        for(auto i:equations)
        {
            //if two character is equal, 
            
            // e.g. a == b
           // then we group them together
           // how? we use `find` function to find out the parent group of the target character index
          // then update parent. a & b would be in group 1 (i.e. a merged into the group where b belongs to)
          // or you can also do `parent[find(e[3]- 'a')] = find(e[0] - 'a');` (i.e. b merged into the group where a belongs to)
            
            if(i[1] == '=')
            {
                int a = (i[0] - 'a');
                int b = (i[3] - 'a');
                
                
                v[Find(a)] = Find(b);
                
            }
           
            
        }
        
        
        
         for(auto i:equations)
        {
             int a = (i[0] - 'a');
             int b = (i[3] - 'a');
             
             //if two characters are not equal
            // then which means their parent must not be equal
             
             
            if(i[1] == '!' && (Find(a) == Find(b)))
            {
                
                    return false;
                
                
            }
            
            
        }
        
        return true;
        
        
    }
};
