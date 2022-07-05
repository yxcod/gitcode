#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include <thread>
#include<mutex>
#include <list>
#include <future>
using namespace std;
//int main()
//{
////    int i=10;
////    int k=20;
////    int num=i*k;
////    cout<<num<<endl;
//    vector<int>v1;
//    for (int i=0; i<100; i++)
//    {
//        v1.push_back(i);
//    }
////    auto it=v1.begin();
////    for (; it!=v1.end(); it++)
////      {
////        cout<<*it<<endl;
////    }
//    for (vector<int>::iterator it=v1.begin(); it!=v1.end(); it++)
//    {
//        cout<<*it<<endl;
//    }
//}
//class test
//{
//public:
//    int a=10;
//    string str="hello";
//    double h=26.2323;
//
//};
//
//class test* fun1(void* data,class test*(*fun)(void* data))
//{
//    return fun(data);
//
//}
//class test* testfun(void* data)
//{
//    class test* t1=(class test*)data;
//    return t1;
//
//
//}
//
//
//int main()
//{
//    test t1;
//    t1.a=50;
//    t1.str="world";
//    t1=*fun1(&t1,testfun);
//    cout<<t1.a<<endl;
//    return 0;
//}
//class copyt{
//public:
//  copyt operator=(const copyt & c2)
//    {
//      i=c2.i;
//      return *this;
//    }
//    int *i;
//    copyt(const copyt & c1)
//    {
//        i=c1.i;//t1已经在堆区开辟了空间 这里 直接把c1.i指向的地址赋值给i
//        len=c1.len;
//        ch1=new char[len];
//        strcpy(ch1, c1.ch1);
//    }
//    copyt(){};
//    int*i;
//    char*ch1;
//    int len;
//    ~copyt()
//    {
////        delete ch1;
////        delete i;
//    }

//};
//int main()
//{
//    copyt t1;
//    t1.i=new int(10);
//    copyt t2;
//    t2=t1;
//    cout<<*t2.i<<endl;
//    copyt t1;
//    t1.len=5;
//    t1.i=new int (10);
//    char arr [5]={'h','e','l','l','o'};//这里在复制构造函数中已经开辟了空间 这里直接让构造函数开辟空间值指向字符首地址就行
//    t1.ch1=arr;
////    for (int i=0;i<t1.len ; i++)
////    {
////        cout<<*(t1.ch1+i)<<endl;
////    }
//    copyt t2(t1);
//    cout<<t2.len<<endl;
//    for (int i=0;i<5 ; i++)
//    {
//        cout<<*(t2.ch1+i)<<endl;
//    }
//    cout<<*t2.i<<endl;
//
    
