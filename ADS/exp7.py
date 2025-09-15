class Node:
    def __init__(self,key):
        self.key = key
        self.left =None
        self.right = None

def inorder_traversal(root):
    if root is not None:
        inorder_traversal(root.left)
        print(root.key, end =" ")
        inorder_traversal(root.right)

def preorder_traversal(root):
    if root is not None:
        print(root.key, end=" ") 
        preorder_traversal(root.left)  
        preorder_traversal(root.right) 

def postorder_traversal(root):
    if root is not None:
        postorder_traversal(root.left)  
        postorder_traversal(root.right)  
        print(root.key, end=" ")  

if __name__ == "__main__":
    root = Node(1)
    root.left = Node(2)
    root.right = Node(3)
    root.left.left = Node(4)
    root.left.right = Node(5)

    print("Inorder Traversal of the tree : ")
    inorder_traversal(root)
    print("\nPreorder Traversal of the tree:")
    preorder_traversal(root)
    print("\nPostorder Traversal of the tree:")
    postorder_traversal(root)