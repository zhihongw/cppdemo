#include <vector>

using namespace std;

class Base {
public:
    virtual void func()=0;
};

class D1 : public Base {
public:
    void func() {cout<<"D1"<<endl;}
};

class D2 : public Base {
public:
    void func() {cout<<"D2"<<endl;}
};

template <typename T>
void wrapper(T fptr) {
  fptr();
}

int main() {
    D1 d1;
    D2 d2;
    auto f1 = std::bind(&Base::func, d1);
    auto f2 = std::bind(&Base::func, d2);

    wrapper(f1);
    wrapper(f2);
    return 0;
}
