#include <iostream>
#include <typeinfo>

using namespace std;

class	parent{

  public :
	parent(){cout << "Constructor parent"<< endl;}
	void	print(void)
	{
	  std::cout << "TEST" << std::endl;
	}
	int	i = 0;
};

class	child : public parent
{
  public :
	child(){cout << "Constructor child"<< endl;}
	void	print(void)
	{
	  std::cout << "CHILD" << std::endl;
	}
	int	i = 1;
};

class	child2 : public parent
{
  public :
	child2(){cout << "Constructor child2"<< endl;}
	int	i = 2;

};

class	test{
  public :
	test();
	test(child c);
	test(child2 c);
};

void	f(test t)
{
  (void)t;
  cout << "test" << endl;
}

int	main(void)
{
  test	a;
  f(a);
  return (0);
}
