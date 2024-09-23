#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>


typedef unsigned long long fib_type;

fib_type iterative_fibonacci(int nthNum) {
    fib_type prevprevnum = 0;
    fib_type prevnum = 1;
    fib_type currentnum = 0;

    for (int i = 0; i < nthNum; i++) {
        if (will_overflow(prevprevnum, prevnum)) {
            printf("Overflow at Fibonacci index: %d\n", i);
            exit(1);
        }
        prevprevnum = prevnum;
        prevnum = currentnum;
        currentnum = prevprevnum + prevnum;
    }

    return currentnum;
}

fib_type recursive_fibonacci(int nthNum) {
    if (nthNum == 0) {
        return 0;
    } else if (nthNum == 1) {
        return 1;
    }
    return recursive_fibonacci(nthNum - 1) + recursive_fibonacci(nthNum - 2);
}




int will_overflow(fib_type a, fib_type b) {
    return a > 0 && b > 0 && (a > (ULLONG_MAX - b));
}



int main(int argc, char *argv[]) {

    int num = atoi(argv[1]) - 1;
    if (num < 0) {
        num = 0;
    }
    char method = argv[2][0];
    fib_type result;

    clock_t start = clock();
    
    if (method == 'i') {
        result = iterative_fibonacci(num);
    } else if (method == 'r') {
        result = recursive_fibonacci(num);
    }

    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;

   printf("%lld\n", result);
   //printf("Time taken: %f seconds\n", time_spent);

   return 0;
}