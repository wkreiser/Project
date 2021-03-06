//Reverse Engineering Lab2A
#include <stdio.h>
#include <time.h>

int fibo(int a)
{   
    if (a == 0)
    {
        a = 0;
        return a;
    }
    else if (a == 1)
    {
        a = 1;
        return a;
    }
    else
    {
        return (fibo(a-1) + fibo(a-2));
    }
}

int iterFibo(int a)
{
    int f1 = 0, f2 = 1, f;
    if (a == 0)
    {
        a = 0;
        return a;
    }
    else if (a == 1)
    {
        a = 1;
        return a;
    }
    else
    {
        do {
            f = f1+f2;
            f1 = f2;
            f2 = f;
            a--;
        } while(a>1);

    }   
    return f;
}
int main(void)
{
    //1 parameter
    
    int arg_0 = 20;
    int recurFib = 0, iterfib = 0;
    //Recursive and Iterative time start
    clock_t recStart, recEnd, iterStart, iterEnd;
    double recur_time_used, iter_time_used;

    //Tracking the time that recursive fibonacci takes
    recStart = clock();
    printf("This is a test %f.\n", (double)recStart);
    recurFib = fibo(arg_0);
    recEnd = clock()-recStart;
    recur_time_used = ((double)(recEnd)/CLOCKS_PER_SEC);

    //Tracking the time that iterative fibonacci takes
    iterStart = clock();
    iterfib = iterFibo(arg_0);
    iterEnd = clock() - iterStart;
    iter_time_used =  ((double) (iterEnd)/CLOCKS_PER_SEC);

    printf("N1: %d N2: %d\n\n", recurFib, iterfib);

    if (iter_time_used < recur_time_used)
    {
        printf("N2 is less than N1.\n");
        printf("N2: %f N1: %f", iter_time_used, recur_time_used);
    }
    else
    {
        printf("N1 is less than N2.\n");
        printf("N1: %f N2: %f\n", recur_time_used, iter_time_used);
    }

    return 0;
}