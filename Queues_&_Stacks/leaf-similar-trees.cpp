 bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        if(root1==NULL)
            return false;
        if(root2==NULL)
            return false;
        else
        {
            vector<int> inter1;
            vector<int> inter2;
            stack<TreeNode*> s1;
            stack<TreeNode*> s2;
            s1.push(root1);
            s2.push(root2);
            while(s1.size()!=NULL)
            {
                    TreeNode* curr=s1.top();
                    s1.pop();
                    if(curr->left==NULL && curr->right==NULL)
                        inter1.push_back(curr->val);
                    if(curr->left!=NULL)
                        s1.push(curr->left);
                    if(curr->right!=NULL)
                        s1.push(curr->right);
            }
            
             while(s2.size()!=NULL)
            {
                    TreeNode* curr=s2.top();
                    s2.pop();
                    if(curr->left==NULL && curr->right==NULL)
                        inter2.push_back(curr->val);
                    if(curr->left!=NULL)
                        s2.push(curr->left);
                    if(curr->right!=NULL)
                        s2.push(curr->right);
            }
            
             if(inter1.size()!=inter2.size())
                 return false;
             
            for(int i=0;i<inter1.size();i++)
            {
                if(inter1[i]!=inter2[i])
                {
                    return false;
                    break;
                }
            }
            
            return true;
        }
        
    }
