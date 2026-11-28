import sys
import math
from bisect import bisect_left, bisect_right
from collections import Counter, defaultdict, deque
from functools import lru_cache
from heapq import heappop, heappush
from itertools import accumulate, combinations, permutations, product

from atcoder.dsu import DSU
from atcoder.fenwicktree import FenwickTree
from atcoder.lazysegtree import LazySegTree
from atcoder.segtree import SegTree

input = sys.stdin.readline


def main():
    n, m = (int(x) for x in input().split())
    a = set(map(int, input().split()))
    for i in range(m):
        x, y = (int(a) for a in input().split())
        a.add(y)
        a.remove(x)
    answer = sorted(a)
    print(*answer)
    pass


if __name__ == "__main__":
    main()
