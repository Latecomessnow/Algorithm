#include <stdio.h>

void Swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void AdjustDown(int *a, int n, int parent)
{
    int child = parent * 2 + 1;
    while (child < n)
    {
        if (child + 1 < n && a[child + 1] > a[child])
            child++;
        if (a[child] > a[parent])
        {
            Swap(&a[child], &a[parent]);
            parent = child;
            child = parent * 2 + 1;
        }
        else
            break;
    }
}

void HeapSort(int *a, int n)
{
    // 堆排序前需要先建堆，从倒数第一个非叶子节点开始建堆
    for (int i = (n - 1 - 1) / 2; i >= 0; i--)
    {
        AdjustDown(a, n, i);
    }
    int end = n - 1;
    while (end)
    {
        // 每次都把最大的堆定数据换到最后，然后从堆顶开始向下调整
        Swap(&a[0], &a[end]);
        AdjustDown(a, end, 0);
        end--;
    }
}

int main()
{
    int arr[10] = {2, 10, 42, 3, 56, 1, 8, 90, 45, 2};
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
    putchar('\n');
    putchar('\n');
    HeapSort(arr, sizeof(arr) / sizeof(int));
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
    putchar('\n');
    return 0;
}