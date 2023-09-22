# Operating-Systems-IUST
My solutions to IUST's Operating Systems, Fall 2022, Dr. Entezari.

## <img width="20" height="20" src="https://img.icons8.com/wired/64/41b883/class.png" alt="class"/> Class Activities
### CA1 
- Description: Materials related to understanding the fundamentals of the C programming language.
- Code: [Link to CA1](https://github.com/lelnazrezaeel/Operating-Systems-IUST/tree/main/Class%20Activities/CA1)

### CA2 
- Description: Materials focused on comprehending the concept of fork in operating systems.
- Answers: [Link to CA2](https://github.com/lelnazrezaeel/Operating-Systems-IUST/tree/main/Class%20Activities/CA2)

### CA3 
- Description: Short research materials on Shared Mutex in concurrent programming.
- Answers: [Link to CA3](https://github.com/lelnazrezaeel/Operating-Systems-IUST/tree/main/Class%20Activities/CA3)

## <img width="20" height="20" src="https://img.icons8.com/ios/50/41b883/homework.png" alt="homework"/> Homeworks
### Practical Homeworks
- Description: Implementation-based homework assignments.
- Code: [Link to Practical Homeworks](https://github.com/lelnazrezaeel/Operating-Systems-IUST/tree/main/Homeworks/Practical)
  - HW1: [Pointer to Function](https://github.com/lelnazrezaeel/Operating-Systems-IUST/tree/main/Homeworks/Practical/HW1)
  - HW2: [Process Familiarity](https://github.com/lelnazrezaeel/Operating-Systems-IUST/tree/main/Homeworks/Practical/HW2)
  - HW3: [Distributed Merge-Sort](https://github.com/lelnazrezaeel/Operating-Systems-IUST/tree/main/Homeworks/Practical/HW3)
  - HW4: [Simple Logger](https://github.com/lelnazrezaeel/Operating-Systems-IUST/tree/main/Homeworks/Practical/HW4)

### Theory Homeworks
- Description: Theory-based homework assignments.
- Answers: [Link to Theory Homeworks](https://github.com/lelnazrezaeel/Operating-Systems-IUST/tree/main/Homeworks/Theory)
  - HW1: [Processes](https://github.com/lelnazrezaeel/Operating-Systems-IUST/tree/main/Homeworks/Theory/HW1)
  - HW2: [Threads & Concurrency](https://github.com/lelnazrezaeel/Operating-Systems-IUST/tree/main/Homeworks/Theory/HW2)
  - HW3: [CPU Scheduling](https://github.com/lelnazrezaeel/Operating-Systems-IUST/tree/main/Homeworks/Theory/HW3)
  - HW4: [Virtual Memory](https://github.com/lelnazrezaeel/Operating-Systems-IUST/tree/main/Homeworks/Theory/HW4)

## <img width="20" height="20" src="https://img.icons8.com/external-smashingstocks-mixed-smashing-stocks/68/41b883/external-Notes-work-from-home-smashingstocks-mixed-smashing-stocks-2.png" alt="Notes"/> Notes
- Description: Lecture slides and materials provided by the professor.
- [Link to Notes](https://github.com/lelnazrezaeel/Operating-Systems-IUST/tree/main/Notes)

## <img width="20" height="20" src="https://img.icons8.com/ios/50/41b883/project.png" alt="project"/> Project
### Ph1 - Project Definition
- Description: In this phase, a new system call called "dump_proc" is added to the 6Xv operating system. The dump_proc system call provides information about running and runnable processes to the user as an array of "info_proc" structures, sorted by the "memsize" field. This phase involves defining the system call and creating a user-level program to test it.
- Code: [Link to Ph1](https://github.com/lelnazrezaeel/Operating-Systems-IUST/tree/main/Project/Ph1)

### Ph2 - Project Implementation
- Description: This phase involves the implementation of various aspects.
  - Part1: System Call Expansion - Expands the "proc" structure in the 6Xv codebase by adding new fields: stime, etime, iotime, and rtime. These fields track various aspects of a process's execution time.
    - Code: [Link to Part1](https://github.com/lelnazrezaeel/Operating-Systems-IUST/tree/main/Project/Ph2/Part1)
  - Part2: Waitx System Call - Introduces the "waitx" system call to extract specific information about a process's runtime and waiting time.
    - Code: [Link to Part2](https://github.com/lelnazrezaeel/Operating-Systems-IUST/tree/main/Project/Ph2/Part2)
  - Part3: Scheduler Implementation - Modifies the scheduler in 6Xv to implement a priority-based scheduling algorithm. Processes with higher priority are given preference.
    - Code: [Link to Part3](https://github.com/lelnazrezaeel/Operating-Systems-IUST/tree/main/Project/Ph2/Part3)
  - Part3-2: Multi-Level Queue - Implements a multi-level queue with three separate queues, each with a different priority level. The highest-priority queue uses a guaranteed fairness scheduling policy.
    - Code: [Link to Part3-2](https://github.com/lelnazrezaeel/Operating-Systems-IUST/tree/main/Project/Ph2/Part3-2)
