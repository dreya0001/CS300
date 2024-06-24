# CS300
CS-300 Analysis and Design
# Course Planner Project

## Project Overview

This project involves developing a software application to assist academic advisors in managing course information. The application can load course data from a file, print a list of all courses in alphanumeric order, and display detailed information about specific courses, including their prerequisites.

## Portfolio Submissions

### Analysis of Run-time and Memory for Data Structures

#### Problem
Evaluated different data structures (vector, hash table, binary search tree) for storing and managing course data.

#### Analysis
- **Vector**: Simple implementation but has O(n) search time, making it less efficient for large datasets.
- **Hash Table**: Offers O(1) average case search and insertion times, suitable for large datasets and fast prerequisite checking.
- **Binary Search Tree**: Provides O(log n) search time but degrades to O(n) in the worst case. Useful for ordered traversal.

#### Recommendation
The hash table was recommended for its efficiency in search and insertion operations, crucial for the application requirements.

### Working Code to Sort and Print Course List

#### Problem
Developed code to load course data, sort it alphanumerically and print the sorted list.

#### Implementation
- **Data Loading**: Reads data from a file and stores it in an unordered_map.
- **Sorting**: Extracts course numbers, sorts them, and prints the sorted list.
- **Course Information**: Prints detailed information about a course, including prerequisites.

## Reflection

### Problem Solving
Addressed the need for efficient data management using appropriate data structures.

### Approach
Choose a hash table for its average-case constant time operations, ensuring efficient data retrieval and insertion.

### Roadblocks
Overcame challenges in file handling, data parsing, and ensuring efficient data retrieval using documentation, peer advice, and debugging techniques.

### Software Design
Emphasized the importance of selecting suitable data structures, planning, and designing before coding.

### Code Maintainability
Focused on clear naming conventions, modularization, in-line comments, and comprehensive error handling to produce maintainable, readable, and adaptable code.

## Conclusion

This project showcases my ability to apply data structures and algorithms to solve real-world problems effectively, emphasizing efficiency, scalability, and maintainability in software development.
