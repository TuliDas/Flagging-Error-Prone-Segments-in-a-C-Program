static int global_loop_id = 0, global_ifelse_id = 0, global_function_id = 0;
#include <chrono>
long long getTicks(){return std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count();}
#include <stdio.h>
int main()
{ freopen("Input.txt", "r+", stdin); freopen("Output.txt", "w+", stdout);
printf("line = %d\n",__LINE__);    int c, first, last, middle, n, search, array[100];
printf("line = %d\n",__LINE__);    printf("Enter number of elements\n");
printf("line = %d\n",__LINE__);    scanf("%d", &n);
printf("line = %d\n",__LINE__);    printf("Enter %d integers\n", n);
    for (c = 0; c < n; c++)
    {
printf("line = %d\n",__LINE__);        scanf("%d", &array[c]);
    }
printf("line = %d\n",__LINE__);    printf("Enter value to find\n");
printf("line = %d\n",__LINE__);    scanf("%d", &search);
printf("line = %d\n",__LINE__);    first = 0;
printf("line = %d\n",__LINE__);    last = n - 1;
printf("line = %d\n",__LINE__);    middle = (first+last)/2;
    while (first <= last)
    {
        if (array[middle] < search)
        {
printf("line = %d\n",__LINE__);            first = middle + 1;
        }
        else if (array[middle] == search)
        {
printf("line = %d\n",__LINE__);            printf("%d found at location %d.\n", search, middle+1);
printf("line = %d\n",__LINE__);            break;
        }
        else
        {
printf("line = %d\n",__LINE__);            last = middle - 1;
        }
printf("line = %d\n",__LINE__);        middle = (first + last)/2;
    }
    if (first > last)
    {
printf("line = %d\n",__LINE__);        printf("Not found! %d isn't present in the list.\n", search);
    }
printf("line = %d\n",__LINE__);    return 0;
}
