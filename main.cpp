#include <bits/stdc++.h>
#define int long long
#define endl "\n"

using namespace std;

const int maxlen = 10010;

class Set{
public:
    Set(){};                            // 构造函数
    Set(int *a1, int *a2);              // 构造函数，重载用来接收数组
    void print();                       // 打印集合元素
    int length()const;                  // 返回集合元素个数
    void add(int a);                    // 新增元素 a
    void del(int a);                    // 删除元素 a
    void clean();                       // 清空集合
    int operator[](int i)const;         // 重组 [], 直接访问 A[i]
    void operator=(const Set &s);       // 重组 = , 传值
    Set operator-(const Set& s1)const;  // 重组 - , 用于差集和交集的运算
    Set operator+(const Set& s1)const;  // 重组 + , 用于并集
    Set intersect(const Set &s);        // 交集
private:
    vector<int> arr;                    // 用于存储集合元素的动态数组
};

Set::Set(int *a1, int *a2){
    int len = a2 - a1;
    for(int i = 0; i <= len; i++) add(*(a1 + i));
}

void Set::print(){
    for(int i = 0; i < arr.size(); i++) cout << arr[i] << " ";
    cout << endl;
}

int Set::length()const{
    return arr.size();
}

void Set::add(int a){
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] == a) return;
    }
    arr.push_back(a);
}

void Set::del(int a){
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] == a){
            arr.erase(arr.begin() + i);
            break;
        }
    }
}

void Set::clean(){
    arr.clear();
}

int Set::operator[](int i)const{
    if(i > arr.size()){
        cout << "索引超过最大值！将返回第0个元素" << endl;
        return arr[0];
    }else{
        return arr[i];
    }
}

// 赋值
void Set::operator=(const Set &s){
    arr.clear();
    for(int i = 0; i < s.length(); i++){
        arr.push_back(s[i]);
    }
}

// 交集
Set Set::intersect(const Set &s){
    Set s1, s2;
    for(int i = 0; i < arr.size(); i++){
        s1.add(arr[i]);
    }
    s2 = s1;
    s1 = s1 - s;
    s2 = s2 - s1;
    return s2;
}

// 并集
Set Set::operator+(const Set& s1)const{
    Set s;
    for(int i = 0; i < arr.size(); i++){
        s.add(arr[i]);
    }
    for(int i = 0; i < s1.length(); i++){
        s.add(s1[i]);
    }
    return s;
}

// 差集
Set Set::operator-(const Set& s1)const{
    Set s;
    for(int i = 0; i < arr.size(); i++){
        s.add(arr[i]);
    }
    for(int i = 0; i < s1.length(); i++){
        s.del(s1[i]);
    }
    return s;
}

signed main(){

    // 为方便操作，以下操作将从数组 a 取数
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 6, 58, 44};

    // 取 a(0, 8)
    Set s(a, a + 8);
    s.print();
    cout << s.length() << endl;

    // 取 a(4, 6)
    Set s1(a + 4, a + 6);
    s1.print();
    cout << s1.length() << endl;

    // 测试差集 (s - s1), 注意为检查运算准确性, s2 在运算前加了元素 128
    Set s2;
    s2 = s - s1;
    s2.add(128);
    s2.print();
    cout << s2.length() << endl;

    // 测试交集 (s3 交 s2)
    Set s3;
    s3 = s.intersect(s2);
    s3.print();
    cout << s3.length() << endl;

    // 取 a(6, 9)
    Set s4(a + 6, a + 9);
    s4.print();
    cout << s4.length() << endl;

    // 测试并集 (s1 + s4)
    Set s5;
    s5 = s1 + s4;
    s5.print();
    cout << s5.length() << endl;
    return 0;
}
