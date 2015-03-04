#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main()
{
    string in_str;
    const size_t str_size =10;
    char result_str[str_size];
    cin>>in_str;
    size_t len=in_str.size();
    strncpy(result_str,in_str.c_str(),len);
    result_str[len+1]='0';
    cout<<result_str;

    return 0;
}
