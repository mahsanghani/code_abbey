# (a) Phone Screen vs. Onsite Format — Research + OOP Design Question Bank

## What the research confirms

**Your recollection was right — the phone screen is NOT guaranteed to be pure DSA.** Formats reported across 2025–2026 candidate write-ups fall into a few buckets:

1. **Classic: 1 hr, 1–2 medium DSA problems, talk-and-code on CoderPad/HackerRank.** Video call (Amazon moved from Chime to Zoom in early 2026); many interviewers keep cameras off. This is still the *most commonly reported* format.
2. **LLD/OOP-flavored screen** — exactly what you experienced with the bidirectional graph. One SDE2 report: *"It's a low-level design round focused on code extensibility and OOP concepts... implemented necessary classes, functions, and performed operations as told."* Another loop reported the phone screen and onsite together spanning "LLD, DSA, HLD, and Leadership Principles" — meaning LLD can land at *either* stage, not exclusively onsite.
3. **Heavier-LP-than-expected, even in "technical" rounds.** Multiple candidates flag this as the biggest surprise: *"I was asked LP questions for almost 30 minutes with a lot of follow-ups. I had very little time for the system design round."* Behavioral content is reported to consume more than half of every round's time — including phone screens. **Every phone screen should be prepped as: 1 technical problem (DSA or OOP/LLD) + 2 LPs with deep follow-ups**, not "just coding."

**Bottom line on structure:** the phone screen is a **compressed, unpredictable sample** of the full loop — it can pull from DSA, LLD, or both, and will *always* carry meaningful LP weight. Prep for phone screen = prep for "any single onsite round," not a separate lighter category.

## Onsite loop shape (for contrast)
Typically 4–6 rounds (~5 hrs total): a coding round or two (DSA), an LLD/OOD round, an HLD/system-design round, and the Bar Raiser (LPs + one DSA/LLD problem, veto power). L5 is expected to be competent in **both** HLD and LLD — L4 candidates reportedly skip system design rounds entirely, so the presence of *any* design round at all is itself an L5 signal.

---

## Common Amazon phone-screen-style OOP/LLD design prompts

Since a graph came up last time, here's a bank organized by data-structure family — the same "prompt → clarify → entities → key method → complexity" flow applies to all of them. These are **short-form** versions suited to a 30–45 min technical slot (as opposed to the fuller Parking-Lot-style prompts in your LLD track, which run closer to 45–60 min).

### Graph-based
- **Design a bidirectional/undirected graph** (your last one) — `addEdge`, `removeEdge`, `getNeighbors`, `isConnected`. Key decision: adjacency list vs. matrix, and how you keep both directions in sync on add/remove.
- **Design a graph that supports both directed and undirected edges** — forces a clean `Edge` abstraction rather than hard-coding symmetry.
- **Design a social network's "friend" graph** — `addFriend`, `areFriends`, `mutualFriends`, `degreesOfSeparation` (BFS to shortest path between two users).
- **Design a course-dependency validator** — essentially 207/210 wrapped in a class (`addCourse`, `addPrerequisite`, `canComplete`, `getOrder`) — ties your topo-sort work directly to an LLD framing.

### Tree-based
- **Design a file system (directory tree)** — `addFile`, `addDirectory`, `getSize` (recursive, bottom-up like your DFS tree work), `find(path)`.
- **Design a trie / autocomplete system** — `insert`, `search`, `startsWith`. Natural bridge from your 208/211 knowledge into a class API.
- **Design an org chart** — `addEmployee(manager)`, `getDirectReports`, `getAllReports` (subtree), `getManagerChain` (path to root).

### Linked-list-based
- **Design a browser history (back/forward)** — doubly linked list, `visit(url)`, `back(steps)`, `forward(steps)`. Classic "linked list as a design problem" — the twist is bounding `steps` correctly.
- **Design a music/video playlist with next/previous and shuffle** — circular doubly linked list; shuffle is the interesting design decision (regenerate order vs. maintain a separate shuffled pointer chain).
- **Design an LRU Cache as a class** (you've done 146 as an algorithm — the LLD framing asks you to also discuss: what if eviction policy needs to be swappable? → Strategy pattern, same as your track's #6).

### Hash-map / set-based
- **Design a rate limiter** (also on your track, #7) — `TokenBucket`/`SlidingWindow` as swappable strategies behind one interface.
- **Design a key-value store with TTL/expiry** — `set(key, val, ttl)`, `get(key)` (lazy vs. active expiry is the design fork).
- **Design a Twitter-like "recent tweets" feed merge** — ties to your heap work (merge k sorted lists of tweets by timestamp) wrapped in a class.

### Heap/priority-based
- **Design a task scheduler with priorities** — `addTask(priority)`, `getNextTask()`, `cancelTask(id)` — cancellation is the interesting wrinkle (lazy deletion from a heap, which you saw in Dijkstra's stale-entry handling).
- **Design a leaderboard** — `addScore`, `getTopK`, `getRank(player)` — heap vs. sorted structure tradeoff discussion.

### General pattern across ALL of these
The interviewer is grading the **same six-step method** from your LLD track regardless of which data structure:
1. Clarify scope (what operations, what scale, thread-safety needed?)
2. Identify entities (nouns → classes)
3. Relationships (has-a / is-a)
4. Behaviors/interfaces (verbs → methods, abstract base where it helps)
5. Pattern if one genuinely fits (Strategy is by far the most common in this list — allocation, eviction, scheduling)
6. Walk a scenario + discuss extensibility ("how would you add X?")

**Prep move:** don't grind these as 12 separate problems. Pick 3–4 (one graph, one tree, one linked-list, one heap) and drill the *method* until it's reflexive — the specific data structure matters less than fluently running the six steps under time pressure in ~30 minutes instead of your track's leisurely 45–60.
