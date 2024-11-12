//If you wanna see the spaghetti steps that I made to make this, check out my dataStructure repository.
//You'll find a more messy code with tons of comments if you're interested.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Stack nodes
typedef struct node {
    double num;
    struct node* next;
} stackNode;

// Function prototypes
double substringToDouble(char* start, char* end);
double doOperation(char operatorr, double operand1, double operand2);
stackNode* push(double x, stackNode** top);
double pop(stackNode** top);
int isOperator(char x);
void instructions();

int main() {
    instructions();

    int expressionSize;
    scanf("%d", &expressionSize);

    char expression[(expressionSize + 1) * 2];
    fflush(stdin);
    scanf("%[^\n]", expression);

    int spaceIndex = -1;
    stackNode* top = NULL;
    double result = 0, operand2, operand1;

    for (int i = 0; expression[i] != '\0'; i++) {
        switch (expression[i]) {
            case '+':
            case '-':
            case '/':
            case '*':
                operand2 = pop(&top);
                operand1 = pop(&top);
                result = doOperation(expression[i], operand1, operand2);
                push(result, &top);
                i++;
                spaceIndex = i;
                break;

            default:
                if (expression[i] == ' ') {
                    if (spaceIndex == -1) {
                        top = push(substringToDouble(&expression[0], &expression[i]), &top);
                    } else {
                        top = push(substringToDouble(&expression[spaceIndex + 1], &expression[i]), &top);
                    }
                    spaceIndex = i;
                }
        }
    }

    printf("%f", result);
    return 0;
}

void instructions() {
    printf("Enter the size of the expression, including all spaces and operands, followed by the expression itself.\n");
    printf("Ensure each number is separated from operators by a single space.\nExample: 9 3 4 * 8 + 4 / -\n");
}

double doOperation(char operatorr, double operand1, double operand2) {
    switch (operatorr) {
        case '+': return operand1 + operand2;
        case '-': return operand1 - operand2;
        case '*': return operand1 * operand2;
        case '/': return operand1 / operand2;
    }
}

stackNode* push(double x, stackNode** top) {
    stackNode* newTop = (stackNode*)malloc(sizeof(stackNode));
    newTop->num = x;
    newTop->next = *top;
    *top = newTop;
    return *top;
}

double pop(stackNode** top) {
    double popMe = (*top)->num;
    stackNode* temp = *top;
    *top = (*top)->next;
    free(temp);
    return popMe;
}

double substringToDouble(char* start, char* end) {
    size_t length = end - start;
    char temp[length + 1];
    strncpy(temp, start, length);
    temp[length] = '\0';
    return strtod(temp, NULL);
}

int isOperator(char x) {
    return (x == '-' || x == '+' || x == '/' || x == '*') ? 1 : 0;
}