//}
mutex m1;
list<int>l1;
int a=0;
unique_lock<mutex>sbguard(m1,try_to_lock);//这里sbguard相当于一个可以自己解锁的锁比lock_guard灵活但是效率也低
//class test{
//public:
//    void pushin()
//    {
//        for (int i=0; i<1000; i++) {
//            //m1.lock();
//            if (sbguard.owns_lock())//若拿到锁则执行下面的语句此时unique_lock第二个参数为try_to_lock
//            {
//                l1.push_back(i);
//                a++;
//                m1.unlock();
//            }
//            //cout<<a<<endl;
//        }
//    }
//    void popout()
//    {
//        if (!l1.empty())
//        {
//            for (int i=0; i<1000; i++)
//            {
//                //m1.lock();
//                if (sbguard.owns_lock())
//                {
//                    cout<<*l1.begin()<<endl;
//                    l1.pop_front();
//                    a--;
//                    cout<<"a的值为:"<<a<<endl;
//                }
//                //m1.unlock();
//            }
//        }
//        return;
//    }
//};
//once_flag flag;
//static int h=0;
//condition_variable my_cond;
//static int chose=0;
//void thre1()
//{
//    cout<<"线程1等待中......"<<endl;
//    chrono::milliseconds dura(5000);
//    this_thread::sleep_for(dura);
//    chose++;
//    my_cond.notify_one();
//    cout<<"线程1执行结束！"<<endl;
//
//}
//void thre2()
//{
//    my_cond.wait(sbguard,[=](){
//        if (chose>0)
//        {
//            return true;
//        }
//        return false;
//    });
//    cout<<endl;
//    cout<<"线程2执行结束:"<<chose<<endl;
//
//}
//int futurethred()
//{
//    chrono::seconds dura(5);
//    this_thread::sleep_for(dura);
//    cout<<"futurethred()的线程id为:"<<this_thread::get_id()<<endl;
//    return 10;
//}
//class father
//{
//public:
//    int ret()
//    {
//        return i;
//    }
//    void print()
//    {
//        cout<<"hello"<<endl;
//    }
//private:
//    int i=10;
//
//};
//class son:public father
//{
//public:
//    void print1()
//    {
//        cout<<"world"<<endl;
//    }
//
//};
//class father test()//C++中这里前面的class带不带都允许
//{
//    father f1;
//    return f1;
//}
class person
{
public:
    virtual void skin()=0;//纯虚函数（即是抽象类不能实列化对象） 子类必须重写 否则也为抽象类
    virtual void lenth(int lenth)=0;
   virtual ~person()//只有析构函数为虚析构函数时候 delete父类指针时候 子类的析构函数才会被调用
    {
        cout<<"人类的析构函数调用"<<endl;
    }
};
class blackperson:public person
{
public:
    virtual void skin()
    {
        cout<<"这是黑人"<<endl;
    }
    
};
class whiteperson:public person
{
public:
    virtual void skin()
    {
        cout<<"这是白人"<<endl;
    }
    void lenth(int lenth)
    {
        p=new int(lenth);
        cout<<"长度为:"<<*p<<endl;
    }
    ~whiteperson()
    {
        cout<<"白人的析构函数调用"<<endl;
        if (p!=nullptr) {
            delete p;
            p=nullptr;
        }
    }
private:
    int *p;
};

int main()
{
    int lenth=18;
    person* p2=new whiteperson;
    p2->lenth(lenth);//只有子类的函数是继承父类中的函数 才能通过这种方法调出出来 子类自己新加的函数 无法通过父类指针调用
    delete p2;//析构函数只有在实列化出的对象被销毁时候才会被调用 此对象开辟在堆区 所以只有delete时候才会调用析构函数
//    person* p1=new blackperson;//通常利用父类指针指向各种实列化出的子类 再利用多态就能 实现不同效果
//    p1->skin();
//    son s1;
//    father& f1=s1;//基类的取址 可以直接指向派生类
//    father*f2=&s1;//基类指针可以指向派生类的地址无需强转化
//    test frist;
    
    
    
//    thread t1(&test::pushin,&frist);
//    thread t2(&test::popout,&frist);
//    t1.join();
//    t2.join();
// unique_lock<mutex>sbguard(m1,try_to_lock);//这里sbguard相当于一个可以自己解锁的锁比lock_guard灵活但是效率也低
//call_once(once_flag flag,fun) 当两个线程的入口函数都是fun的时候 利用这个函数就能保证这个函数只被调用一次 且调用时候另一个函数会被阻塞
//    call_once(flag, test01);//能够直接调用test01函数运行
//    call_once(flag, test01);
//    cout<<h<<endl;
//    条件变量 condition_variable  wait  notify_one  notify_all
// my_cond(condition_variable实列化出的对象）my_cond.wait(sbguard,[this](){
//  })  //若第三个参数返回值为false则会阻塞在这 直到收到notify的通知 收到通知会再进行一次判断 若为true则继续执行后面代码 否则继续阻塞在这
//    thread t1(thre1);
//    thread t2(thre2);
//    t1.join();
//    t2.join();
//    cout<<"主线程执行结束"<<endl;
// async future 创建后台任务并返回值
//    future<int> result=async(futurethred);//这里会创建新的线程去执行futurethred函数 返回值给result
//    cout<<"主线程等待中..."<<endl;
//    cout<<result.get()<<endl;//会阻塞在这等子线程执行完 这里不管调不调用result.get()主线程都会阻塞等子线程执行结束
//    cout<<"主线程id为:"<<this_thread::get_id()<<endl;
//    son s1;
//    s1.print();
    //cout<<s1.i<<endl; 子类无法直接访问到父类的私有成员
    //cout<<s1.ret()<<endl; 但是可以通过公共接口间接访问
  
    
}
