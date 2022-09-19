class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
     
     /* This Problem statement is quite so confusing in itself but if we go throuh the input           
     and  Sample Output We find that we had to report such paths from the input of list of        
     paths that have count greater than one.
     
       
        So a Pretty straight Forward Solution to the Problem is to use a
        hashmap or(Dictionary in python with string as key and a list as value which will also conatins string ) 
        this hashmap will have content of          
        file as key and their respective path as values
        
        as the hash map is created we will now only filter thoes file name in our ans list which have content value greater than 1.
        */
        
        vector<vector<string>>res;
        
        
        unordered_map<string,vector<string>>mp;
        
        for(auto dr:paths)
        {
            stringstream str(dr);
            
            string dir;
            string file;
            getline(str,dir,' ');
            
            while(getline(str,file,' '))
            {
                string mat = file.substr(file.find('(')+1,file.find(')') - file.find('(')+1);
                string fname = dir + '/' + file.substr(0,file.find('('));
                mp[mat].push_back(fname);
                
                
            }
        }
        
        for(auto i:mp)
        {
            if(i.second.size()>1)
            {
                res.push_back(i.second);
            }
        }
        
        return res;
        
    }
};



/*



Time Complexity :  O(N)   Since we are creating a map and futher filtering this map's value for our final list of paths

Space Complexity : O(N)     Since we are creating a map of size less than input provided and final list of the answe.
*/
