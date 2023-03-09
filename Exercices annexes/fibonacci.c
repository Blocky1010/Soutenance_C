#include <stdio.h>

int fibonacci(int max_fib){
    int ret_fib;
    int v1;
    int v2;
    int i;

    v1 = 0;
    v2 = 1;
    i = 1;
    if (max_fib == 0) {
        ret_fib = 0;
    
    }else if (max_fib == 1) {
        ret_fib = 1;
    }
    else {
        while(i < max_fib){
        ret_fib = v1 + v2 ;
        v1 = v2 ;
        v2 = ret_fib;
        i++;
        
        }
    }
    return (ret_fib);

    
}

int main (void) {
    int fib;
    fib = fibonacci(0);
    printf("%i\n", fib);
    return(1);
}
 
