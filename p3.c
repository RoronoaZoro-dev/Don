#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 5

struct BOOK {
    int ISBN;
    char title[50];
    char author[50];
    float price;
};

struct stack {
    struct BOOK b[SIZE];
    int top;
};

void push(struct stack *ps, struct BOOK b1);
struct BOOK pop(struct stack *ps);
void display(struct stack *ps);

void main() {
    struct stack s;
    struct BOOK b1, r1;
    int choice;
    s.top = -1;

    do {
        printf("\n1: PUSH\t 2: POP\t 3: DISPLAY\t 4: QUIT");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the ISBN, title, author, and price of the book to push:\n");
                scanf("%d", &b1.ISBN);
                getchar();
                printf("Enter Title: ");
                fgets(b1.title, sizeof(b1.title), stdin);
                b1.title[strcspn(b1.title, "\n")] = '\0';

                printf("Enter Author: ");
                fgets(b1.author, sizeof(b1.author), stdin);
                b1.author[strcspn(b1.author, "\n")] = '\0';

                printf("Enter Price: ");
                scanf("%f", &b1.price);

                push(&s, b1);
                break;

            case 2:
                r1 = pop(&s);
                printf("The details of BOOK popped are:\n");
                printf("ISBN = %d, Title = %s, Author = %s, Price = %f\n",
                       r1.ISBN, r1.title, r1.author, r1.price);
                break;

            case 3:
                display(&s);
                break;

            case 4:
                printf("\nQuitting operation stack\n");
                break;

            default:
                printf("No such option\n");
                break;
        }
    } while (choice != 4);
}

void push(struct stack *ps, struct BOOK b1) {
    if (ps->top == SIZE - 1) {
        printf("Stack Overflow\n");
    } else {
        ++(ps->top);
        ps->b[ps->top] = b1;
        printf("Book pushed onto the stack.\n");
    }
}

struct BOOK pop(struct stack *ps) {
    struct BOOK r;
    if (ps->top == -1) {
        printf("\nStack Underflow\n");
        exit(1);
    } else {
        r = ps->b[ps->top];
        (ps->top)--;
        return r;
    }
}

void display(struct stack *ps) {
    int i;
    if (ps->top == -1) {
        printf("\nStack is empty\n");
    } else {
        printf("Stack contents are:\n");
        for (i = ps->top; i >= 0; i--) {
            printf("ISBN = %d, Title = %s, Author = %s, Price = %.2f\n",
                   ps->b[i].ISBN, ps->b[i].title, ps->b[i].author, ps->b[i].price);
        }
    }
}