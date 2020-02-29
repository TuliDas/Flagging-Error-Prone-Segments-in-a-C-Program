static int global_loop_id = 0, global_ifelse_id = 0, global_function_id = 0;
#include <chrono>
long long getTicks(){return std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count();}
#include <stdio.h>
int main()
{ freopen("Input.txt", "r+", stdin); freopen("Output.txt", "w+", stdout);auto startTime5 = getTicks();
    int c, first, last, middle, n, search, array[100];
    printf("Enter number of elements\n");
    scanf("%d", &n);
    printf("Enter %d integers\n", n);
auto startTime11 = getTicks();    for (c = 0; c < n; c++)
    {
        scanf("%d", &array[c]);
    }printf("Time = %lld , ( 11 , 14 ) \n", getTicks() - startTime11);
    printf("Enter value to find\n");
    scanf("%d", &search);
    first = 0;
    last = n - 1;
    middle = (first+last)/2;
auto startTime20 = getTicks();    while (first <= last)
    {
        if (array[middle] < search)
        {auto startTime22 = getTicks();
            first = middle + 1;
printf("Time = %lld , ( 22 , 25 ) \n", getTicks() - startTime22);        }
        else if (array[middle] == search)
        {auto startTime26 = getTicks();
            printf("%d found at location %d.\n", search, middle+1);
            break;
printf("Time = %lld , ( 26 , 30 ) \n", getTicks() - startTime26);        }
        else
        {auto startTime31 = getTicks();
            last = middle - 1;
printf("Time = %lld , ( 31 , 34 ) \n", getTicks() - startTime31);        }
        middle = (first + last)/2;
    }printf("Time = %lld , ( 20 , 36 ) \n", getTicks() - startTime20);
    if (first > last)
    {auto startTime37 = getTicks();
        printf("Not found! %d isn't present in the list.\n", search);
printf("Time = %lld , ( 37 , 40 ) \n", getTicks() - startTime37);    }
printf("Time = %lld , ( 5 , 42 ) \n", getTicks() - startTime5);    return 0;
printf("Time = %lld , ( 5 , 42 ) \n", getTicks() - startTime5);}
