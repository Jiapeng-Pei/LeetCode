def sink(arr, n, i): 
    largest = i  
    l = 2*i + 1 
    r = 2*i + 2    
    if l < n and arr[i] < arr[l]: 
        largest = l 
  
    if r < n and arr[largest] < arr[r]: 
        largest = r 
  
    if largest != i: 
        arr[i],arr[largest] = arr[largest],arr[i]
        sink(arr, n, largest) 

def heapSort(arr): 
    n = len(arr) 
  
    # Build a maxheap. 
    for i in range(n, -1, -1): 
        sink(arr, n, i) 
  
    # 1. swap the largest element with the tail element
    # 2. maintain the remaining heap a max heap.
    for i in range(n-1, 0, -1): 
        arr[i], arr[0] = arr[0], arr[i]   
        sink(arr, i, 0) 
        
from queue import PriorityQueue

class intR(object):
    def __init__(self, val) -> None:
        self.val = val
    
    def __lt__(self, other):
        return self.val > other.val
    
right = PriorityQueue()
left = PriorityQueue()
        
def insert(self, val):
    if left.empty():
        left.put(intR(val))
        return
        
    rightTop = right.get()
    leftTop = left.get()
    if left.qsize() == right.qsize():
        if val <= rightTop:
            left.put(intR(val))
            left.put(leftTop)
            right.put(rightTop)
        else:
            left.put(intR(rightTop))
            left.put(leftTop)
            right.put(val)
    else:
        if val >= leftTop.val:
            right.put(val)
            right.put(rightTop)
            left.put(leftTop)
        else:
            right.put(leftTop.val)
            right.put(rightTop)
            left.put(intR(val))
            
def show_lmedian(): 
    ret = left.get()
    left.put(ret)
    return ret.val
        

  

