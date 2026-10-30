# DSU (Data Structures Using C) - Lab Practicals

A complete, structured collection of **Data Structures Using C** laboratory practicals, implemented in clean, simple, and well-documented C programs.

---

## 📁 Repository Structure & Practical Index

| Practical No. | Specific Part | Description | File Name |
| :--- | :---: | :--- | :--- |
| **Practical 1a** | Part A | Array Operations: Create, Insert, Delete, Display | [`practical_01a_array_operations.c`](practical_01a_array_operations.c) |
| **Practical 1b** | Part B | String Functions: strcmp, strlen, strcpy, strrev, strcat, strupr, strlwr, strchr | [`practical_01b_string_functions.c`](practical_01b_string_functions.c) |
| **Practical 2a** | Part A | Checking a Bit at Nth Position (Set or Clear) | [`practical_02a_check_bit_nth_position.c`](practical_02a_check_bit_nth_position.c) |
| **Practical 2b** | Part B | Maximum Bitwise AND Value Produced by Pairwise Array Elements | [`practical_02b_max_bitwise_and_pair.c`](practical_02b_max_bitwise_and_pair.c) |
| **Practical 2c** | Part C | Check Whether a Number is Even or Odd Using Bitwise Operator | [`practical_02c_even_odd_bitwise.c`](practical_02c_even_odd_bitwise.c) |
| **Practical 3a** | Part A | Linear Search on an Array of Numbers | [`practical_03a_linear_search_numbers.c`](practical_03a_linear_search_numbers.c) |
| **Practical 3b** | Part B | Linear Search on an Array of Strings | [`practical_03b_linear_search_strings.c`](practical_03b_linear_search_strings.c) |
| **Practical 4a** | Part A | Binary Search on an Array of Numbers | [`practical_04a_binary_search_numbers.c`](practical_04a_binary_search_numbers.c) |
| **Practical 4b** | Part B | Binary Search on an Array of Strings | [`practical_04b_binary_search_strings.c`](practical_04b_binary_search_strings.c) |
| **Practical 5a** | Part A | Bubble Sort on an Array of Numbers | [`practical_05a_bubble_sort_numbers.c`](practical_05a_bubble_sort_numbers.c) |
| **Practical 5b** | Part B | Bubble Sort on an Array of Strings | [`practical_05b_bubble_sort_strings.c`](practical_05b_bubble_sort_strings.c) |
| **Practical 6a** | Part A | Selection Sort on an Array of Numbers | [`practical_06a_selection_sort_numbers.c`](practical_06a_selection_sort_numbers.c) |
| **Practical 6b** | Part B | Selection Sort on an Array of Strings | [`practical_06b_selection_sort_strings.c`](practical_06b_selection_sort_strings.c) |
| **Practical 7a** | Part A | Insertion Sort on an Array of Numbers | [`practical_07a_insertion_sort_numbers.c`](practical_07a_insertion_sort_numbers.c) |
| **Practical 7b** | Part B | Insertion Sort on an Array of Strings | [`practical_07b_insertion_sort_strings.c`](practical_07b_insertion_sort_strings.c) |
| **Practical 8**  | - | Singly Linked List: Insert (Beginning, End, After), Search, Display | [`practical_08_singly_linked_list_insert_search_display.c`](practical_08_singly_linked_list_insert_search_display.c) |
| **Practical 9**  | - | Singly Linked List: Delete (Beginning, End, After), Display | [`practical_09_singly_linked_list_delete_display.c`](practical_09_singly_linked_list_delete_display.c) |
| **Practical 10** | - | Singly Linked List: Search, Count Nodes, Merge Two Lists | [`practical_10_singly_linked_list_search_count_merge.c`](practical_10_singly_linked_list_search_count_merge.c) |
| **Practical 11** | - | Stack Operations: PUSH, POP, Display using Array | [`practical_11_stack_push_pop_array.c`](practical_11_stack_push_pop_array.c) |
| **Practical 12** | - | Parenthesis Checker to Find Correctness of Equation using Stack | [`practical_12_parenthesis_checker_stack.c`](practical_12_parenthesis_checker_stack.c) |
| **Practical 13** | Parts A & B | Recursion: (i) Multiplication, (ii) Reverse String | [`practical_13_recursion.c`](practical_13_recursion.c) |
| **Practical 15** | - | Linear Queue Operations: INSERT and DELETE using Array | [`practical_15_linear_queue_array.c`](practical_15_linear_queue_array.c) |

*(Note: Per lab scope, Trees & Graphs practicals are excluded).*

---

## 🔍 Topic Finder Tool

If you want to find which practical contains a specific topic, you can search using either the **Python script** or the **C program**:

### Using Python:
```bash
# Direct keyword search
python find_practical.py "bubble sort"
python find_practical.py "bitwise"
python find_practical.py "linked list"

# Interactive search
python find_practical.py
```

### Using C:
```bash
# Compile
gcc find_practical.c -o find_practical

# Direct keyword search
./find_practical "stack"

# Interactive search
./find_practical
```

---

## 🚀 How to Compile & Run Any Practical

You can compile any practical using GCC:

```bash
# Compile
gcc practical_01a_array_operations.c -o practical_01a

# Run (Windows)
practical_01a.exe

# Run (Linux / macOS)
./practical_01a
```
