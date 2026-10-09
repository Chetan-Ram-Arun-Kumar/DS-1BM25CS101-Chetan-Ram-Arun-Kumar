#include <stdio.h>
#include <ctype.h>

#define MAX 100

// Stack structure for operators
char stack[MAX];
int top = -1;

// Push operator onto stack
void push(char item) {
    if (top >= MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = item;
}

// Pop operator from stack
char pop() {
    if (top == -1) {
        return -1;
    }
    return stack[top--];
}

// Return the precedence of operators
int precedence(char symbol) {
    switch (symbol) {
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        case '(': return 0;
        default: return -1;
    }
}

// Main logic to convert Infix to Postfix
void infixToPostfix(char infix[], char postfix[]) {
    int i = 0, j = 0;
    char item, x;

    push('(');          // Push opening parenthesis to stack
    // Append closing parenthesis to the end of the infix expression
    while (infix[i] != '\0') {
        i++;
    }
    infix[i] = ')';
    infix[i + 1] = '\0';

    i = 0;
    item = infix[i];

    while (item != '\0') {
        if (item == '(') {
            push(item);
        } 
        else if (isalnum(item)) { // If operand (single character or digit), add to output
            postfix[j++] = item;
        } 
        else if (item == '+' || item == '-' || item == '*' || item == '/') {
            x = pop();
            // Pop operators with higher or equal precedence
            while (precedence(x) >= precedence(item)) {
                postfix[j++] = x;
                x = pop();
            }
            push(x);
            push(item);
        } 
        else if (item == ')') {
            x = pop();
            // Pop until an opening parenthesis is encountered
            while (x != '(') {
                postfix[j++] = x;
                x = pop();
            }
        }
        i++;
        item = infix[i];
    }
    postfix[j] = '\0'; // Null-terminate the postfix string
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter a valid Infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix Expression: %s\n", postfix);
    return 0;
}
