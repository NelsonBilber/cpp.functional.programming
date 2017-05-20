//http://modernescpp.com/index.php/the-definition-of-functional-programming
//http://blog.madhukaraphatak.com/functional-programming-in-c++/

#include <iostream>
#include <functional>
#include <vector>

using namespace std;


struct Foo
{
    Foo(int num):num_(num)
    {}
    
    void print_num(int i)
    {
        std::cout << num_+1 << endl;
    }
    
    int num_;
};

struct PrintNum
{
    void operator()(int i) const
    {
        std::cout << i << endl;
    }
};


void print_num(int i)
{
    std::cout << i << '\n';
}

template <typename Collection,typename unop>
void for_each(Collection col, unop op)
{
    std::for_each(col.begin(),col.end(),op);
}


int main(int argc, char *argv[])
{
    //Class template std::function is a general-purpose polymorphic function wrapper.
    
    // store a free function
    std::function <void (int)> f_display = print_num;
    f_display(89);
    
    // store a call to a data member accessor
    const Foo foo(314159);
    std::function<int(Foo const&)> f_num = &Foo::num_;
    std::cout << "num_: " << f_num(foo) << '\n';
    
    auto lambda_echo = [](int i ) { std::cout << i << std::endl; };
    vector<int> col = {12, 3, 4, 9};
    for_each(col,lambda_echo);
    
    return 0;
}
