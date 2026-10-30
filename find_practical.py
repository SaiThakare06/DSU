#!/usr/bin/env python3
"""
Practical Topic Finder Script
----------------------------
Usage:
    1) Run interactively:
       python find_practical.py
    2) Run with a search argument directly:
       python find_practical.py "bubble sort"
       python find_practical.py "bitwise"
       python find_practical.py "linked list"
"""

import sys

PRACTICALS = [
    {
        "practical_no": "Practical 1a",
        "part": "A",
        "topic": "Array Operations: Create, Insert, Delete, Display",
        "filename": "practical_01a_array_operations.c",
        "keywords": "array operations create insert delete display traverse linear array size shift"
    },
    {
        "practical_no": "Practical 1b",
        "part": "B",
        "topic": "String Library Functions (strcmp, strlen, strcpy, strrev, strcat, strupr, strlwr, strchr)",
        "filename": "practical_01b_string_functions.c",
        "keywords": "string functions strlen strcmp strcpy strrev strcat strupr strlwr strchr reverse uppercase lowercase concatenate compare length find character"
    },
    {
        "practical_no": "Practical 2a",
        "part": "A",
        "topic": "Checking a Bit at Nth Position (Set or Clear)",
        "filename": "practical_02a_check_bit_nth_position.c",
        "keywords": "bitwise check bit nth position set clear binary and operator bit manipulation mask"
    },
    {
        "practical_no": "Practical 2b",
        "part": "B",
        "topic": "Find Maximum AND Value Produced by Pairwise Elements of an Array",
        "filename": "practical_02b_max_bitwise_and_pair.c",
        "keywords": "bitwise maximum and value pairwise elements array and operator bitwise pair"
    },
    {
        "practical_no": "Practical 2c",
        "part": "C",
        "topic": "Check Whether a Number is Even or Odd Using Bitwise Operator",
        "filename": "practical_02c_even_odd_bitwise.c",
        "keywords": "bitwise even odd check number even or odd lsb least significant bit & 1"
    },
    {
        "practical_no": "Practical 3a",
        "part": "A",
        "topic": "Linear Search on an Array of Numbers",
        "filename": "practical_03a_linear_search_numbers.c",
        "keywords": "linear search numbers array sequential search search key find element"
    },
    {
        "practical_no": "Practical 3b",
        "part": "B",
        "topic": "Linear Search on an Array of Strings",
        "filename": "practical_03b_linear_search_strings.c",
        "keywords": "linear search strings array sequential search strcmp string match"
    },
    {
        "practical_no": "Practical 4a",
        "part": "A",
        "topic": "Binary Search on a Sorted Array of Numbers",
        "filename": "practical_04a_binary_search_numbers.c",
        "keywords": "binary search numbers sorted array divide and conquer low high mid"
    },
    {
        "practical_no": "Practical 4b",
        "part": "B",
        "topic": "Binary Search on an Array of Strings",
        "filename": "practical_04b_binary_search_strings.c",
        "keywords": "binary search strings sorted strings lexicographical strcmp alphabetical"
    },
    {
        "practical_no": "Practical 5a",
        "part": "A",
        "topic": "Bubble Sort on an Array of Numbers",
        "filename": "practical_05a_bubble_sort_numbers.c",
        "keywords": "bubble sort numbers sorting adjacent swap passes ascending order"
    },
    {
        "practical_no": "Practical 5b",
        "part": "B",
        "topic": "Bubble Sort on an Array of Strings",
        "filename": "practical_05b_bubble_sort_strings.c",
        "keywords": "bubble sort strings string sorting lexicographical dictionary order strcmp"
    },
    {
        "practical_no": "Practical 6a",
        "part": "A",
        "topic": "Selection Sort on an Array of Numbers",
        "filename": "practical_06a_selection_sort_numbers.c",
        "keywords": "selection sort numbers sorting minimum element smallest swap unsorted"
    },
    {
        "practical_no": "Practical 6b",
        "part": "B",
        "topic": "Selection Sort on an Array of Strings",
        "filename": "practical_06b_selection_sort_strings.c",
        "keywords": "selection sort strings string sorting lexicographical smallest string swap"
    },
    {
        "practical_no": "Practical 7a",
        "part": "A",
        "topic": "Insertion Sort on an Array of Numbers",
        "filename": "practical_07a_insertion_sort_numbers.c",
        "keywords": "insertion sort numbers sorting key element shift playing cards"
    },
    {
        "practical_no": "Practical 7b",
        "part": "B",
        "topic": "Insertion Sort on an Array of Strings",
        "filename": "practical_07b_insertion_sort_strings.c",
        "keywords": "insertion sort strings string sorting shift strings insert key strcmp"
    },
    {
        "practical_no": "Practical 8",
        "part": "-",
        "topic": "Singly Linked List: Insert at Beginning, End, After, Search, Display",
        "filename": "practical_08_singly_linked_list_insert_search_display.c",
        "keywords": "linked list singly linked list sll insert beginning insert end insert after search display node malloc dynamic memory"
    },
    {
        "practical_no": "Practical 9",
        "part": "-",
        "topic": "Singly Linked List: Delete at Beginning, End, After, Display",
        "filename": "practical_09_singly_linked_list_delete_display.c",
        "keywords": "linked list singly linked list sll delete beginning delete end delete after display free node memory deallocation"
    },
    {
        "practical_no": "Practical 10",
        "part": "-",
        "topic": "Singly Linked List: Search, Merge Two Lists, Count the Nodes",
        "filename": "practical_10_singly_linked_list_search_count_merge.c",
        "keywords": "linked list singly linked list sll search count nodes count length merge two lists combine"
    },
    {
        "practical_no": "Practical 11",
        "part": "-",
        "topic": "Stack Operations: PUSH and POP Using Array",
        "filename": "practical_11_stack_push_pop_array.c",
        "keywords": "stack array push pop display peek lifo top stack overflow stack underflow"
    },
    {
        "practical_no": "Practical 12",
        "part": "-",
        "topic": "Parenthesis Checker to Find Correctness of Equation using Stack",
        "filename": "practical_12_parenthesis_checker_stack.c",
        "keywords": "parenthesis checker stack balanced brackets curly braces expression equation syntax"
    },
    {
        "practical_no": "Practical 13",
        "part": "A & B",
        "topic": "Recursion: (i) Multiplication of Two Numbers, (ii) Reverse String",
        "filename": "practical_13_recursion.c",
        "keywords": "recursion recursive multiplication reverse string recursive addition base condition"
    },
    {
        "practical_no": "Practical 15",
        "part": "-",
        "topic": "Linear Queue Operations: INSERT and DELETE Using Array",
        "filename": "practical_15_linear_queue_array.c",
        "keywords": "queue linear queue enqueue dequeue insert delete fifo front rear queue overflow underflow"
    }
]

