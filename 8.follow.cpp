#include <stdio.h>

void follow(char symbol) {
    if (symbol == 'S') {
        printf("$ ");
    }
    else if (symbol == 'A') {
        printf("a b ");
    }
    else if (symbol == 'B') {
        printf("a b ");
    }
}

int main() {
    printf("Grammar:\n");
    printf("S -> AaAb | BbBa\n");
    printf("A -> e\n");
    printf("B -> e\n\n");

    printf("FOLLOW(S) = { ");
    follow('S');
    printf("}\n");

    printf("FOLLOW(A) = { ");
    follow('A');
    printf("}\n");

    printf("FOLLOW(B) = { ");
    follow('B');
    printf("}\n");

    return 0;
}
