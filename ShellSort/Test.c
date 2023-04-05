#include <stdio.h>

void ShellSort(int *a, int n)
{
    int gap = n;
    while (gap > 1)
    {
        gap /= 2;
        for (int i = 0; i < n - gap; i++)
        {
            int end = i;
            int tmp = a[end + gap];
            while (end >= 0)
            {
                if (tmp < a[end])
                {
                    a[end + gap] = a[end];
                    end -= gap;
                }
                else
                    break;
            }
            a[end + gap] = tmp;
        }
    }
}

int main()
{
    int arr[10] = {2, 10, 42, 3, 56, 1, 8, 90, 45, 2};
    ShellSort(arr, sizeof(arr) / sizeof(int));
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
    putchar('\n');
    return 0;
}