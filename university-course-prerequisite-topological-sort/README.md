# University Course Prerequisite System Using Topological Sort

## Course
CSA03 – Data Structures

## Objective
To represent university course prerequisites using a directed graph and generate a valid course-taking order using Topological Sort.

## Algorithms Used
1. BFS-based Topological Sort using Kahn's Algorithm
2. DFS-based Topological Sort
3. Cycle Detection

## Graph Representation
Each course is represented as a vertex and each prerequisite relationship is represented as a directed edge.

For example:

Programming Fundamentals → Data Structures
Data Structures → Algorithms
Algorithms → Machine Learning

## Course Mapping

0 - Programming Fundamentals
1 - Data Structures
2 - Algorithms
3 - Database Systems
4 - Machine Learning
5 - Big Data Analytics
6 - Artificial Intelligence
7 - Deep Learning

## How to Run

Compile:

gcc course_prerequisite.c -o course_prerequisite

Run:

./course_prerequisite

## Sample Result

BFS (Kahn's Algorithm) Topological Order:
0 1 2 3 4 5 6 7

DFS Topological Order:
0 1 3 5 2 4 6 7

Both orders satisfy the prerequisite constraints.

## Cycle Detection

If the prerequisite graph contains a cycle, the program displays:

Cycle detected. No valid course order exists.

## Complexity

Time Complexity: O(V + E)

Space Complexity: O(V)

## Applications

- University course registration
- Academic planning
- Curriculum dependency validation
- Prerequisite management

## SDG Mapping

SDG 4 – Quality Education

SDG 9 – Industry, Innovation and Infrastructure
