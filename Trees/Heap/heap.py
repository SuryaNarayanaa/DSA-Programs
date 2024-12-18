class Heap:
    def __init__(self):
        self.arr = []
    
    def swap(self, i, j):
        self.arr[i], self.arr[j] = self.arr[j], self.arr[i]
    
    def parent(self, index):
        return (index - 1) // 2
    
    def left(self, index):
        return (2 * index) + 1
    
    def right(self, index):
        return (2 * index) + 2
    
    def upheap(self, index):
        if(index ==0):
            return
        p = self.parent(index)
        if(self.arr[p]>self.arr[index]):
            self.swap(p, index)
            self.upheap(p)

    def downheap(self, index):
        min  = index
        left = self.left(index)
        right = self.right(index)
        if left < len(self.arr) and self.arr[left] < self.arr[min]:
            min = left
        if right < len(self.arr) and self.arr[right] < self.arr[min]:
            min = right
        if(min!=index):
            self.swap(min,index)
            self.downheap(min)
            

    def insert(self, data):
        self.arr.append(data)
        self.upheap(len(self.arr)-1)

    def remove(self):
        if(len(self.arr)==0):
            return  None
        top = self.arr[0]
        last = self.arr.pop()
        if(len(self.arr)!= 0):
            self.arr[0]= last   
            self.downheap(0)
        return top

    def heapsort(self):
        sort = []
        while len(self.arr) != 0:
            sort.append(self.remove())
        
        return sort



h = Heap()
h.insert(5)

h.insert(3)
h.insert(54)
h.insert(53)
h.insert(54)
print(h.heapsort())