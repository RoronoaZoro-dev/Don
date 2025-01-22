#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

struct node { 
int coefficient;    
int x_power;        
int y_power;        
int z_power;        
struct node* next;
}; 
typedef struct node *NODEPTR;

NODEPTR createNode(int coeff, int x, int y, int z); 
NODEPTR insertEnd(NODEPTR list, int coeff, int x, int y, int z);
void displayPolynomial(NODEPTR list);
double evaluatePolynomial(NODEPTR list, double x, double y, double z);

NODEPTR createNode(int coeff, int x, int y, int z) { 
NODEPTR p = (NODEPTR)malloc(sizeof(struct node));  
p->coefficient = coeff;
p->x_power = x;          
p->y_power = y;      
p->z_power = z;          
p->next = p;           
return p;               
} 
NODEPTR insertEnd(NODEPTR list, int coeff, int x, int y, int z) { 
NODEPTR p = createNode(coeff, x, y, z); 
if (list == NULL) {  
list = p;       
} else {      
NODEPTR q = list;
while (q->next != list) {
q = q->next; 
} 
q->next = p;  
p->next = list;
} 
return list;
} 
void displayPolynomial(NODEPTR list) { 
if (list == NULL) {  
printf("Polynomial is empty.\n"); 
return; 
} 
NODEPTR p = list; 
do { 
printf("%+dx^%dy^%dz^%d ", p->coefficient, p->x_power, p->y_power, p->z_power); 
p = p->next;
} while (p != list);
printf("\n");  
} 

double evaluatePolynomial(NODEPTR list, double x, double y, double z) { 
double result = 0.0; 
if (list == NULL) { 
return result; 
} 
NODEPTR q = list;
do { 
result += q->coefficient * pow(x, q->x_power) * pow(y, q->y_power) * pow(z, q->z_power); 
q = q->next;
} while (q != list);
return result; 
} 

int main() { 
NODEPTR poly = NULL;

poly = insertEnd(poly, 6, 2, 2, 1);  
poly = insertEnd(poly, -4, 0, 1, 5); 
poly = insertEnd(poly, 3, 3, 1, 1); 
poly = insertEnd(poly, 2, 1, 5, 1); 
poly = insertEnd(poly, -2, 1, 1, 3); 
printf("Polynomial: "); 
displayPolynomial(poly); 
double x, y, z;
printf("\nEnter values for x, y, z: "); 
scanf("%lf %lf %lf", &x, &y, &z);  
double result = evaluatePolynomial(poly, x, y, z);
printf("Result of evaluation: %.2lf\n", result);
return 0;  
}