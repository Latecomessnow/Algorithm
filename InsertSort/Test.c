#include <stdio.h>

void InsertSort(int* a, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int end = i;
        int tmp = a[end + 1];
        while (end >= 0)
        {
            if (tmp < a[end])
            {
                a[end + 1] = a[end];
                end--;
            }
            else
                break;
        }
        a[end + 1] = tmp;
    }
}

int main()
{
    int arr[10] = { 9, 4, 21, 31, 6, 89, 2, 1, 9, 24 };
    InsertSort(arr, sizeof(arr) / sizeof(int));
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
    putchar('\n');
    return 0;
}
