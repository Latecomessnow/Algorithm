#include <iostream>
#include <stdlib.h>

using namespace std;

void _MergeSort(int *a, int left, int right, int *tmp)
{
    if (left >= right)
        return;
    int mid = left + (right - left) / 2;
    // 划分左右区间
    _MergeSort(a, left, mid, tmp);
    _MergeSort(a, mid + 1, right, tmp);

    // 开始归并，比较两个区间大小放进tmp数组
    int begin1 = left, end1 = mid;
    int begin2 = mid + 1, end2 = right;
    int i = left;
    while (begin1 <= end1 && begin2 <= end2)
    {
        if (a[begin1] < a[begin2])
            tmp[i++] = a[begin1++];
        else
            tmp[i++] = a[begin2++];
    }
    // 将剩余元素继续放进tmp数组
    while (begin1 <= end1)
        tmp[i++] = a[begin1++];
    while (begin2 <= end2)
        tmp[i++] = a[begin2++];

    // 将数组拷贝回原数组
    for (int j = left; j <= right; j++)
        a[j] = tmp[j];
}
void MergeSort(int *a, int n)
{
    int *tmp = (int *)malloc(sizeof(int) * n);
    if (tmp == nullptr)
        exit(-1);
    _MergeSort(a, 0, n - 1, tmp);
    free(tmp);
}

int main()
{
    int arr[10] = {2, 0, 9, 11, 5, 6, 3, 3, 4, 1};
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << endl;
    MergeSort(arr, sizeof(arr) / sizeof(int));
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}