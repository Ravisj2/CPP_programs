#include<iostream>
using namespace std;
class A
{
	public:
		A()
		{
		cout<<"constructor stated"<<endl;
		}
		A (A &bob22)
		{
		xx = bob22.xx;
		}
		void fun(int aa)
		{
			xx=aa;
		}
		void display()
		{
			cout<<xx<<endl;
		}
		int xx;
};
int main()
{
	A obj;
	obj.fun(900);
	obj.display();
	A obj2=obj;
	obj.display();
	return 0;
}
