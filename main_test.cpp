/*!
    \file
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *fp = fopen("test.txt","rb");
    if (fp == NULL) {
        printf("error un opening file\n");
        return 0;
    }
    double a = 0, b = 0, c = 0, x1 = 0, x2 = 0;
    int nRoots = -2;

    fseek(fp, 0L, SEEK_END);
    int n = ftell(fp);
    fseek(fp, 0L, SEEK_SET);
    char *ptr = (char*) calloc(n, sizeof(char));
    size_t read_size =  fread(ptr, sizeof(char), n, fp);
    if (read_size != (size_t) n) {
        printf("error\n");
        return 0;
    }
    int n_symbols_read = 0;
    while(1) {
        int current_shift = 0;
        if (sscanf(ptr+n_symbols_read, "%lf %lf %lf %d %n", &a, &b, &c, &nRoots, &current_shift) == EOF){
            printf("%lf %lf %lf %d %d\n", a, b, c, nRoots, n_symbols_read);
            break;
        }
        n_symbols_read += current_shift;
        if (nRoots == 2) {
            sscanf(ptr+n_symbols_read, "%lf %lf %n", &x1, &x2, &current_shift);
            n_symbols_read += current_shift;
        }
        if (nRoots == 1) {
            sscanf(ptr+n_symbols_read, "%lf %n", &x1, &current_shift);
            n_symbols_read += current_shift;
        }
        printf("%lf %lf %lf %d %d\n", a, b, c, nRoots, n_symbols_read);
    }
    return 0;
}
