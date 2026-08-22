# Next 5 Weeks — Structured from Your Actual Progress

## Where you actually stand (from practice history + session log)

**Strong / largely locked:**
- Arrays, hashing, sliding window, intervals, two pointers (Weekend 1–2 territory)
- Knapsack DP family (2291, 416, 494, 474, 322, 518) — full three-dial mastery
- Graphs: flood-fill, multi-source BFS (all 4 read-outs), topo sort (both algorithms, both problems, incl. Alien Dictionary), Union-Find (incl. hard 305... marked "didn't make sense," see below), Dijkstra (743, 787, 778, 1631)
- Backtracking: full sweep in one sitting (78, 46, 47, 39, 79, 131)
- Heaps/Top-K: 215, 973, 347, 621, 23
- Design/LLD bridges: 146, 1628, 155, 348
- Binary search family: 704, 33, 81, 875 (incl. the rotated + duplicates progression)
- "Survivor" pattern: 169, 277

**Explicitly flagged as weak / tech debt (your own words):**
- **305 (Number of Islands II)** — "didn't make any sense" — dynamic connectivity, the hardest DSU problem
- **Trees (non-BST)** — 102, 236, 199, 124, 297 — queued twice, never executed (OA tangents and mixed-practice pulled focus both times)
- **Parking Lot LLD** — the canonical whiteboard design problem, queued since early in prep, never attempted
- **LLD only lightly covered beyond the gradeable bridges** — you've never done a pure whiteboard design (Vending Machine, Elevator, Splitwise) from your own track

**New this session:** the phone screen can be OOP/LLD-flavored (not guaranteed DSA), and LP volume is heavier than typical prep assumes, even in technical rounds. Both need dedicated time, not just DSA grinding.

## The prioritization logic

You explicitly asked to "solidify weak concepts and dig deeper into trees and graphs." Reading your history literally: **trees is a true gap** (queued, never done), **graphs has one hard remaining gap** (305 + arguably Advanced Graphs variety), and **LLD is the widest gap of all** (only the LeetCode-gradeable bridges are done — the actual whiteboard-design skill the L5 loop tests has almost no reps). LPs need to shift from "worksheet exists" to "stories are written and follow-up-tested."

Five weeks, each with a clear theme, ending with the two things you can't grind on LeetCode (LLD whiteboard + LP delivery) getting real practice before the loop.

---

## Week 1 — Trees (the true gap), finally executed

- **Mon–Tue:** 102 (Level Order, BFS) → 236 (LCA general tree, DFS) — the two queued from your track, with the templates already written up-thread.
- **Wed:** 199 (Right Side View — one-line variant of 102), 543 (Diameter — DFS-returns-a-value, same shape as 695/1628 you already know)
- **Thu:** 124 (Max Path Sum — DFS-returns-value with a twist: local max vs. global max, the hardest one here)
- **Fri:** 297 (Serialize/Deserialize — genuinely different: encoding + BFS/DFS reconstruction)
- **Weekend:** re-derive all 5 from blank (your standard method), then mixed re-drill: 2–3 random tree problems from the Amazon list to confirm the templates are automatic, not memorized-in-sequence.

**Exit bar:** you can write BFS-level-order and DFS-value-bubbles-up from a blank page without hesitation, on any tree problem, regardless of order asked.

## Week 2 — Graphs: close 305, add Advanced Graphs variety

- **Mon–Tue:** 305 (Number of Islands II) — this time, build it *slowly*: DSU where the grid `(r,c)` maps to a flat index, islands appear incrementally, and you report `count` after each addition. This is "your UnionFind class, applied where the graph itself grows over time" — the mental model shift is the whole problem. Trace 2–3 small examples by hand before coding.
- **Wed:** Redo 547/684/721 cold (no notes) as a speed check — these should now take <10 min each.
- **Thu–Fri:** Advanced Graphs variety you haven't hit: **Path with Minimum Effort** you've done (1631), add **Swim in Rising Water** (778, done) as a pair-check, then **Reconstruct Itinerary** (Eulerian path — genuinely new: DFS with edge-removal, a different graph technique than anything in your kit) and **Min Cost to Connect All Points** (MST via Prim's or Kruskal's — also new, and ties your DSU + heap skills together directly).
- **Weekend:** mixed graph practice from the Amazon list, unlabeled — the retrieval-under-uncertainty rep, now including MST/Eulerian recognition alongside flood-fill/BFS/topo/DSU/Dijkstra.

