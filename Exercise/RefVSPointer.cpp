#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

class test {
public:
    int i = 3563456;
    vector<vector<int>> vec1;
    vector<vector<int>> vec2;
    vector<vector<int>> vec3;
    vector<vector<int>> vec4;
};

test obj;

class test2 {
public:
    test& testRef;

    test2(test& ref): testRef(ref){};
};

struct {
    int index = 0;
    test real = obj;
} obj1;

struct {
    int index = 0;
    test& ref = obj;
} obj2;

int j = 1;

struct {
    int index = 0;
    int& ref = j;
} obj3;

test2 retTest2() {
    test tmp;
    return test2(tmp);
}

void bindingARef() {
    test tmp;
    tmp.i = 1;
    obj2.ref = tmp;
}

/* 1.所以，如果一定要把成员变量定义成引用，那就一定要保证引用指向的对象
     的生命周期至少比本身对象的生命周期要长，不然会产生未定义行为。
   2.虽说引用在定义上指的是被引用的对象本身，但是引用本身是通过类似指针的
     方式实现的。所以其大小约等于指针的大小，取决于不同的引用实现方式。
   3.面试的时候尽量也不要这样写，其一是编译器会报错，其二是会出现很多未知的bug。
     老老实实复制对象，不差那一点内存。
*/
int main() {
    cout << "Size of obj: " << sizeof(obj) << endl;
    cout << "Size of obj1: " << sizeof(obj1) << endl;
    cout << "Size of obj2: " << sizeof(obj2) << endl;
    bindingARef();
    cout << "Size of obj2: " << sizeof(obj2) << endl;
    cout << obj2.ref.i << endl;

    test2 t = retTest2();
    bindingARef();
    cout << t.testRef.i << endl;

}