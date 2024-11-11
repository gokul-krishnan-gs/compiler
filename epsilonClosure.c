#include <stdio.h>
#include <string.h>

char eclosure[20][20], states[10], sym[3] = "01", st[20][20];

int main() {
    int i, nt, k, j;
    char state, state1, state2, input;
    printf("\nEnter the number of states: ");
    scanf("%d", &i);

    printf("\nEnter the number of transitions: ");
    scanf("%d", &nt);

    printf("\nEnter the states: ");
    scanf("%s", states);

    printf("\nEnter the transitions in the format 'state input nextstate' (e.g., 'A0B'):\n");
    for (j = 0; j < nt; j++) {
        scanf("%s", st[j]);
    }

    for (i = 0; i < strlen(states); i++) {
        k = 0;
        printf("\ne-closure of %c is {", states[i]);

        state = states[i];
        eclosure[i][k++] = state;
        eclosure[i][k++] = ',';   

        for (j = 0; j < nt; j++) {
            state1 = st[j][0];
            input = st[j][1];
            state2 = st[j][2];

        
            if (state == state1 && input == 'e') {
               
                int duplicate = 0;
                for (int a = 0; a < k; a++) {
                    if (eclosure[i][a] == state2) {
                        duplicate = 1;
                        break;
                    }
                }
                if (!duplicate) {
                    eclosure[i][k++] = state2;
                    eclosure[i][k++] = ',';
                    state = state2;
                }
            }
        }

        eclosure[i][k - 1] = '\0';  
        printf("%s}", eclosure[i]);
        printf("\n");
    }

    return 0;
}


/*

Enter the number of states: 3

Enter the number of transitions: 6

Enter the states: ABC

Enter the transitions in the format 'state input nextstate' (e.g., 'A0B'):
AeB
AeC
B1B
BeC
C0C
C1C

e-closure of A is {A,B,C}

e-closure of B is {B,C}

e-closure of C is {C}


or

Enter the number of states: 4
Enter the number of transitions: 5
Enter the states: PQRS
Enter the transitions in the format 'state input nextstate' (e.g., 'A0B'):
P e Q
Q e R
R e S
S 1 P
P 0 R

e-closure of P is {P, Q, R, S}
e-closure of Q is {Q, R, S}
e-closure of R is {R, S}
e-closure of S is {S}


*/
