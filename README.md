# Index Creation Using Hashing and Balanced Trees (C++)

A performance-oriented C++ library designed to efficiently index and manage large-scale datasets using a combination of hashing techniques and self-balancing trees (AVL).  
The project focuses on fast lookup times, optimized memory usage, and robust data management under constrained environments, including 32-bit architectures.

---

## Stack
- C++
- Templates and generic programming
- AVL Trees (self-balancing binary search trees)
- Hash tables
- Custom data structures
- Performance optimization
- 32-bit architecture constraints
- Linux development environment

---

## What this project demonstrates
- Design and implementation of **self-balancing tree structures (AVL)**
- Combination of **hashing and balanced trees** for efficient indexing
- Use of **C++ templates** to create reusable, type-safe data structures
- Performance-driven design under **memory and architecture limitations**
- Efficient handling of **large-scale datasets (millions of records)**

---

## Project Overview
The library was developed to address performance bottlenecks in slow-responding databases by introducing a custom indexing mechanism.  
It combines hashing for fast access with AVL trees for ordered data storage and balanced operations, ensuring predictable performance even under heavy data loads.

Key features include:
- Fast insertion, search, and deletion operations
- Balanced tree rotations and reconfiguration
- Custom hash table integration with AVL-based buckets
- Structured data export capabilities

---

## Architecture
The project is organized into modular components, each responsible for a specific aspect of data management:

- **AVL Tree Module**  
  Implements balanced tree logic, including rotations and rebalancing mechanisms.

- **Hash Table Module**  
  Distributes data efficiently while maintaining fast access paths.

- **Template-Based Interfaces**  
  Enable generic programming and reuse across different data types.

- **Data Management Layer**  
  Handles insertion, search, deletion, and export operations.

---

## Performance Results
- Achieved **sub-120ms response times** during search operations
- Efficient data insertion and deletion across large datasets
- Optimized memory usage suitable for **32-bit systems**
- Predictable performance due to balanced tree structures

---

## Use Case
This project demonstrates low-level systems thinking and performance-oriented design, making it relevant for:
- Backend and systems programming
- Performance-critical applications
- Data structure and algorithm-heavy workloads
- Engineering roles requiring strong C++ foundations

---

## Notes
This project was originally developed as part of a long-term academic effort and later refactored and presented as an independent engineering project focused on performance, scalability, and clean design.
