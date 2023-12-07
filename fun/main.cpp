#include <iostream>
#include <string>
#include <vector>
#include <regex>
using namespace std;
int main()
{
    

    regex s (".*@.*\\.(edu|com|net)$");
    string m = "ryanheffelman@carthage.edu";

    if (regex_search(m, s)) cout<<m<<endl;

}
