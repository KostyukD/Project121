#include <iostream>
#include <cstring>
using namespace std;

class MyString 
{
private:
    char* str;
    int length;
    static int objectCount;

public:
    MyString() 
    {
        length = 80;
        str = new char[length + 1];
        strcpy(str, "");
        objectCount++;
    }

    MyString(int size)
    {
        length = size;
        str = new char[length + 1];
        strcpy(str, "");
        objectCount++;
    }

    MyString(const char* inputStr) 
    {
        length = strlen(inputStr);
        str = new char[length + 1];
        strcpy(str, inputStr);
        objectCount++;
    }

    ~MyString() 
    {
        delete[] str;
        objectCount--;
    }
    
    void input() 
    {
        cout << "Enter a string: ";
        cin.getline(str, length);
    }

    void output() const 
    {
        cout << "String: " << str << endl;
    }

    void MyStrcpy(MyString& obj) 
    {
        delete[] str;
        length = obj.length;
        str = new char[length + 1];
        strcpy(str, obj.str);
    }

    bool MyStrStr(const char* substr) const 
    {
        return strstr(str, substr) != nullptr;
    }

    int MyChr(char c) const 
    {
        for (int i = 0; i < length; i++) 
        {
            if (str[i] == c) 
            {
                return i;
            }
        }
        return -1;
    }

    int MyStrLen() const 
    {
        return length;
    }

    void MyStrCat(MyString& b) 
    {
        char* newStr = new char[length + b.length + 1];
        strcpy(newStr, str);
        strcat(newStr, b.str);
        delete[] str;
        str = newStr;
        length += b.length;
    }

    void MyDelChr(char c) 
    {
        char* newStr = new char[length + 1];
        int newLen = 0;
        for (int i = 0; i < length; i++) 
        {
            if (str[i] != c) 
            {
                newStr[newLen++] = str[i];
            }
        }
        newStr[newLen] = '\0';
        delete[] str;
        str = newStr;
        length = newLen;
    }

    int MyStrCmp(MyString& b) const 
    {
        int result = strcmp(str, b.str);
        if (result < 0) return -1;
        if (result > 0) return 1;
        return 0;
    }

    MyString operator+(const MyString& b) const 
    {
        MyString temp;
        temp.length = length + b.length;
        temp.str = new char[temp.length + 1];
        strcpy(temp.str, str);
        strcat(temp.str, b.str);
        return temp;
    }

    MyString& operator++() 
    {
        char* newStr = new char[length + 2];
        std::strcpy(newStr, str);
        newStr[length] = ' ';
        newStr[length + 1] = '\0';
        delete[] str;
        str = newStr;
        length += 1;
        return *this;
    }

    MyString& operator--() 
    {
        if (length > 0) 
        {
            str[length - 1] = '\0';
            length -= 1;
        }
        return *this;
    }

    static int getObjectCount() 
    {
        return objectCount;
    }
};

int MyString::objectCount = 0;
