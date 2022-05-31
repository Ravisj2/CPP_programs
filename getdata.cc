# include <iostream>
using namespace std;
class A
{
	int a;
	public:
	A()
	{
	cout<<"iam starting constructor"<<endl;
	}
	void setdata (int x)
	{
		a=x;
	}
	int getdat()
	{
	 return a;
	}
};
int main()
{
	A obj;
	obj.setdata(870);
	cout<<"ravi:"<<obj.getdat()<<endl;
	return 0;
}

