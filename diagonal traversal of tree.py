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

def solve_diagonal_traversal(node, state):

    if node == None:
        return

    ordered_map[state].append(node.data)

    if node.left is not None:
        solve_diagonal_traversal(node.left, state+1)

    if node.right is not None:
        solve_diagonal_traversal(node.right, state)


if __name__ == '__main__':

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

    solve_diagonal_traversal(root, 0)

    for k in sorted(ordered_map.keys()):
        for m in range(len(ordered_map[k])):
            print(ordered_map[k][m], end=' ')

        print()

    ordered_map = defaultdict(list)
    print()

    root1 = Node(8);
    root1.left = Node(3);
    root1.right = Node(10);
    root1.left.left = Node(1);
    root1.left.right = Node(6);
    root1.right.right = Node(14);
    root1.right.right.left = Node(13);
    root1.left.right.left = Node(4);
    root1.left.right.right = Node(7);

    solve_diagonal_traversal(root1, 0)

    for k in sorted(ordered_map.keys()):
        for m in range(len(ordered_map[k])):
            print(ordered_map[k][m], end=' ')

        print()
