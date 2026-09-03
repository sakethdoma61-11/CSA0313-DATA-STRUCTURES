# University Course Prerequisite Management Using Topological Sorting

## Course
CSA03 – Data Structures – Slot D

## Problem Statement
University courses often have prerequisite relationships. A directed graph represents these dependencies, where each vertex is a course and `u -> v` means `u` must be completed before `v`.

## Course Mapping
0 PF – Programming Fundamentals; 1 DS – Data Structures; 2 ALG – Algorithms; 3 DBMS – Database Management Systems; 4 CN – Computer Networks; 5 OS – Operating Systems; 6 AI – Artificial Intelligence; 7 ML – Machine Learning.

## Prerequisite Edges
PF -> DS, PF -> DBMS, DS -> ALG, DS -> OS, DBMS -> AI, ALG -> AI, CN -> OS, OS -> ML, AI -> ML.

## Algorithms
**BFS-based Kahn's Algorithm:** calculate indegrees, queue all zero-indegree courses, remove courses and decrease dependent indegrees. A course enters the queue when its indegree becomes zero.

**DFS-based Topological Sort:** use states 0 (unvisited), 1 (visiting), and 2 (visited). A visiting-to-visiting edge detects a cycle. Finished courses are pushed onto a stack; popping the stack gives a valid order.

## Valid Orders
BFS: `PF -> CN -> DS -> DBMS -> ALG -> OS -> AI -> ML`

DFS: `CN -> PF -> DBMS -> DS -> OS -> ALG -> AI -> ML`

Different valid topological orders are possible when prerequisite constraints are still satisfied.

## Cycle Detection
Example cycle: `DS -> ALG -> AI -> ML -> DS`. Such a cycle means no course in the cycle can be scheduled first, so registration cannot produce a valid order.

## Complexity
With an adjacency-list representation: **O(V + E)** time and **O(V)** auxiliary space for both methods. The demonstration C program uses an adjacency matrix for this small fixed graph.

## Files
- `course_prerequisite.c` – C implementation
- `sample_input.txt` – graph description
- `sample_output.txt` – expected output
- `README.md` – documentation

## Compilation
`gcc course_prerequisite.c -o course_prerequisite`

## Applications
University course registration, prerequisite validation, semester planning, curriculum dependency checking, and academic progression planning.

## SDG Mapping
**SDG 4 – Quality Education** and **SDG 9 – Industry, Innovation and Infrastructure**.

## Team
Doma Saketh – 192525018; N. Sai Charan – 192525247; G. Nikhil – 192525393; V Bharathwaj Reddy – 192372213.
