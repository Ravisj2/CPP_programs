#include <iostream>
using namespace std;
class Test
{	
	public:
	int a,b;
	Test()
 {
	 cout<<"iam constructor,,"<<endl;
 }
	Test(int a)
	{
		cout<<"iam one argument constriuctor"<<endl;
	}
	~Test()
	{
		cout<<"iam a distructor"<<endl;
	}
	void fun (int x,int y)
	{
		a=x;
		b=y;
	}
};
int main()
{
	Test *ptr= new Test();
	ptr->fun(40,50);
	cout<<ptr->a<<ptr->b<<endl;
	delete ptr;
	return 0;
}


