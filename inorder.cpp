#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <queue>
using namespace std;

struct treenode {
    int val;
    treenode* left;
    treenode* right;
    treenode(int x) : val(x), left(nullptr), right(nullptr) {}
};
vector<string> values;
treenode* buildtree(string input) {
    istringstream iss(input);
    string words;
    while (getline(iss, words, ' ')) {
        values.push_back(words);
    }

    int n = values.size();
    if (n == 0 || values[0] == "null") {
        return nullptr;
    }

    queue<treenode*> q;
    treenode* root = new treenode(stoi(values[0]));
    q.push(root);

    int idx = 1;
    while (!q.empty() && idx < n) {
        treenode* curr = q.front();
        q.pop();
        string leftele = values[idx++];
        if (!(leftele == "null")) {
            curr->left = new treenode(stoi(leftele));
            q.push(curr->left);
        }
        if (idx < n) {
            string rightele = values[idx++];
            if (!(rightele == "null")) {
                curr->right = new treenode(stoi(rightele));
                q.push(curr->right);
            }
        }
    }
    return root;
}

void printinor(struct treenode* y) {
    if (y == nullptr) return;
    printinor(y->left);
    cout << y->val << " ";
    printinor(y->right);
}

int main() {
    cout << "Enter values: ";
    string input;
    getline(cin, input);
    treenode* root = buildtree(input);

    printinor(root);
    return 0;
}
