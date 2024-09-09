/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>>mat(m,vector<int>(n,-1));
        
        int i=0,j=0,cur_d = 0,mom[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
        
        for(;head != nullptr;head = head->next)
        {
            mat[i][j] = head->val;
            int newi = i+mom[cur_d][0],newj = j+mom[cur_d][1];
            
            if(min(newi,newj) < 0 || newi >= m || newj >= n || mat[newi][newj] != -1)
            {
                cur_d = (cur_d+1)%4;
                
            }
            i += mom[cur_d][0];
            j += mom[cur_d][1];
            
        }
        return mat;
    }
};
