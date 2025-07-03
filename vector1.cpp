
#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

//输出方式1：
void PrintVector(vector<int>& v) {
    for (vector<int>::iterator iter = v.begin(); iter != v.end();iter++) {
        cout << *iter << " ";
    }
    cout << endl;
}
//输出方式2：
void PrintVector1(const vector<int>& v) {
    for (int i = 0;i < v.size();i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

//bool cmp(int a, int b) {
//    return a > b;
//}

int main()
{

    /*11.排序
    vector<int>v1 = { 4,7,5,8,6,0,9,1,8,6 };
    sort(v1.begin(), v1.end(),cmp);
    PrintVector(v1);*/

    /*10.高效删除：即使用swap(v[index],v.back()) v.pop_back()的方法删除
    vector <int> v;
    for (int i = 0;i < 150006;++i) {
        v.push_back(i);
    }
    //低效删除
    //for (int i = 0;i < 150000;++i) {
    //    v.erase(v.begin() + 4);
    //}
    //高效删除
    for (int i = 0;i < 150000;++i) {
        swap(v[4], v.back());
        v.pop_back();
    }
    cout << "end" << endl; */

    /*9.空间预留
    vector<int>v;
    //使用reserve()预留空间，可以使capacity不用多次扩容
    v.reserve(100);
    for (int i = 0;i < 100;i++) {
        cout << "size:" << v.size() << "," << "capacity:" << v.capacity() << endl;
        v.push_back(i);
    }
    //reserve()  修改的是capacity
    //resize()   修改的是size
    */

    /*8.内存交换、缩容、内存清理
    //1内存交换
    vector<int>v1 = { 4,7,5,8,6 };
    vector<int>v2 = { 1,3,0,7,5 };
    v1.swap(v2);
    PrintVector(v1);
    PrintVector(v2);

    //2缩容
    v1.resize(10000);
    v1.resize(5);
    cout << "v1的capacity()表示的大小：" << v1.capacity() << endl;
    //按照匿名方式（vector <int> x(v1) ---> vector <int> (v1)），匿名时执行拷贝构造函数
    vector <int> (v1).swap(v1);
    cout << "v1的capacity()表示的大小：" << v1.capacity() << endl;

    //3内存清理
    v2.resize(10000);
    v2.clear();//并不是内存清理，而是清理数据
    vector <int>({}).swap(v2);
    cout << "v2的capacity()表示的大小：" << v2.capacity() << endl;*/

    /*7.vector输出打印
    vector<int>v = { 4,7,5,8,6 };
    //保证不会越界时中括号的效率比at()高
    cout << v[2] << endl;
    //at()有异常处理，有异常时输出和后面都不会有输出
    cout << v.at(2) << endl;
    cout << v.at(12) << endl;*/

    //cout << "front:" << v.front() << endl; at()异常，不接着输出
    /*6.vector扩容:capacity()扩容原理是1.5向下取整数，size()表示数据大小，resize()表示开辟的空间大小
    vector<int>v = { 4,7,5,8,6};
    PrintVector(v);
    cout << "size()表示的大小：" << v.size() << endl;
    cout << "capacity()表示的大小：" << v.capacity() << endl;
    v.push_back(3);
    cout << "size()表示的大小：" << v.size() << endl;
    cout << "capacity()表示的大小：" << v.capacity() << endl;
    v.push_back(4);
    cout << "size()表示的大小：" << v.size() << endl;
    cout << "capacity()表示的大小：" << v.capacity() << endl;
    v.push_back(5);
    cout << "size()表示的大小：" << v.size() << endl;
    cout << "capacity()表示的大小：" << v.capacity() << endl;
    PrintVector(v);
    v.resize(16);
    cout << "size()表示的大小：" << v.size() << endl;
    cout << "capacity()表示的大小：" << v.capacity() << endl;
    //空间足够大的时候会直接返回100的空间，而不是扩容
    v.resize(100);
    cout << "size()表示的大小：" << v.size() << endl;
    cout << "capacity()表示的大小：" << v.capacity() << endl;
    //这个不会缩容，而是后面的零不会显示了
    v.resize(5);
    cout << "size()表示的大小：" << v.size() << endl;
    cout << "capacity()表示的大小：" << v.capacity() << endl;*/

    /*5.vector删除,1、pop_back() 2、erase(); 3、clear();
    vector<int>v = { 2,0,2,5,9,8,5,211};
    PrintVector(v);
    v.pop_back();
    PrintVector(v);
    v.erase(v.begin());
    PrintVector(v);
    //迭代器会返回出来下一个值（即指向下一个值），如果v.erase(v.end()-1)那么迭代器会指向v.end()所以报错
    vector <int>::iterator it = v.erase(v.end()-2);
    PrintVector(v);
    cout << *it << endl;
    v.clear();
    PrintVector(v);*/

    /*4.vector插入,1、push_back() 2、insert()
    vector<int>v;
    for (int i = 0;i < 10;++i) {
        v.push_back(i);
    }
    PrintVector(v);
    v.insert(v.begin(), 888);
    PrintVector(v);
    v.insert(v.begin() + 2, 666);
    PrintVector(v);
    */

    /*3.赋值
    vector<int>v1 = { 2,0,2,4 };
    //1.赋值
    vector<int>v2 = v1;
    PrintVector(v2);
    //2.assign赋值
    vector<int> v3;
    v3.assign(v1.begin(), v1.end());
    PrintVector(v3);
    //3.assign初始化列表
    vector<int> v4;
    v4.assign({ 4,0,7,7 });
    PrintVector(v4);
    //4.assign a个b 赋值
    vector<int> v5;
    v5.assign(8, 6);
    PrintVector(v5);*/

    /*2.赋值
    //1.隐式构造
    vector<int> v1 = { 2,0,2,4 }; 
    PrintVector(v1);
    //2.显式构造
    vector<int> v2({ 4,0,7,7 });
    PrintVector(v2);
    //3.迭代器
    vector<int> v3(v1.begin(), v1.end());
    PrintVector(v3);
    //4.全0初始化
    vector<int> v4(8);
    PrintVector(v4);
    //5.申请8个空间的元素，每个元素初始化为6
    vector<int> v5(8, 6);
    PrintVector(v5);
    //6.拷贝构造
    vector<int> v6(v2);
    PrintVector(v6);*/

    /*1.基础认识,capacity()表示容量，begin(),end(),front(),back()
    vector int a[6] = { 5,8,9,4,1,2 };
    vector<int> v = { 2,0,2,4 };
    cout << v.capacity() << endl;
    v.push_back(7);
    cout << v.capacity() << endl;
    cout <<"begin"<< * v.begin() << endl;
    cout << "end" << *((v.end())-1) << endl;
    cout << "front" << v.front() << endl;
    cout << "back" << v.back() << endl;*/
}
