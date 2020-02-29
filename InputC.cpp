static int global_loop_id = 0, global_ifelse_id = 0, global_function_id = 0;
#include <chrono>
long long getTicks(){return std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count();}
#include <stdio.h>
int main()
{ freopen("Input.txt", "r+", stdin); freopen("Output.txt", "w+", stdout);printf("function_start_id %d line = %d\n", ++global_function_id, __LINE__);
printf("line = %d\n",__LINE__);    int c, first, last, middle, n, search, array[100];
printf("line = %d\n",__LINE__);    printf("Enter number of elements\n");
printf("line = %d\n",__LINE__);    scanf("%d", &n);
printf("line = %d\n",__LINE__);    printf("Enter %d integers\n", n);
printf("loop_start_id %d line = %d\n", ++global_loop_id, __LINE__);    for (c = 0; c < n; c++)
    {
printf("line = %d\n",__LINE__);        scanf("%d", &array[c]);
    }printf("loop_end_id %d line = %d\n", global_loop_id--, __LINE__);
printf("line = %d\n",__LINE__);    printf("Enter value to find\n");
printf("line = %d\n",__LINE__);    scanf("%d", &search);
printf("line = %d\n",__LINE__);    first = 0;
printf("line = %d\n",__LINE__);    last = n - 1;
printf("line = %d\n",__LINE__);    middle = (first+last)/2;
printf("loop_start_id %d line = %d\n", ++global_loop_id, __LINE__);    while (first <= last)
    {
        if (array[middle] < search)
        {printf("ifelse_start_id %d line = %d\n", ++global_ifelse_id, __LINE__);
printf("line = %d\n",__LINE__);            first = middle + 1;
printf("ifelse_end_id %d line = %d\n", global_ifelse_id--, __LINE__);        }
        else if (array[middle] == search)
        {printf("ifelse_start_id %d line = %d\n", ++global_ifelse_id, __LINE__);
printf("line = %d\n",__LINE__);            printf("%d found at location %d.\n", search, middle+1);
printf("line = %d\n",__LINE__);            break;
printf("ifelse_end_id %d line = %d\n", global_ifelse_id--, __LINE__);        }
        else
        {printf("ifelse_start_id %d line = %d\n", ++global_ifelse_id, __LINE__);
printf("line = %d\n",__LINE__);            last = middle - 1;
printf("ifelse_end_id %d line = %d\n", global_ifelse_id--, __LINE__);        }
printf("line = %d\n",__LINE__);        middle = (first + last)/2;
    }printf("loop_end_id %d line = %d\n", global_loop_id--, __LINE__);
    if (first > last)
    {printf("ifelse_start_id %d line = %d\n", ++global_ifelse_id, __LINE__);
printf("line = %d\n",__LINE__);        printf("Not found! %d isn't present in the list.\n", search);
printf("ifelse_end_id %d line = %d\n", global_ifelse_id--, __LINE__);    }
printf("line = %d\n",__LINE__);printf("function_end_id %d line = %d\n", global_function_id--, __LINE__);    return 0;
printf("function_end_id %d line = %d\n", global_function_id--, __LINE__);}
