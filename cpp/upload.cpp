
#include <iostream>
using namespace std;
int main(){
    string *s=new string("adsf");
    cout<<*s<<endl;
    delete(s);
    return 0;
}
