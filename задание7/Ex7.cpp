#include <iostream>
#include <vector>
using namespace std;

int main()
{
    typedef vector<int> VEC;
    VEC v;
    int a, count = 0;

    cout << v.size() << " " << v.capacity() << endl;

    for (int i = 0; i < 1000; i++)
    {
        a = v.capacity();
        v.push_back(1);
        if (a != v.capacity())
        {
            cout << v.size() << " " << v.capacity() << endl;
            count++;
        }
        //cout << v.size() << " " << v.capacity() << endl;
    }
    cout << "count= " << count << endl;



}