**Exit bar:** 305 makes sense and you could explain the "grid cell → DSU index" trick to someone else. MST and Eulerian path are at least recognized on sight, even if slower to execute.

## Week 3 — LLD: the widest gap, finally with real reps

This is the week most overdue. Follow your own track (already written, never used beyond the LeetCode bridges):
- **Mon:** Parking Lot (the whiteboard version — multi-level, vehicle hierarchy, Strategy for allocation + pricing). This has been in tech debt the entire prep. Do it for real, sketch classes, bring back for review.
- **Tue:** Vending Machine (State pattern)
- **Wed:** Tic-Tac-Toe LLD framing (you did the algorithm at 348 — now do the *class design* version: separate Board/Player/Game, discuss N×N generalization)
- **Thu:** Elevator System (State + Strategy combined — the hardest one on your track)
- **Fri:** Rate Limiter (Strategy, ties to your new OOP-phone-screen bank from item (a) above)
- **Weekend:** Splitwise (entity-heavy stretch) + re-run the 6-step method cold on one you haven't seen (pull a fresh prompt) to check it's reflexive, not memorized.

**Exit bar:** you can run the 6-step method (clarify → entities → relationships → behaviors → pattern → scenario+extensibility) unprompted, out loud, in ~30–45 min on a prompt you've never seen.

## Week 4 — Integration: mixed DSA + LP + timed OOP phone-screen sim

- **Mon–Wed:** Pure mixed LeetCode practice, unlabeled, pulled from the Amazon-six-months list — 2 problems/day under a 35-min clock (simulating onsite coding rounds), covering whatever patterns come up (this is where trees/graphs/DP/backtracking all get cross-tested together).
- **Thu:** Timed OOP phone-screen simulation — pick 2 prompts from item (a)'s bank (one you haven't drilled), 30 min each, no notes, then review.
- **Fri:** LP story pass — take the 8–10 stories from your worksheet, run each against the L5 bar from item (b), and for 3 of them, do the "5 follow-ups deep" drill (have a partner or run it against me) to pressure-test them the way a Bar Raiser will.
- **Weekend:** light review only — re-derive 3–4 things from tech debt across the whole prep (whatever still feels shaky) rather than new material. Rest matters here.

**Exit bar:** you've simulated the actual mixed pressure of a real round — code + LP in the same session, on the clock — at least twice.

## Week 5 — Full mock loops + targeted patching

- **Mon–Tue:** Two full mock loops (Pramp/interviewing.io/a friend) — each: 1 DSA problem (45 min, narrated) + 2 LP questions with follow-ups. Score yourself: correct solution, clean code, complexity stated, talked the whole time, LP story landed with a clear result + reflection.
- **Wed:** One mock OOP/LLD round (30–45 min) — since you now know this is a real phone-screen possibility, don't let it go untested in mock form.
- **Thu:** Patch whatever the mocks exposed — if it's a specific pattern, drill 2–3 more of that type; if it's LP delivery, rewrite and re-time the weak story.
- **Fri:** Light — one final Parking-Lot-style LLD run-through and a re-skim of your top ~15 "do not walk in without these" LeetCode problems from the original crash course.
- **Weekend before interviews:** rest, sleep, no new material. Confidence at this point should come from volume already banked, not last-minute cramming.

---

## What this deliberately does NOT do
It doesn't re-drill what's already strong (knapsack, flood-fill, backtracking, heaps) — those get one confirmation pass in Week 4's mixed practice and otherwise stay untouched, since re-grinding solid material is the lowest-leverage use of your remaining 5 weeks. Every week targets something in your own history marked incomplete, unclear, or never attempted.
