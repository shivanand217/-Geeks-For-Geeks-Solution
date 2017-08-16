from collections import defaultdict

class Node:
    def __init__(self, key):
        self.data = key
        self.left = None
        self.right = None

def inorder(node):

    if node == None:
        return

    inorder(node.left)
    print(node.data, end=' ')
    inorder(node.right)

def solve_vertical_order(root, direction):

    if root == None:
        return

    ordered_map[direction].append(root.data)

    if root.left is not None:
        solve_vertical_order(root.left, direction-1)

    if root.right is not None:
        solve_vertical_order(root.right, direction+1)

    

if __name__ == "__main__":
    
    global ordered_map
    
    ordered_map = defaultdict(list)

    root = Node(1)
    root.left = Node(2)
    root.right = Node(3)
    root.left.left = Node(4)
    root.left.right = Node(5)
    root.right.left = Node(6)
    root.right.right = Node(7)
    root.right.left.right = Node(8)
    root.right.right.right = Node(9)

    # inorder(root)
    solve_vertical_order(root, 0)

    #for k in ordered_map.keys():
     #   print(ordered_map[k])

    for k in sorted(ordered_map.keys()):
        for m in range(len(ordered_map[k])):
            print(ordered_map[k][m], end=' ')

        print()  
