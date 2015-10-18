import sys

"""
Solution is the number of edges in a spanning tree.
We know that it exists, because of the problem constraints
"""
print len(set(sys.stdin.read().replace('-', '\n').strip().split()))-2
