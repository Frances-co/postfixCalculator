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
    printf("Enter the size of the expression: ");
    scanf("%d", &expressionSize);

    char expression[expressionSize + 1];
    //fflush(stdin);
    getchar();
    //that's better cuz fflush isn't standard and won't work across
    //all compilers.
    //I have to consume the newline character from the scanf above
    //otherwise, it will be added as the first character for the scanf below in the for loop..
    //So every expression will start with a newline character and I don't want that.

    printf("Enter the expression:");
    for(int i=0; i<expressionSize; i++){
        scanf("%c", &expression[i]);
    }
    expression[expressionSize]='\0';


    int spaceIndex = -1;
    stackNode* top = NULL;
    double result = 0, operand2, operand1;

    for (int i = 0; expression[i] != '\0'; i++) {
        switch (expression[i]) {
            case '+':
            case '-':
            case '/':
            case '*':
                if(top!=NULL && top->next!=NULL){
                    operand2 = pop(&top);
                    operand1 = pop(&top);
                    result = doOperation(expression[i], operand1, operand2);
                    push(result, &top);
                    i++;
                    spaceIndex = i;
                }
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
    getchar();
    return 0;
}

void instructions() {
    printf("Enter the size of the expression, including all spaces and operands, followed by the expression itself.\n");
    printf("Ensure each number is separated from operators by a single space.\nExample:9 3 4 * 8 + 4 / -\n");
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
