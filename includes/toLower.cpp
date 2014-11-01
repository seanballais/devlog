#include <locale>
#include <string>
using namespace std;

// Code based from NoobTuts
string toLower(const string& s)
{
    std::string result;

    std::locale loc;

    for (unsigned int i = 0; i < s.length(); ++i)
    {
        result += tolower(s.at(i), loc);
    }

    return result;
}