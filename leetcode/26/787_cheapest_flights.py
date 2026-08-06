"""
LC 787 - Cheapest Flights Within K Stops
Three approaches, instrumented so you can WATCH each one work.

Run:        python3 cheapest_flights.py
Debug:      set a breakpoint (click left of a line number) and press F5 in VS Code
Toggle logs: set VERBOSE = False to silence the step-by-step prints
"""

import heapq
from collections import defaultdict, deque

VERBOSE = True


def log(msg):
    if VERBOSE:
        print(msg)


# ----------------------------------------------------------------------
# Approach 1: BFS level-by-level  (the canonical CORRECT approach for 787)
# Each BFS "level" = one more stop used. We process k+1 levels of edges.
# ----------------------------------------------------------------------
def bfs(n, flights, src, dst, k):
    graph = defaultdict(list)
    for u, v, w in flights:
        graph[u].append((v, w))

    # best[node] = cheapest cost found so far to reach node
    best = [float("inf")] * n
    best[src] = 0
    queue = deque([(src, 0)])            # (node, cost_so_far)
    stops = 0

    log(f"\n=== BFS ===  src={src} dst={dst} k={k}")
    while queue and stops <= k:
        log(f"\n-- level {stops} (stops used) --  frontier size={len(queue)}")
        for _ in range(len(queue)):      # process exactly one level
            node, cost = queue.popleft()
            for nbr, price in graph[node]:
                new_cost = cost + price
                # only enqueue if this is a cheaper way to reach nbr
                if new_cost < best[nbr]:
                    log(f"   relax {node}->{nbr}: {cost}+{price}={new_cost}  "
                        f"(was {best[nbr]})")
                    best[nbr] = new_cost
                    queue.append((nbr, new_cost))
                else:
                    log(f"   skip  {node}->{nbr}: {new_cost} not < best {best[nbr]}")
        stops += 1

    result = best[dst] if best[dst] != float("inf") else -1
    log(f"BFS result: {result}\n")
    return result


# ----------------------------------------------------------------------
# Approach 2: DFS with memo  (recursive: explore paths, cap the stops)
# state = (node, stops_remaining) -> cheapest cost from node to dst
# ----------------------------------------------------------------------
def dfs(n, flights, src, dst, k):
    graph = defaultdict(list)
    for u, v, w in flights:
        graph[u].append((v, w))

    memo = {}
    depth = [0]  # just for pretty-printing indentation

    log(f"\n=== DFS ===  src={src} dst={dst} k={k}")

    def solve(node, stops_left):
        if node == dst:
            return 0
        if stops_left < 0:
            return float("inf")
        if (node, stops_left) in memo:
            log("  " * depth[0] + f"memo hit ({node}, stops_left={stops_left})")
            return memo[(node, stops_left)]

        log("  " * depth[0] + f"visit node={node} stops_left={stops_left}")
        best = float("inf")
        depth[0] += 1
        for nbr, price in graph[node]:
            sub = solve(nbr, stops_left - 1)
            if sub + price < best:
                best = sub + price
        depth[0] -= 1

        memo[(node, stops_left)] = best
        return best

    ans = solve(src, k)           # k stops => k+1 edges => start with k "extra" hops
    result = ans if ans != float("inf") else -1
    log(f"DFS result: {result}\n")
    return result


# ----------------------------------------------------------------------
# Approach 3: Dijkstra-with-stops  (min-heap, but state carries stops)
# THE LESSON: plain Dijkstra by cost alone is WRONG here, because the
# cheapest path may exceed k stops. We add stops to the heap state so we
# don't prune a pricier-but-fewer-stops path that's actually valid.
# ----------------------------------------------------------------------
def dijkstra(n, flights, src, dst, k):
    graph = defaultdict(list)
    for u, v, w in flights:
        graph[u].append((v, w))

    # heap entries: (cost_so_far, node, stops_used)
    heap = [(0, src, 0)]
    # best_stops[node] = fewest stops we've reached `node` with (for pruning)
    best_stops = {}

    log(f"\n=== DIJKSTRA (with stops) ===  src={src} dst={dst} k={k}")
    while heap:
        cost, node, stops = heapq.heappop(heap)
        log(f"\n pop  (cost={cost}, node={node}, stops={stops})")

        if node == dst:                       # first pop of dst = cheapest valid
            log(f" reached dst! cost={cost}")
            log(f"Dijkstra result: {cost}\n")
            return cost
        if stops > k:                         # used too many stops -> dead path
            log(f"   prune: stops {stops} > k {k}")
            continue
        # prune only if we've already reached node with FEWER-or-equal stops
        if node in best_stops and best_stops[node] <= stops:
            log(f"   prune: reached {node} before with <= stops "
                f"({best_stops[node]} <= {stops})")
            continue
        best_stops[node] = stops

        for nbr, price in graph[node]:
            log(f"   push (cost={cost+price}, node={nbr}, stops={stops+1})")
            heapq.heappush(heap, (cost + price, nbr, stops + 1))

    log("Dijkstra result: -1\n")
    return -1


# ----------------------------------------------------------------------
# Test harness
# ----------------------------------------------------------------------
if __name__ == "__main__":
    tests = [
        # (n, flights, src, dst, k, expected)
        (4, [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]], 0, 3, 1, 700),
        (3, [[0,1,100],[1,2,100],[0,2,500]], 0, 2, 1, 200),
        (3, [[0,1,100],[1,2,100],[0,2,500]], 0, 2, 0, 500),
    ]

    for idx, (n, flights, src, dst, k, expected) in enumerate(tests, 1):
        print("#" * 70)
        print(f"TEST {idx}: n={n} src={src} dst={dst} k={k}  expected={expected}")
        print("#" * 70)

        # Silence per-step logs for the summary comparison; flip VERBOSE=True
        # (top of file) to watch any single approach in detail.
        b = bfs(n, flights, src, dst, k)
        d = dfs(n, flights, src, dst, k)
        j = dijkstra(n, flights, src, dst, k)

        print(f"\n  BFS      -> {b}   {'PASS' if b == expected else 'FAIL'}")
        print(f"  DFS      -> {d}   {'PASS' if d == expected else 'FAIL'}")
        print(f"  Dijkstra -> {j}   {'PASS' if j == expected else 'FAIL'}")
        print()