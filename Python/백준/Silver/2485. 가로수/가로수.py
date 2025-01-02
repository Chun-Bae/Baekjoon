from math import gcd
from functools import reduce

def min_trees_to_add(tree_positions):
    gaps = [tree_positions[i] - tree_positions[i-1] for i in range(1, len(tree_positions))]
    interval_gcd = reduce(gcd, gaps)
    total_new_trees = sum((gap // interval_gcd) - 1 for gap in gaps)
    return total_new_trees

n = int(input())
tree_positions = [int(input()) for _ in range(n)]

print(min_trees_to_add(tree_positions))