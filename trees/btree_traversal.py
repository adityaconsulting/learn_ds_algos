class Btree:
    def __init__(self,data):
        self.data = data
        self.left = None
        self.right = None
        
    def inorder_traversal(self):
        if self.left:
            self.left.inorder_traversal()
        print(" ",self.data)
        if self.right:
            self.right.inorder_traversal()
    def preorder_traversal(self):
        print(self.data)
        if self.left:
            self.left.preorder_traversal()
        if self.right:
            self.right.preorder_traversal()
    def postorder_traversal(self):
        if self.left:
            self.left.postorder_traversal()
        if self.right:
            self.right.postorder_traversal()
        print(self.data)

Bt  = Btree(2) 
Bt.left = Btree(4)
Bt.right =  Btree(6)

Bt.left.left = Btree(8)
Bt.left.right = Btree(10)

print("in-order traversal")
Bt.inorder_traversal()
print("pre-order traversal")
Bt.preorder_traversal()
print("post-order traversal")
Bt.postorder_traversal()



