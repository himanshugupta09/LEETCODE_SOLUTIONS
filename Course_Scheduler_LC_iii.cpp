class Solution
{
public:
    
    static bool comp(vector<int> &a, vector<int> &b){
        return a[1] < b[1];
    }
    
    int scheduleCourse(vector<vector<int>> &courses){
        
        
        sort(courses.begin(), courses.end(), comp);
        
       
        priority_queue<int> maxD;

        int time = 0; 
        for (auto course : courses){
            
            
            if (time + course[0] <= course[1]){
                time += course[0];
                maxD.push(course[0]);
            }
            
            
            else if (!maxD.empty() && maxD.top() >= course[0]){
                time = time - maxD.top() + course[0]; 
                maxD.pop();                           
                maxD.push(course[0]);                 
            }
        }
        
        
        return maxD.size();
    }
};
