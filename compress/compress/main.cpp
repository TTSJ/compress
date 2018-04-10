#include <utils/stream.h>
#include <memory.h>
#include <string>
#include <cmath>
#include <map>
#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string/replace.hpp>
#include <algorithm>
#include <boost/format.hpp>

using namespace std;

int main()
{
    string addr = "127.0.0.1:50003";
    int chanel = 2;

    boost::format fmt = boost::format("%s_%d") % addr %chanel;
    string ss = fmt.str();


    getchar();
}