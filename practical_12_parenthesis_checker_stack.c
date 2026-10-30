/*
 * Practical No. 12:
 * Title: Write a C Program to Implement Parenthesis Checker to Find Correctness of Equation
 *
 * Concept:
 * - Checks whether brackets (), {}, [] in an expression are well-balanced using a Stack.
 * - Opening brackets are pushed onto the stack.
 * - For a closing bracket, the top bracket is popped and checked for a match.
 * - If stack becomes empty after processing and no mismatch occurs, equation is correct.
 */

#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char ch) {
    if (top < MAX - 1) {
        stack[++top] = ch;
    }
}

char pop() {
    if (top >= 0) {
        return stack[top--];
    }
    return '\0';
}

int isMatchingPair(char open, char close) {
    if (open == '(' && close == ')') return 1;
    if (open == '{' && close == '}') return 1;
    if (open == '[' && close == ']') return 1;
    return 0;
}

int checkBalanced(char exp[]) {
    int i;
    char ch;
    top = -1; // Reset stack

    for (i = 0; exp[i] != '\0'; i++) {
        // Push opening brackets
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
            push(exp[i]);
        }
        // Handle closing brackets
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            if (top == -1) {
                // Closing bracket with no opening bracket
                return 0;
            }
            ch = pop();
            if (!isMatchingPair(ch, exp[i])) {
                // Brackets do not match
                return 0;
            }
        }
    }

    // If stack is empty, all brackets were matched
    return (top == -1);
}

int main() {
    char exp[MAX];

    printf("================ PARENTHESIS CHECKER USING STACK ================\n");
    printf("Enter Expression (e.g. (A+B)*(C-D) or [(A+B)*{C-D}]): ");
    scanf("%99s", exp);

    if (checkBalanced(exp)) {
        printf("\nResult: Expression is Correct (Balanced Parentheses).\n");
    } else {
        printf("\nResult: Expression is Incorrect (Unbalanced Parentheses).\n");
    }

    return 0;
}
