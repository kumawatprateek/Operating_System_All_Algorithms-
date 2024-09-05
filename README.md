# Operating System Algorithms Repository

Welcome to the **Operating System Algorithms** repository! This repository contains implementations of various fundamental algorithms and techniques used in operating systems. The programs demonstrate different aspects of CPU scheduling, memory management, file allocation, and more. Below is a detailed description of each program included in this repository.

## 1. CPU Scheduling Algorithms

### a. First-Come, First-Served (FCFS)
- **Description**: Implements the FCFS scheduling algorithm where processes are executed in the order they arrive in the ready queue.
- **Key Features**: Simple and easy to understand, but may lead to the "convoy effect."

### b. Shortest Job First (SJF)
- **Description**: Implements the SJF scheduling algorithm where processes with the shortest burst times are executed first.
- **Key Features**: Minimizes average waiting time but can cause starvation of longer processes.

### c. Round Robin (RR)
- **Description**: Implements the Round Robin scheduling algorithm with a fixed time quantum, providing each process a fair share of CPU time in cyclic order.
- **Key Features**: Suitable for time-sharing systems, ensuring responsiveness.

### d. Priority Scheduling (Preemptive)
- **Description**: Implements the preemptive version of Priority Scheduling where processes are executed based on their priority levels.
- **Key Features**: Higher priority processes preempt lower priority ones, useful for systems where priority-based task handling is critical.

## 2. Contiguous Memory Allocation Techniques

### a. Worst-fit
- **Description**: Implements the Worst-fit memory allocation algorithm which allocates the largest available memory block.
- **Key Features**: Aims to minimize fragmentation by using the largest free block.

### b. Best-fit
- **Description**: Implements the Best-fit memory allocation algorithm which allocates the smallest block of memory that fits the requested size.
- **Key Features**: Reduces wasted space but may lead to increased fragmentation.

### c. First-fit
- **Description**: Implements the First-fit memory allocation algorithm which allocates the first block of memory that is large enough.
- **Key Features**: Simple and fast but may lead to fragmentation.

## 3. File Allocation Strategies

### a. Sequential
- **Description**: Implements the Sequential file allocation strategy where files are stored in contiguous blocks.
- **Key Features**: Simple to implement and efficient for sequential access.

### b. Indexed
- **Description**: Implements the Indexed file allocation strategy where an index block contains pointers to the file blocks.
- **Key Features**: Supports efficient random access.

### c. Linked
- **Description**: Implements the Linked file allocation strategy where each file block contains a pointer to the next block.
- **Key Features**: Dynamic block allocation but may have slower access times.

## 4. File Organization Techniques

### a. Single Level Directory
- **Description**: Implements a Single Level Directory for file organization.
- **Key Features**: Simple directory structure but may become cluttered with many files.

### b. Two Level Directory
- **Description**: Implements a Two Level Directory structure that organizes files into subdirectories.
- **Key Features**: Improves organization and manageability.

### c. Hierarchical
- **Description**: Implements a Hierarchical Directory structure with multiple levels of directories.
- **Key Features**: Provides a more organized and scalable file system.

## 5. Banker’s Algorithm for Deadlock Avoidance

- **Description**: Implements the Banker’s Algorithm, which is used to allocate resources to processes while avoiding deadlocks.
- **Key Features**: Ensures that the system remains in a safe state.

## 6. Disk Scheduling Algorithms

### a. Shortest Seek Time First (SSTF)
- **Description**: Implements the SSTF disk scheduling algorithm which selects the request with the shortest seek time.
- **Key Features**: Reduces the average seek time.

### b. SCAN
- **Description**: Implements the SCAN disk scheduling algorithm which moves the disk arm in one direction to service requests and then reverses direction.
- **Key Features**: Provides a more uniform distribution of service.

### c. C-SCAN
- **Description**: Implements the Circular SCAN (C-SCAN) disk scheduling algorithm which moves the disk arm in one direction and then jumps back to the start.
- **Key Features**: Reduces the wait time for requests at the end of the disk.

### d. FCFS
- **Description**: Implements the First-Come, First-Served (FCFS) disk scheduling algorithm where requests are processed in the order they arrive.
- **Key Features**: Simple but may result in less efficient seek times.

## 7. Page Replacement Algorithms

### a. FIFO
- **Description**: Implements the First-In, First-Out (FIFO) page replacement algorithm which replaces the oldest page in memory.
- **Key Features**: Simple but may not always be optimal.

### b. LRU
- **Description**: Implements the Least Recently Used (LRU) page replacement algorithm which replaces the page that has not been used for the longest time.
- **Key Features**: More accurate in predicting which pages will be used in the near future.

### c. OPT
- **Description**: Implements the Optimal (OPT) page replacement algorithm which replaces the page that will not be used for the longest period in the future.
- **Key Features**: Provides the best possible performance but is not feasible in real systems.

## 8. Producer-Consumer Problem Using Semaphores

- **Description**: Implements the Producer-Consumer problem using semaphores to synchronize access to a shared buffer.
- **Key Features**: Demonstrates the use of semaphores for process synchronization.

## 9. Dining-Philosophers Problem

- **Description**: Implements the Dining-Philosophers problem to demonstrate process synchronization and deadlock avoidance strategies.
- **Key Features**: Models a classic synchronization problem with five philosophers sharing chopsticks.

follow on Linkedin- https://www.linkedin.com/in/kumawatprateek/
