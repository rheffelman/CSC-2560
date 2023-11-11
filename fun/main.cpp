#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    double amt = 10000.0;

    for (int i = 0; i < 20; i++){
        amt *= 1.043;
    }
    printf("%.2f\n", amt - 10000);
}
