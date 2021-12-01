#include <stdio.h>
#include <stdlib.h>


int read_num(FILE *file, int *num);

int main() {
    int prev, cur, tally = 0;
    FILE *file = fopen("input", "r");
    
    read_num(file, &prev);

    while (!feof(file)) {
        if (read_num(file, &cur)) {
            if (cur > prev) {
                tally++;
            }
            prev = cur;
        }
    }
    printf("%d\n", tally);
}

int read_num(FILE *file, int *num) {
    static char *buf = NULL;
    static size_t buf_size = 0;

    if(getline(&buf, &buf_size, file) < 1)
        return 0;
    *num = atoi(buf);
    return 1;
}
    
