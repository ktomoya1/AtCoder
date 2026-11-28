import sys
import math
from bisect import bisect_left, bisect_right
from collections import Counter, defaultdict, deque
from functools import lru_cache
from heapq import heappop, heappush
from itertools import accumulate, combinations, permutations, product

#from atcoder.dsu import DSU
#from atcoder.fenwicktree import FenwickTree
#from atcoder.lazysegtree import LazySegTree
#from atcoder.segtree import SegTree

input = sys.stdin.readline


def main():
    n = int(input())
    s = input().rstrip()
    answer = []
    for c in s:
        if c == 'A': answer.append("Alpha")
        elif c == 'B': answer.append("Bravo")
        else: answer.append("Charlie")
    print(*answer)
    pass


if __name__ == "__main__":
    main()
