#include <stdio.h>
#include <stdlib.h>
 
// Define the structure for a polynomial term
typedef struct Term {
    int coeff;  // Coefficient
    int exp;    // Exponent
    struct Term* next;
} Term;
 
// Function to create a new term
Term* createTerm(int coeff, int exp) {
    Term* newTerm = (Term*)malloc(sizeof(Term));
    newTerm->coeff = coeff;
    newTerm->exp = exp;
    newTerm->next = NULL;
    return newTerm;
}
 
// Function to add a term to the polynomial
void addTerm(Term** poly, int coeff, int exp) {
    Term* newTerm = createTerm(coeff, exp);
    if (*poly == NULL) {
        *poly = newTerm;
    } else {
        Term* temp = *poly;
        Term* prev = NULL;
        while (temp != NULL && temp->exp > exp) {
            prev = temp;
            temp = temp->next;
        }
        if (temp != NULL && temp->exp == exp) {
            temp->coeff += coeff;
        } else {
            if (prev == NULL) {
                newTerm->next = *poly;
                *poly = newTerm;
            } else {
                newTerm->next = temp;
                prev->next = newTerm;
            }
        }
    }
}
 
// Function to add two polynomials
Term* addPolynomials(Term* poly1, Term* poly2) {
    Term* result = NULL;
    Term* p1 = poly1;
    Term* p2 = poly2;
 
    while (p1 != NULL && p2 != NULL) {
        if (p1->exp == p2->exp) {
            addTerm(&result, p1->coeff + p2->coeff, p1->exp);
            p1 = p1->next;
            p2 = p2->next;
        } else if (p1->exp > p2->exp) {
            addTerm(&result, p1->coeff, p1->exp);
            p1 = p1->next;
        } else {
            addTerm(&result, p2->coeff, p2->exp);
            p2 = p2->next;
        }
    }
 
    while (p1 != NULL) {
        addTerm(&result, p1->coeff, p1->exp);
        p1 = p1->next;
    }
 
    while (p2 != NULL) {
        addTerm(&result, p2->coeff, p2->exp);
        p2 = p2->next;
    }
 
    return result;
}
 
// Function to display a polynomial
void displayPolynomial(Term* poly) {
    Term* temp = poly;
    while (temp != NULL) {
        printf("%dx^%d", temp->coeff, temp->exp);
        if (temp->next != NULL) {
            printf(" + ");
        }
        temp = temp->next;
    }
    printf("\n");
}
 
int main() {
    Term* poly1 = NULL;
    Term* poly2 = NULL;
 
    // Polynomial 1: 5x^3 + 4x^2 + 2x^1 + 1
    addTerm(&poly1, 5, 3);
    addTerm(&poly1, 4, 2);
    addTerm(&poly1, 2, 1);
    addTerm(&poly1, 1, 0);
 
    // Polynomial 2: 3x^3 + 3x^2 + 2
    addTerm(&poly2, 3, 3);
    addTerm(&poly2, 3, 2);
    addTerm(&poly2, 2, 0);
 
    printf("Polynomial 1: ");
    displayPolynomial(poly1);
 
    printf("Polynomial 2: ");
    displayPolynomial(poly2);
 
    Term* result = addPolynomials(poly1, poly2);
 
    printf("Resultant Polynomial: ");
    displayPolynomial(result);
 
    // Free the allocated memory
    while (poly1 != NULL) {
        Term* temp = poly1;
        poly1 = poly1->next;
        free(temp);
    }
    while (poly2 != NULL) {
        Term* temp = poly2;
        poly2 = poly2->next;
        free(temp);
    }
    while (result != NULL) {
        Term* temp = result;
        result = result->next;
        free(temp);
    }
 
    return 0;
}