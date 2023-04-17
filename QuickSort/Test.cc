#include <iostream>
#include <stack>

using namespace std;

// 1. Hoare法
// void QuickSort(int* a, int begin, int end)
// {
//     // 区间只有一个数或者区间不存在不需要再递归了
//     if (begin >= end)
//         return;
//     int left = begin, right = end;
//     int keyi = left;
//     while (left < right)
//     {
//         // 右边先走找小
//         while (left < right && a[right] >= a[keyi])
//         {
//             right--;
//         }
//         // 左边再走找大
//         while (left < right && a[left] <= a[keyi])
//         {
//             left++;
//         }
//         swap(a[left], a[right]);
//     }
//     swap(a[keyi], a[left]);
//     keyi = left;
//     QuickSort(a, begin, keyi - 1);
//     QuickSort(a, keyi + 1, end);
// }

// 2. 挖坑法
// void QuickSort(int* a, int begin, int end)
// {
//     if (begin >= end)
//         return;
//     int left = begin, right = end;
//     // 左边第一个做坑位
//     int key = a[left];
//     while (left < right)
//     {
//         // 右边先走找小填坑位
//         while (left < right && a[right] >= key)
//         {
//             right--;
//         }
//         a[left] = a[right];
//         while (left < right && a[left] <= key)
//         {
//             left++;
//         }
//         a[right] = a[left];
//     }
//     // 把基准值填到最后的坑位中
//     a[left] = key;
//     QuickSort(a, begin, left - 1);
//     QuickSort(a, left + 1, end);
// }

// 3. 前后指针法
void QuickSort(int* a, int begin, int end)
{
    if (begin >= end)
        return;
    int prev = begin;
    int cur = begin + 1;
    int keyi = begin;
    while (cur <= end)
    {
        // 若cur指向的内容小于key，则prev先向后移动一位，
        // 然后交换prev和cur指针指向的内容，然后cur指针++
        if (a[cur] < a[keyi] && ++prev != cur)
        {
            swap(a[prev], a[cur]);
        }
        cur++;
    }
    swap(a[keyi], a[prev]);
    keyi = prev;
    QuickSort(a, begin, keyi - 1);
    QuickSort(a, keyi + 1, end);
}

// 快排非递归版本
// 单趟排序
int PartSort(int* a, int begin, int end)
{
    int prev = begin;
    int cur = begin + 1;
    int keyi = begin;
    while (cur <= end)
    {
        if (a[cur] < a[keyi] && ++prev != cur)
        {
            swap(a[prev], a[cur]);
        }
        cur++;
    }
    swap(a[keyi], a[prev]);
    keyi = prev;
    return keyi;
}

void QuicKSortNonR(int* a, int begin, int end)
{
    stack<int> s;
    s.push(begin);
    s.push(end);
    while (!s.empty())
    {
        // 每次先取出左右边界，先右后左
        int right = s.top();
        s.pop();
        int left = s.top();
        s.pop();
        // 进行单趟排序
        int keyi = PartSort(a, left, right);
        // 区间存在的话继续模拟操作
        if (left < keyi - 1)
        {
            // 先入左操作数，再入右操作数
            s.push(left);
            s.push(keyi - 1);
        }
        if (keyi - 1 < right)
        {
            s.push(keyi + 1);
            s.push(right);
        }
    }
}
int main()
{
    int arr[10] = {2, 0, 9, 11, 5, 6, 3, 3, 4, 1};
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    //QuickSort(arr, 0, sizeof(arr) / sizeof(int) - 1);
    QuicKSortNonR(arr, 0, sizeof(arr) / sizeof(int) - 1);
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}