def search_topic(query: str):
    query = query.strip().lower()
    if not query:
        print("Please enter a valid topic or keyword.\n")
        return

    matches = []
    for item in PRACTICALS:
        fields = [
            item["practical_no"].lower(),
            item["part"].lower(),
            item["topic"].lower(),
            item["filename"].lower(),
            item["keywords"].lower()
        ]
        if any(query in field for field in fields):
            matches.append(item)

    print("\n" + "=" * 65)
    print(f"SEARCH RESULTS FOR: \"{query}\"")
    print("=" * 65)

    if not matches:
        print(f"No practicals found matching \"{query}\".")
        print("Tip: Try searching by keyword like 'stack', 'bubble', 'linked list', 'string', 'bitwise', 'part a', etc.")
    else:
        for idx, item in enumerate(matches, 1):
            print(f"[{idx}] {item['practical_no']}  |  Part: {item['part']}")
            print(f"    Topic    : {item['topic']}")
            print(f"    File Name: {item['filename']}")
            print("-" * 65)
        print(f"Total matching practical(s): {len(matches)}")

    print("=" * 65 + "\n")

def list_all():
    print("\n" + "=" * 75)
    print(f"{'PRACTICAL':<15} {'PART':<8} {'TOPIC':<38} {'FILE'}")
    print("-" * 75)
    for p in PRACTICALS:
        print(f"{p['practical_no']:<15} {p['part']:<8} {p['topic'][:36]:<38} {p['filename']}")
    print("=" * 75 + "\n")

def main():
    if len(sys.argv) > 1:
        query = " ".join(sys.argv[1:])
        search_topic(query)
        return

    print("=================================================================")
    print("                 DSU PRACTICAL TOPIC FINDER                      ")
    print("=================================================================")
    print("Type any topic, data structure, algorithm, or part (A / B / C).")
    print("Type 'list' to view all practicals, or 'exit' to quit.\n")

    while True:
        try:
            query = input("Enter TOPIC to search: ").strip()
        except (EOFError, KeyboardInterrupt):
            print("\nGoodbye!")
            break

        if not query:
            continue

        if query.lower() in ("exit", "quit", "q"):
            print("Goodbye!")
            break

        if query.lower() in ("list", "all"):
            list_all()
            continue

        search_topic(query)

if __name__ == "__main__":
    main()
