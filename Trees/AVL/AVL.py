class Node:
    def __init__(self,data):
        self.data = 0
        self.left = None
        self.right = None
        self.height = 1 
class AVL:
    def createNode(self, data):
        node = Node(data)
        return node
    def rightRotate(self,node):
        p=node
        c=  p.left
        t= c.right

        c.right = p
        p.left =t

        c.height = max(self.getHeight(c.left), self.getHeight(c.right)) + 1
        p.height = max(self.getHeight(p.left), self.getHeight(p.right)) + 1

        return c

    def leftRotate(self,node):
        p =node
        c= p.right
        t=c.left

        c.left = p
        p.right = t

        c.height = max(self.getHeight(c.left), self.getHeight(c.right)) + 1
        p.height = max(self.getHeight(p.left), self.getHeight(p.right)) + 1

        return c



    def rotate(self,node):
        if(self.getHeight(node.left) - self.getHeight(node.right) > 1):
            if(self.getHeight(node.left.left) - self.getHeight(node.left.right) > 0):
                return self.rightRotate(node)
            elif(self.getHeight(node.left.left) - self.getHeight(node.left.right) < 0):
                node.left = self.leftRotate(node.left)
                return self.rightRotate(node)

        if(self.getHeight(node.left) - self.getHeight(node.right) < -1):
            if(self.getHeight(node.right.right) - self.getHeight(node.right.left) > 0):
                return self.leftRotate(node)
            elif(self.getHeight(node.right.right) - self.getHeight(node.right.left) < 0):
                node.right = self.rightRotate(node.right)
                return self.leftRotate(node)

        return node

    def insert(self, data, node):
        if node is None:
            return self.createNode(data)
        if data < node.data:
            node.left = self.insert(data, node.left)
        elif data > node.data:
            node.right = self.insert(data, node.right)


        node.height = max(self.getHeight(node.left), self.getHeight(node.right)) + 1
        return self.rotate(node)

    def getHeight(self, node):
        if node is None:
            return 0
        return node.height

def createAVL():
            
    avl = AVL()
    node =None
    for i in range(1000):
        node = avl.insert(i, node)
    print(avl.getHeight(node))
createAVL()