#include <iostream>
#include <string>
using namespace std;

void count(int x)
{
    cout << x << " ";
    if (x < 5) count(x - 1);
}

int main()
{
    string s = "emily";
    string y;
    cin >> y;
    if (y != s) main();
}
