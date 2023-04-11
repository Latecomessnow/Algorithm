#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    for (auto &e : v)
    {
        cout << e << " ";
    }
    cout << endl;
    cout << endl;
    swap(v[0], v[1]);
    for (auto &e : v)
    {
        cout << e << " ";
    }
    cout << endl;
    return 0;
}