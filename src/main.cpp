#include <iostream>
#include <fmt/format.h>
#include <my_lib.h>
#include <concepts>

template<class T>
concept Printable = requires(std::ostream& os, T a)
{
    os << a;
};

template<Printable T>
void print(const T& a){
    std::cout << a << std::endl;
}

int main(int argc, char* argv[]){
    std::cout << "Hello, World!\n";
    int c = lib::add(5, 6);
    
    print(c);
    
    return 0;
}
