#include <iostream>
#include <string>

using namespace std;

string findSubstring(string str)
{
   string substring,tmp_substring;
   substring.erase(substring.begin(), substring.end());
   for(size_t charCount = 0; charCount<str.length();++charCount)
   {
        if(str[charCount] >= '0' && str[charCount]<='9')
        {
            if(substring.length() < tmp_substring.length())
            {
                substring.erase(substring.begin(), substring.end());
                substring.append(tmp_substring);
            }
            tmp_substring.erase(tmp_substring.begin(), tmp_substring.end());
        }
        tmp_substring+=str[charCount];
    }
    return substring;
}

void reverse(int strLength,string& str)
{
    char tmpChar;
    for(size_t i = 0, j = strLength -1 ; (strLength-i) != (strLength)/2;++i, --j)
    {
        tmpChar = str[i];
        str[i] = str[j];
        str[j] = tmpChar;
    }
}

int main()
{
    string str;
    cin>>str;
    string maxSubstring = findSubstring(str);;
    int length = maxSubstring.length();
    if(maxSubstring[0] != maxSubstring[length-1])
    {
        reverse(length, maxSubstring);
        return 0;
    }
    return 0;
}
