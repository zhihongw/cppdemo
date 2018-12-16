#include <iostream>
#include <vector>

using namespace std;

class Foo {
    public:
        Foo() {
            cout<<"Foo copy func called"<<endl;
        }
};

int main() {
    vector<vector<Foo> > v1;
    vector<Foo> v11;
    v11.push_back(Foo());
    v1.push_back(v11);
    vector<vector<Foo> > v2(v1);
    return 0;
}

