class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        string str = "";

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();

            if(!curr) str += "#,";
            else str += (to_string(curr->val) + ",");

            if(curr){
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0) return NULL;

        stringstream s(data);
        string str;
        getline(s, str, ',');

        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();

            getline(s, str, ',');
            if(str != "#"){
                TreeNode* left = new TreeNode(stoi(str));
                curr->left = left;
                q.push(left);
            }

            getline(s, str, ',');
            if(str != "#"){
                TreeNode* right = new TreeNode(stoi(str));
                curr->right = right;
                q.push(right);
            }

        } 

        return root;
    }
};