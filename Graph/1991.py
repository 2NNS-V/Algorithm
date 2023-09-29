import sys
input = sys.stdin.readline

n = int(input())

tree = {}

# 전위순회
def preorder(node):
    if node != ".":
        print(node, end='')
        preorder(tree[node][0]) # 왼쪽
        preorder(tree[node][1]) # 오른족

# 중위순회 
def inorder(node):
    if node != ".":
        inorder(tree[node][0]) # 왼쪽
        print(node, end='')
        inorder(tree[node][1]) # 오른쪽
    

# 후위순회
def postorder(node):
    if node != ".":
        postorder(tree[node][0]) # 왼쪽
        postorder(tree[node][1]) # 오른쪽
        print(node, end = '')
        


for i in range(n):
    key, val1, val2 = map(str, input().split())
    tree[key] = val1, val2

preorder('A')
print()
inorder('A')
print()
postorder('A')

