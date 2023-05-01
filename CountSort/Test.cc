#include <iostream>
#include <stdlib.h>

using namespace std;

void CountSort(int* a, int n)
{
    int min = a[0];
    int max = a[0];
    for (int i = 0; i < n; i++)
    {
        if (a[i] < min)
            min = a[i];
        if (a[i] > max)
            max = a[i];
    }
    int range = max - min + 1;
    int* count = (int*)malloc(sizeof(int) * range);
    if (count == nullptr)
    {
        printf("malloc fail\n");
        exit(-1);
    }
    // 统计数字出现的次数
    for (int i = 0; i < n; i++)
    {
        count[a[i] - min]++;
    }
    int j = 0;
    // 开始按次数进行排序
    for (int i = 0; i < range; i++)
    {
        while (count[i]--)
            a[j++] = i + min;
    }
    free(count);
}

int main()
{
    int arr[15] = {2, 0, 9, 11, 5, 6, 3, 3, 4, 1, 12, 190, 323, 190, 2888};
    for (int i = 0; i < 15; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << endl;
    CountSort(arr, sizeof(arr) / sizeof(int));
    for (int i = 0; i < 15; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
