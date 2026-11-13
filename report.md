# Algorithm Battle – Which Data Structure Wins?

## Library Book Management System

**Student Name:** Jeevan Gowda  
**Registration Number:** RA2511026050191  
**Programming Language:** C  
**Application:** Library Book Management System

## 1. Introduction

The Library Book Management System stores and searches book records using three different data structures:

1. Binary Search Tree (BST)
2. AVL Tree
3. Hashing with Linear Probing

The objective is to compare their searching performance, tree heights, and collision handling.

## 2. Dataset

- Total initial book records: 40
- Book IDs: 2001 to 2040
- New book ID used for insertion experiment: 2050
- Hash table size: 53
- Collision handling method: Linear Probing

## 3. Operations Implemented

- Insertion of book records
- Successful searching
- Unsuccessful searching
- Inorder traversal
- Preorder traversal
- Postorder traversal
- AVL rotations and balancing
- Hash collision handling using linear probing

## 4. Experimental Results

### Successful Search

Search key: 2020

| Data Structure | Comparisons |
|---|---:|
| BST | 20 |
| AVL Tree | 4 |
| Hashing | 1 |

### Unsuccessful Search

Search key: 9999

| Data Structure | Comparisons |
|---|---:|
| BST | 40 |
| AVL Tree | 6 |
| Hashing | 1 |

### Tree Height and Collisions

| Measurement | Result |
|---|---:|
| BST Height | 40 |
| AVL Tree Height | 6 |
| Hashing Collisions | 0 |

### Insertion Experiment

New book ID: 2050

The program successfully inserted the new book into all three data structures.

| Data Structure | Search Comparisons |
|---|---:|
| BST | 41 |
| AVL Tree | 6 |
| Hashing | 1 |

Hash collisions after insertion: 0.

## 5. Analysis

The BST required more comparisons because the records were inserted in sorted order. This created an unbalanced tree with a height of 40.

The AVL Tree performed better because it automatically balances itself using rotations. Its height was only 6, resulting in fewer comparisons.

Hashing performed best in this experiment. It required only one comparison for the tested successful and unsuccessful searches. No collisions occurred because the selected hash function distributed these book IDs across different initial positions in the hash table.

## 6. Conclusion

Based on the experimental results, **Hashing with Linear Probing** performed best for searching book records in this particular dataset.

The AVL Tree is also efficient and is useful when sorted data and tree traversal are required.

The ordinary BST performed poorly because the records were inserted in sorted order, creating an unbalanced tree.

Therefore, hashing is the winner for search efficiency in this experiment, while AVL Tree is a good choice when ordered traversal is important.

## 7. Final Recommendation

For a Library Book Management System that mainly requires fast book ID searching, hashing with linear probing is recommended based on this experiment.

The experiment demonstrates that the performance of a data structure depends on the insertion order, balancing mechanism, and hash function.
