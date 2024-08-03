#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>

using namespace std;

int n; // 트리의 정점 개수
vector<int> inorder(n+1);
vector<int> postorder(n+1);
vector<int> preorder;
unordered_map<int, int> inorderIndex; 

void findPreorder(int inStart, int inEnd, int postStart, int postEnd);

int main() {
    cin >> n;
    inorder.resize(n);
    postorder.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> inorder[i];
        inorderIndex[inorder[i]] = i; // Store index of each element
    }
    for (int i = 0; i < n; i++) {
        cin >> postorder[i];
    }

   findPreorder(0, n - 1, 0, n - 1);
    for (int i = 0; i < preorder.size() ; i++) {
        cout << preorder[i] << " ";
    }
    return 0;
}

void findPreorder(int inStart, int inEnd, int postStart, int postEnd){
    if (inStart > inEnd || postStart > postEnd) return;

    int root = postorder[postEnd]; 
    preorder.push_back(root);

    int rootIndex = inorderIndex[root];
    int leftSubtreeSize = rootIndex - inStart;

    findPreorder(inStart, rootIndex - 1, postStart, postStart + leftSubtreeSize - 1);
    findPreorder(rootIndex + 1, inEnd, postStart + leftSubtreeSize, postEnd - 1);
}