/**
 * Optimal solution using multiset:
 * !Time Complexity: O(N * log2N * log2N * log2N)
 * - Traversing the tree takes O(N) time.
 * - Inserting into the multiset takes O(log2N) time.
 * - Inserting into the map takes O(log2N) time.
 * - Inserting into the nested map takes O(log2N) time.
 * Space Complexity: O(N + N/2)
 * - The map and multiset together take O(N) space.
 * - The queue used for level order traversal takes O(N/2) space in the worst case.
 */

// tc: o(nlog) and sc: o(n)
// oneNote dry run is necessary and make all datastructure properly
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr, right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//! optimal solution Time Complexity: O(N * log2N * log2N * log2N) and Space Complexity: O(N + N/2)
class Solution
{
public:
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        //*{ vertical level {horizontal level {value}}}
        map<int, map<int, multiset<int>>> vl; 
        //* {value, vertical level, horizontal level}
        queue<pair<TreeNode *, pair<int, int>>> todo;
        todo.push({root, {0, 0}}); // pushing the root node with vertical level 0 and horizontal level 0

        while (!todo.empty())
        {
            auto p = todo.front();
            todo.pop();
            TreeNode *node = p.first; // getting the node
            int x = p.second.first;   // getting vertical value
            int y = p.second.second;  // getting horizontal value

            vl[x][y].insert(node->val); // pushing the node 1.value 2.vertical level 3.horizontal level

            if (node->left)
            {
                todo.push({node->left, {x - 1, y + 1}}); // as we go ,left vertical level always decrease and horizontal level alway increase as we go down
            }
            if (node->right)
            {
                todo.push({node->right, {x + 1, y + 1}}); // as we go, right vertical level always increase and horizontal level alway increase as we go down
            }
        }

        vector<vector<int>> result;
        for (auto p : vl)
        {
            vector<int> temp; // temporary store horizontal value of the graph
            for (auto q : p.second)
            {
                temp.insert(temp.end(), q.second.begin(), q.second.end());
            }
            result.push_back(temp);
        }
        return result;
    }
};

// same code but using vector more time complexity because using vector instead of multiset and have to sort that at end of the result
/**
 * Alternative solution using vector:
 * !Time Complexity: O(N * logN)
 * - Traversing the tree takes O(N) time.
 * - Inserting into the vector takes O(1) time.
 * - Sorting the vector takes O(N * logN) time.
 * Space Complexity: O(N)
 * - The map and vector together take O(N) space.
 * - The queue used for level order traversal takes O(N/2) space in the worst case.
 */


class Solution
{
public:
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        map<int, vector<pair<int, int>>> mp;
        queue<pair<TreeNode *, pair<int, int>>> q;
        q.push({root, {0, 0}});
        while (!q.empty())
        {
            int n = q.size();
            for (int i = 0; i < n; i++)
            {
                auto f = q.front();
                q.pop();
                TreeNode *node = f.first;
                auto pos = f.second;
                int xpos = pos.first;
                int ypos = pos.second;
                if (node->left)
                    q.push({node->left, {xpos - 1, ypos + 1}});
                if (node->right)
                    q.push({node->right, {xpos + 1, ypos + 1}});
                mp[xpos].push_back({node->val, ypos});
            }
        }

        vector<vector<int>> ans;
        for (auto i : mp)
        {
            sort(i.second.begin()alignof, i.second.end(), [&](auto p1, auto p2)
                 {
                if(p1.second == p2.second) {
                    return p1.first < p2.first;
                }
                return p1.second < p2.second; });
            vector<int> temp;
            for (auto j : i.second)
            {
                temp.push_back(j.first);
            }
            ans.push_back(temp);
        }

        return ans;
    }
};
