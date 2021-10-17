#include <iostream>

void leftDown(int n) {
    std::string s;
    for (int i = 1; i <= n; ++i){
        s += "*";
        std::cout << s << std::endl;
    }

}


void leftUp(int n){
    for (int i = 0;i < n;++i) {
        std::string s;
        for (int j = n - i;j > 0; --j) {
            s += "*";
        }
        std::cout << s << std::endl;
    }
}


void rightDown(int n){
    for (int i = 1;i <= n;++i) {
        std::string s;
        for (int j = n - i;j > 0; --j) {
            s += " ";
        }
        for (int a = 1;a <= i;++a) {
            s += "*";
        }
        std::cout << s << std::endl;
    }
}


void rhombus(int n){
    for (int i = 1;i <= n;++i) {
        std::string s;
        for (int j = n - i;j > 0; --j) {
            s += " ";
        }
        for (int a = 1;a <= 2 * i - 1;++a) {
            s += "*";
        }
        std::cout << s << std::endl;

    }
    for (int i = n - 1;i > 0;--i) {
        std::string s;
        for (int j = n - i;j > 0; --j) {
            s += " ";
        }
        for (int a = 1;a <= 2 * i - 1;++a) {
            s += "*";
        }
        std::cout << s << std::endl;
    }
}


int main() {
    int n;
    std::cin >> n;
    std::cout << std::endl;

    leftDown(n);
    std::cout << std::endl;
    std::cout << "-----------------------------" << std::endl;

    leftUp(n);
    std::cout << std::endl;
    std::cout << "-----------------------------" << std::endl;

    rightDown(n);
    std::cout << std::endl;
    std::cout << "-----------------------------" << std::endl;

    rhombus(n);
    std::cout << std::endl;
    std::cout << "-----------------------------" << std::endl;
}
