#include <iostream>

#include "../src/Env.cpp"

using namespace std;
int main(){
    cout<<"LibEnvCpp example:"<<endl;
    Env env("test.env"); // load env file

    string foo = env.getVal("foo");//get env values
    string bar = env.getVal("bar");

    cout<<foo<<" "<<bar<<endl;




}