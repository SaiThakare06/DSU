/*
 * Tool: Practical Topic Finder (C Version)
 *
 * Usage:
 *   1) Compile: gcc find_practical.c -o find_practical
 *   2) Run interactively: ./find_practical
 *      or with argument:   ./find_practical "bubble sort"
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    const char *practical_no;
    const char *part;
    const char *topic;
    const char *filename;
    const char *keywords;
} PracticalInfo;

// Database of all lab practicals in this folder
static const PracticalInfo practicals[] = {
    {
        "Practical 1a",
        "A",
        "Array Operations: Create, Insert, Delete, Display",
        "practical_01a_array_operations.c",
        "array operations create insert delete display traverse linear array size shift"
    },
    {
        "Practical 1b",
        "B",
        "String Library Functions (strcmp, strlen, strcpy, strrev, strcat, strupr, strlwr, strchr)",
        "practical_01b_string_functions.c",
        "string functions strlen strcmp strcpy strrev strcat strupr strlwr strchr reverse uppercase lowercase concatenate compare length find character"
    },
    {
        "Practical 2a",
        "A",
        "Checking a Bit at Nth Position (Set or Clear)",
        "practical_02a_check_bit_nth_position.c",
        "bitwise check bit nth position set clear binary and operator bit manipulation mask"
    },
    {
        "Practical 2b",
        "B",
        "Find Maximum AND Value Produced by Pairwise Elements of an Array",
        "practical_02b_max_bitwise_and_pair.c",
        "bitwise maximum and value pairwise elements array and operator bitwise pair"
    },
    {
        "Practical 2c",
        "C",
        "Check Whether a Number is Even or Odd Using Bitwise Operator",
        "practical_02c_even_odd_bitwise.c",
        "bitwise even odd check number even or odd lsb least significant bit & 1"
    },
    {
        "Practical 3a",
        "A",
        "Linear Search on an Array of Numbers",
        "practical_03a_linear_search_numbers.c",
        "linear search numbers array sequential search search key find element"
    },
    {
        "Practical 3b",
        "B",
        "Linear Search on an Array of Strings",
        "practical_03b_linear_search_strings.c",
        "linear search strings array sequential search strcmp string match"
    },
    {
        "Practical 4a",
        "A",
        "Binary Search on a Sorted Array of Numbers",
        "practical_04a_binary_search_numbers.c",
        "binary search numbers sorted array divide and conquer low high mid"
    },
    {
        "Practical 4b",
        "B",
        "Binary Search on an Array of Strings",
        "practical_04b_binary_search_strings.c",
        "binary search strings sorted strings lexicographical strcmp alphabetical"
    },
    {
        "Practical 5a",
        "A",
        "Bubble Sort on an Array of Numbers",
        "practical_05a_bubble_sort_numbers.c",
        "bubble sort numbers sorting adjacent swap passes ascending order"
    },
    {
        "Practical 5b",
        "B",
        "Bubble Sort on an Array of Strings",
        "practical_05b_bubble_sort_strings.c",
        "bubble sort strings string sorting lexicographical dictionary order strcmp"
    },
    {
        "Practical 6a",
        "A",
        "Selection Sort on an Array of Numbers",
        "practical_06a_selection_sort_numbers.c",
        "selection sort numbers sorting minimum element smallest swap unsorted"
    },
    {
        "Practical 6b",
        "B",
        "Selection Sort on an Array of Strings",
        "practical_06b_selection_sort_strings.c",
        "selection sort strings string sorting lexicographical smallest string swap"
    },
    {
        "Practical 7a",
        "A",
        "Insertion Sort on an Array of Numbers",
        "practical_07a_insertion_sort_numbers.c",
        "insertion sort numbers sorting key element shift playing cards"
    },
    {
        "Practical 7b",
        "B",
        "Insertion Sort on an Array of Strings",
        "practical_07b_insertion_sort_strings.c",
        "insertion sort strings string sorting shift strings insert key strcmp"
    },
    {
        "Practical 8",
        "-",
        "Singly Linked List: Insert at Beginning, End, After, Search, Display",
        "practical_08_singly_linked_list_insert_search_display.c",
        "linked list singly linked list sll insert beginning insert end insert after search display node malloc dynamic memory"
    },
    {
        "Practical 9",
        "-",
        "Singly Linked List: Delete at Beginning, End, After, Display",
        "practical_09_singly_linked_list_delete_display.c",
        "linked list singly linked list sll delete beginning delete end delete after display free node memory deallocation"
    },
    {
        "Practical 10",
        "-",
        "Singly Linked List: Search, Merge Two Lists, Count the Nodes",
        "practical_10_singly_linked_list_search_count_merge.c",
        "linked list singly linked list sll search count nodes count length merge two lists combine"
    },
    {
        "Practical 11",
        "-",
        "Stack Operations: PUSH and POP Using Array",
        "practical_11_stack_push_pop_array.c",
        "stack array push pop display peek lifo top stack overflow stack underflow"
    },
    {
        "Practical 12",
        "-",
        "Parenthesis Checker to Find Correctness of Equation using Stack",
        "practical_12_parenthesis_checker_stack.c",
        "parenthesis checker stack balanced brackets curly braces expression equation syntax"
    },
    {
        "Practical 13",
        "A & B",
        "Recursion: (i) Multiplication of Two Numbers, (ii) Reverse String",
        "practical_13_recursion.c",
        "recursion recursive multiplication reverse string recursive addition base condition"
    },
    {
        "Practical 15",
        "-",
        "Linear Queue Operations: INSERT and DELETE Using Array",
        "practical_15_linear_queue_array.c",
        "queue linear queue enqueue dequeue insert delete fifo front rear queue overflow underflow"
    }
};

static const int TOTAL_PRACTICALS = sizeof(practicals) / sizeof(practicals[0]);

// Case-insensitive substring check
int contains_case_insensitive(const char *haystack, const char *needle) {
    char h[512], n[512];
    int i;

    if (!haystack || !needle) return 0;

    for (i = 0; haystack[i] && i < 511; i++) {
        h[i] = (char)tolower((unsigned char)haystack[i]);
    }
    h[i] = '\0';

    for (i = 0; needle[i] && i < 511; i++) {
        n[i] = (char)tolower((unsigned char)needle[i]);
    }
    n[i] = '\0';

    return strstr(h, n) != NULL;
}

// Function to search practicals by topic keyword
void search_topic(const char *query) {
    int matches = 0;
    int i;

    // Trim leading whitespace
    while (isspace((unsigned char)*query)) query++;

    if (strlen(query) == 0) {
        printf("Please enter a non-empty topic keyword.\n");
        return;
    }

    printf("\n======================= SEARCH RESULTS =======================\n");
    printf("Query: \"%s\"\n\n", query);

    for (i = 0; i < TOTAL_PRACTICALS; i++) {
        const PracticalInfo *p = &practicals[i];

        if (contains_case_insensitive(p->practical_no, query) ||
            contains_case_insensitive(p->part, query) ||
            contains_case_insensitive(p->topic, query) ||
            contains_case_insensitive(p->filename, query) ||
            contains_case_insensitive(p->keywords, query)) {

            matches++;
            printf("--------------------------------------------------------------\n");
            printf("[MATCH %d]\n", matches);
            printf("  Practical No : %s\n", p->practical_no);
            printf("  Specific Part: %s\n", p->part);
            printf("  Topic        : %s\n", p->topic);
            printf("  File Name    : %s\n", p->filename);
        }
    }

    if (matches == 0) {
        printf("No practical matched the topic \"%s\".\n", query);
        printf("Tip: Try searching for keywords like 'bubble', 'stack', 'search', 'linked list', 'bitwise', 'queue', 'recursion', 'insert', etc.\n");
    } else {
        printf("--------------------------------------------------------------\n");
        printf("Found %d matching practical(s).\n", matches);
    }
    printf("==============================================================\n\n");
}

int main(int argc, char *argv[]) {
    // If command line argument is provided, search immediately
    if (argc > 1) {
        search_topic(argv[1]);
        return 0;
    }

    // Otherwise, interactive loop
    char query[100];
    printf("==============================================================\n");
    printf("           DSU LAB PRACTICAL TOPIC FINDER                     \n");
    printf("==============================================================\n");
    printf("Type any topic, algorithm, data structure, or part (A/B/C).\n");
    printf("Type 'list' to view all practicals, or 'exit' to quit.\n\n");

    while (1) {
        printf("Enter TOPIC to find: ");
        if (!fgets(query, sizeof(query), stdin)) {
            break;
        }

        // Remove newline character
        query[strcspn(query, "\r\n")] = '\0';

        if (strcmp(query, "exit") == 0 || strcmp(query, "quit") == 0 || strcmp(query, "q") == 0) {
            printf("Goodbye!\n");
            break;
        }

        if (strcmp(query, "list") == 0 || strcmp(query, "all") == 0) {
            int i;
            printf("\n--- ALL AVAILABLE PRACTICALS ---\n");
            for (i = 0; i < TOTAL_PRACTICALS; i++) {
                printf("%-13s [Part %-4s] : %-40s -> %s\n",
                       practicals[i].practical_no,
                       practicals[i].part,
                       practicals[i].topic,
                       practicals[i].filename);
            }
            printf("\n");
            continue;
        }

        if (strlen(query) > 0) {
            search_topic(query);
        }
    }

    return 0;
}
