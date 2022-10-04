import sys
from collections import defaultdict
 
dict1 = defaultdict(lambda :'Rozier')

nodeDict = defaultdict(lambda: list())
indegreeDict = defaultdict(lambda: 0)

def isPairValid(string: str) :
    if len(string) != 5:
        return False
    if string[0] != '(' or string[-1] != ')' or string[2] != ',':
        return False
    if not string[1].isupper() or not string[3].isupper():
        return False
    
    return True

def buildTree(pairs):
    for pair in pairs:
        # Invalid Input
        if not isPairValid(pair):
            return "E1"
        parent = pair[1]
        child = pair[3]
            
        # Duplicate Pair
        if child in nodeDict[parent]:
            return "E2"
        
        # More than 2 Children
        if len(nodeDict[parent]) >= 2:
            return "E3"
        
        nodeDict[parent].append(child)
        nodeDict[child]
        
        indegreeDict[child] += 1
            
    return "Y"

def findRoot():
    root = ''
    for key in nodeDict:
        if indegreeDict[key] == 0:
            if root == '':
                root = key
            else:
                # Multiple Roots
                return "E4"
        elif indegreeDict[key] > 1:
            # Contains Cycle
            return "E5"
        
    return root

def dfs(root):
    if root not in nodeDict:
        return '(' + root + ')'
    ret = '(' + root
    for child in nodeDict[root]:
        ret += dfs(child)
    ret += ')'
    
    return ret

inputStr = ""
for line in sys.stdin:
    inputStr = line.strip()
    break

if inputStr[0] == ' ' or inputStr[-1] == ' ':
    print("E1")
    quit();
    
pairs = inputStr.split(' ')
status = buildTree(pairs)
if (len(status) > 1):
    print(status)
    quit();
    
root = findRoot()
if (len(root) > 1):
    print(root)
    quit();
    
print(dfs(root))
    

        


# 首先在读取数据时检测input是否合法，具体检测每个pair就行；
# 接着一边建图一边检测duplicate和Parent是否有多个child. 
# 可以用一个dict<char, []> 加上一个indegree的dict<char, int>。
# 建完图之后通过indegree数组检测有没有mutiple root，最后跑一个bfs检测有没有环
# (A,B) (A,C) (B,D)  (D,C) 
# (A,B) (B,D) (D,E) (A,C) (C,F) (E,G)