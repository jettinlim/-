#https://lenchen.medium.com/leetcode-559-maximum-depth-of-n-ary-tree-d3fb9ed54477   (Really good & fking clean)

class Node(object):
    def __init__(self, val, children):
        self.val = val
        self.children = children
"""
class Solution(object):
    def maxDepth(self, root):
        """
        :type root: Node
        :rtype: int
        """

        # approach: bottom-up recursivly calculate max depth

        if not root:
            return 0

        if not root.children:
            return 1

        return 1 + max([self.maxDepth(node) for node in root.children])
