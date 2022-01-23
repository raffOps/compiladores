#include <stdio.h>

int main() {
    for(int i=1; i<=10; i++) {
        for(int i2=1; i2<=i; i2++){
            printf("%d", i2);
        }
        printf("\n");
    }
    return 0;
}
