#include <stdio.h>

void Swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void SelectSort(int *a, int n)
{
    // 1. 一次选一个数
    // for (int i = 0; i < n; i++)
    // {
    //     // 遍历位置
    //     int start = i + 1;
    //     // 记录索引位置
    //     int minIndex = i;
    //     while (start < n)
    //     {
    //         if (a[start] < a[minIndex])
    //         {
    //             minIndex = start;
    //         }
    //         start++;
    //     }
    //     // 已选出最小位置，开始交换
    //     Swap(&a[i], &a[minIndex]);
    // }

    // 2. 一次选两个数
    int left = 0;
    int right = n - 1;
    while (left < right)
    {
        int minIndex = left;
        int maxIndex = left;
        for (int i = left + 1; i <= right; i++)
        {
            if (a[i] < a[minIndex])
            {
                minIndex = i;
            }
            if (a[i] > a[maxIndex])
            {
                maxIndex = i;
            }
        }
        Swap(&a[left], &a[minIndex]);
        // 如果最大值是在left位置的话经过交换会被换到minIndex位置
        if (maxIndex == left)
        {
            maxIndex = minIndex;
        }
        Swap(&a[right], &a[maxIndex]);
        left++;
        right--;
    }
}

int main()
{
    int arr[10] = {9, 8, 7, 78, 5, 4, 3, 2, 1, 0};
    SelectSort(arr, 10);
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
    putchar('\n');
    return 0;
}