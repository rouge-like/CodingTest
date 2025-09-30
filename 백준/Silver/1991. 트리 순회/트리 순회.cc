#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int n;

struct Node
{
    char value;
    Node* left;
    Node* right;

    Node(char v) : left(nullptr), right(nullptr), value(v) {}
};

void preorder(Node* root)
{
    if (root == nullptr) return;

    cout << root->value;

    preorder(root->left);
    preorder(root->right);
}
void inorder(Node* root)
{
    if (root == nullptr) return;

    inorder(root->left);
    cout << root->value;
    inorder(root->right);
}
void postorder(Node* root)
{
    if (root == nullptr) return;

    postorder(root->left);
    postorder(root->right);
    cout << root->value;
}
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    map<char, Node*> mp;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        char a, b, c;

        cin >> a >> b >> c;

        Node* nodeA = nullptr;

        if (mp.find(a) != mp.end())
        {
            nodeA = mp[a];
        }
        else
        {
            nodeA = new Node(a);
            mp[a] = nodeA;
        }

        if (b != '.')
        {
            Node* nodeB = nullptr;

            if (mp.find(b) != mp.end())
            {
                nodeB = mp[b];
            }
            else
            {
                nodeB = new Node(b);
                mp[b] = nodeB;
            }

            nodeA->left = nodeB;
        }

        if (c != '.')
        {
            Node* nodeC = nullptr;

            if (mp.find(c) != mp.end())
            {
                nodeC = mp[c];
            }
            else
            {
                nodeC = new Node(c);
                mp[c] = nodeC;
            }

            nodeA->right = nodeC;
        }
    }

    preorder(mp['A']);
    cout << "\n";
    inorder(mp['A']);
    cout << "\n";
    postorder(mp['A']);
    return 0;
}

