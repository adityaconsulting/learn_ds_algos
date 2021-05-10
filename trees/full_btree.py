#A full Binary tree is a special type of binary tree in which every parent node/internal node 
#has either two or no children. -- Also called perfect binary tree.


class Btree:
    def __init__(self,data):
        self.data = data
        self.left = None
        self.right = None
        
    def is_full_btree(self):
        if self == None:
            return True
        # checking for both left and right leaves
        if self.left == None and self.right == None:
            return True
        if self.left != None  and self.right != None:
            return (self.left.is_full_btree() == True and self.right.is_full_btree() == True)
        return False
        
    
    

Bt  = Btree(2) 
Bt.left = Btree(4)
Bt.right =  Btree(6)

Bt.left.left = Btree(8)
Bt.left.right = Btree(10)

Bt.right.left = Btree(12)
Bt.right.right = Btree(14)



if Bt.is_full_btree():
    print("is full or perfect binary tree.")
else:
    print("is not perfect binay tree.")


