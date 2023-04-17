#include <stdio.h>

void Swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void BubbleSort(int *a, int n)
{
    // bool flag = true;
    int flag = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                Swap(&a[j], &a[j + 1]);
                flag = 0;
            }
        }
        if (flag == 1)
            return;
    }
}

int main()
{
    // int arr[10] = {2, 10, 42, 3, 56, 1, 8, 90, 45, 2};
    int arr[10] = {1, 2, 3, 4, 10, 6, 7, 8, 9, 10};
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
    putchar('\n');
    putchar('\n');
    BubbleSort(arr, sizeof(arr) / sizeof(int));
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
    putchar('\n');
    return 0;
}
