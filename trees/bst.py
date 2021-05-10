class BST:
    def __init__(self,data):
        self.data = data
        self.left = None
        self.right = None
    def insert(self,data):
        if data < self.data:
            self.left = BST(dat
        if data > self.data
            self.right = BST(data)
    def inorder_traversal(self):
        if self.left:
            self.left.inorder_traversal()
        print(" ",self.data)
        if self.right:
            self.right.inorder_traversal()

arr = [4,67,5,8,44,]