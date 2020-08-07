<<<<<<< HEAD
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <cstring>
using namespace std;

namespace haizei {
class string {
public :
    friend istream &operator>>(istream &in,  const haizei::string &s);
    string() {
        this->__buff_size = 10;
        this->buff = new char[this->__buff_size];
        this->__length = 0;
    }
    string(const char *str) {
        cout << "string :const char constructor" << endl;
        this->__buff_size = strlen(str) + 1;
        this->buff = new char[this->__buff_size];
        strcpy(this->buff, str);
        this->__length = this->__buff_size - 1;
    }
    string(const string &s){
        cout << "copy constructor" << endl;
        this->__buff_size = s.__buff_size;
        this->buff = new char[__buff_size];
        strcpy(this->buff, s.buff);
        this->__length = s.__length;
    }
    char &at(int ind) {
        if (ind < 0 || ind >= __length) {
            cout << "String Error : out of range" << endl;
            return __end;
        }
        return this->operator[](ind);
    }
    char &operator[](int ind) {
        return buff[ind];
    }
    const char *c_str() const {
        return buff;
    }
    string operator+(const string &s) {
        cout << "string :operator +" << endl;
        int size = this->__length + s.__length + 1;
        char *temp = new char[size];
        strcpy(temp, this->buff);
        strcat(temp, s.buff);
        return temp;
    }
    int size() { return this->__length; }

private:
    int __length, __buff_size;
    char *buff;
    char __end;
};

}

ostream &operator<<(ostream &out, const haizei::string &s) {
    out << s.c_str();
    return out;
}
/*istream &operator>>(istream &in, const haizei::string &s) {
    in >> s.buff;
    return in;
}*/
int main() {
    haizei::string s1 = "hello world", s2 = ", haizei", s3 = ", harbin.";
   // cin >> s1;
    cout << s1 << endl;
    s1[3] = '6';
    cout << s1 << endl;
    cout << s1 + s2 + s3 << endl;
    cout << "=======" << endl;
    haizei::string s4 = s1 + s2 + s3;
    haizei::string s5 = s4;
    s4[3] = '5';
    cout << s4 << endl;
    cout << s5 << endl;
    cout << "=======" << endl;
    for (int i = 0; i < s1.size(); i++) {
        cout << s1[i] << endl;
    }
    return 0;
=======
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <cstring>
using namespace std;

namespace haizei {
class string {
public :
    friend istream &operator>>(istream &in,  const haizei::string &s);
    string() {
        this->__buff_size = 10;
        this->buff = new char[this->__buff_size];
        this->__length = 0;
    }
    string(const char *str) {
        cout << "string :const char constructor" << endl;
        this->__buff_size = strlen(str) + 1;
        this->buff = new char[this->__buff_size];
        strcpy(this->buff, str);
        this->__length = this->__buff_size - 1;
    }
    string(const string &s){
        cout << "copy constructor" << endl;
        this->__buff_size = s.__buff_size;
        this->buff = new char[__buff_size];
        strcpy(this->buff, s.buff);
        this->__length = s.__length;
    }
    char &at(int ind) {
        if (ind < 0 || ind >= __length) {
            cout << "String Error : out of range" << endl;
            return __end;
        }
        return this->operator[](ind);
    }
    char &operator[](int ind) {
        return buff[ind];
    }
    const char *c_str() const {
        return buff;
    }
    string operator+(const string &s) {
        cout << "string :operator +" << endl;
        int size = this->__length + s.__length + 1;
        char *temp = new char[size];
        strcpy(temp, this->buff);
        strcat(temp, s.buff);
        return temp;
    }
    int size() { return this->__length; }

private:
    int __length, __buff_size;
    char *buff;
    char __end;
};

}

ostream &operator<<(ostream &out, const haizei::string &s) {
    out << s.c_str();
    return out;
}
/*istream &operator>>(istream &in, const haizei::string &s) {
    in >> s.buff;
    return in;
}*/
int main() {
    haizei::string s1 = "hello world", s2 = ", haizei", s3 = ", harbin.";
   // cin >> s1;
    cout << s1 << endl;
    s1[3] = '6';
    cout << s1 << endl;
    cout << s1 + s2 + s3 << endl;
    cout << "=======" << endl;
    haizei::string s4 = s1 + s2 + s3;
    haizei::string s5 = s4;
    s4[3] = '5';
    cout << s4 << endl;
    cout << s5 << endl;
    cout << "=======" << endl;
    for (int i = 0; i < s1.size(); i++) {
        cout << s1[i] << endl;
    }
    return 0;
>>>>>>> ac04a7239df575541f20383350d1581396c828d8
}