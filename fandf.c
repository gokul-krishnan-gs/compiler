#include <stdio.h>
#include <string.h>
#include <ctype.h>

int n;
char a[10][10], f[10];
int m = 0;

void follow(char c);
void first(char c);
int isPresent(char arr[], char c);
void addUnique(char arr[], char c);

int main() {
    int i, z;
    char c;
    printf("Enter the number of productions: \n");
    scanf("%d", &n);
    printf("Enter the productions: \n");
    for (i = 0; i < n; i++) {
        scanf("%s", a[i]);
    }

    do {
        m = 0;
        memset(f, '\0', sizeof(f));
        printf("Enter the element whose First and Follow sets are to be found: ");
        scanf(" %c", &c);  

        first(c);
        printf("First(%c) = {", c);
        for (i = 0; i < m; i++) {
            printf("%c", f[i]);
            if (i < m - 1) { 
                printf(", ");
            }
        }
        printf("}\n");

        m = 0;
        memset(f, '\0', sizeof(f));
        follow(c);
        printf("Follow(%c) = {", c);
        for (i = 0; i < m; i++) {
            printf("%c", f[i]);
            if (i < m - 1) {  
                printf(", ");
            }
        }
        printf("}\n");

        printf("Continue (0/1)? ");
        scanf("%d", &z);
    } while (z == 1);

    return 0;
}

   
void first(char c) {
    if (!isupper(c)) {  
        addUnique(f, c);
        return;
    }

    for (int k = 0; k < n; k++) {
        if (a[k][0] == c) {  
            if (a[k][2] == '$') {  
                addUnique(f, '$');
            } else if (islower(a[k][2])) {  
                addUnique(f, a[k][2]);
            } else {  
                first(a[k][2]);
            }
        }
    }
}

void follow(char c) {
    if (a[0][0] == c) { 
        addUnique(f, '$');
    }

    for (int i = 0; i < n; i++) {
        for (int j = 2; j < strlen(a[i]); j++) {
            if (a[i][j] == c) {  
                if (a[i][j + 1] != '\0') {  
                    if (islower(a[i][j + 1])) {  
                        addUnique(f, a[i][j + 1]);
                    } else {  
                        int tempM = m;
                        first(a[i][j + 1]);

                        
                        for (int k = tempM; k < m; k++) {
                            if (f[k] != '$') {
                                addUnique(f, f[k]);
                            }
                        }

                       
                        if (isPresent(f, '$')) {
                            follow(a[i][0]);
                        }
                    }
                } else if (c != a[i][0]) {  
                    follow(a[i][0]);
                }
            }
        }
    }
}

int isPresent(char arr[], char c) {
    for (int i = 0; i < m; i++) {
        if (arr[i] == c) return 1;
    }
    return 0;
}


void addUnique(char arr[], char c) {
    if (!isPresent(arr, c)) {
        arr[m++] = c;
    }
}












/*

Enter the number of productions:
4
Enter the productions:
S-ABC
A-bAc
B-dB
C-fg


OR


Enter the number of productions:
3
Enter the productions:
S-Ab
A-aA
A-$

*/
