#include <stdio.h>

int main()
{
    int N;
    float f, ret = 0.0;
    fscanf(stdin, "%d", &N);
    float S = N * 3.3058;
    do {
        fscanf(stdin, "%f", &f);
        if (f < S && f > ret)
            ret = f;
    } while(getc(stdin) == ' ');
    fprintf(stdout, "%.2f\n", ret / 3.3058);
    fprintf(stdout, "%.2f\n", ret);
}