#include <iostream>
using namespace std;
class A
{
int xx;
void fun (int aa)
{
	xx=aa;
}
void display ()
{
	cout<<"xx="<<xx<<endl;
}
A ()
{
	cout <<"iam in constuctor"<<endl;
}
A (A &obbj22)
{
	xx=obbj22.xx;
	}
friend void test();
};
void test ()
{
	A obj;
	obj.fun(980);
	obj.display();

}
int main ()
{
	test();
	return 0;
}


