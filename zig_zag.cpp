vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int>res;
        list<int>res1;
        queue<TreeNode*>q;
        q.push(root);
        int level=0;
        int ct=1;
        int d=0;
        if(root==NULL)
        return ans;
        while(!q.empty())
        {
           TreeNode* t=q.front();
           if(level%2==0)
           res1.push_back(t->val);
           else
           res1.push_front(t->val);
           q.pop();
           ct--;
           if(t->left!=NULL)
           {
               q.push(t->left);
               d++;
           }
           if(t->right!=NULL)
           {
               q.push(t->right);
               d++;
           }
           if(ct==0)
           {
               ct=d;
               d=0;
               level++;
               for(auto it:res1)
               {
                   res.push_back(it);
               }
               ans.push_back(res);
               res.clear();
               res1.clear();
           }
        }
        return ans;
        
    }
