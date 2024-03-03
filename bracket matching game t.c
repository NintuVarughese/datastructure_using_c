/* which is a bracket matching game to provide
an interactive and educational tool that helps users to understand and
practice matching and balancing bracket within a expression*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
//define a node structure
typedef struct Node {
char data;
struct Node* next;
} Node;
//define linked stack structure
typedef struct {
Node* top;
} LinkedStack;
//initialize the linked stack
void initialize(LinkedStack *stack) {
stack->top = NULL;
}

//check if linked stack is empty
int isEmpty(LinkedStack *stack) {
return stack->top == NULL;
}
//pushing element
void push(LinkedStack *stack, char value) {
//allocate memmory for new node
Node* newNode = (Node*)malloc(sizeof(Node));
if (newNode == NULL) {
printf("Memory allocation failed\n");
exit(EXIT_FAILURE);
}
newNode->data = value;
newNode->next = stack->top;
stack->top = newNode;
}
//pop an element from linked stack
char pop(LinkedStack *stack) {
if (isEmpty(stack)) {
printf("Stack underflow!\n");
exit(EXIT_FAILURE);

}
//remove top node from stack
Node* temp = stack->top;
char poppedValue = temp->data;
stack->top = temp->next;
free(temp);
return poppedValue;
}
//check if bracket form valid pair
bool isBracketMatched(char open, char close) {
return (open == '(' && close == ')') ||
(open == '[' && close == ']') ||
(open == '{' && close == '}');
}
//check expression has balaced bracket
bool checkBracketMatching(const char *expression) {
LinkedStack stack;
initialize(&stack);

int length = strlen(expression);

for (int i = 0; i < length; i++) {

if (expression[i] == '(' || expression[i] == '[' || expression[i] == '{') {
push(&stack, expression[i]);
} else if (expression[i] == ')' || expression[i] == ']' || expression[i] ==
'}') {
if (isEmpty(&stack) || !isBracketMatched(pop(&stack),
expression[i])) {
return false;
}
}
}

return isEmpty(&stack);
}
int main() {
char expression[100];
printf("Bracket Matching Game\n");
printf("Enter an expression: ");
scanf("%s", expression);
if (checkBracketMatching(expression)) {
printf("Brackets are properly matched and balanced.\n");
} else {
printf("Brackets are not properly matched and balanced.\n");
} return 0;

}