#include <iostream>
#include <cmath>

void lines() {
    double xa, ya, xb, yb, xc, yc;
    std::cin >> xa >> ya >> xb >> yb >> xc >> yc;
    int len = 10;
    if (sqrt((xc - xa) * (xc - xa) + (yc - ya) * (yc - ya)) + sqrt((xc - xb) * (xc - xb) + (yc - yb) * (yc - yb)) ==
        len) {
        std::cout << "yes";
    } else {
        std::cout << "no";
    }
}

void lines_without_sqrt() {
    double xa, ya, xb, yb, xc, yc;
    std::cin >> xa >> ya >> xb >> yb >> xc >> yc;
    int len = 10;
    double ac = (xc - xa) * (xc - xa) + (yc - ya) * (yc - ya);
    double bc = (xc - xb) * (xc - xb) + (yc - yb) * (yc - yb);
    if ((4 * ac * bc) == (len * len - ac - bc) * (len * len - ac - bc)) {
        std::cout << "yes";
    } else {
        std::cout << "no";
    }
}

void sum_sin() {
    int n; // n от 1
    double x;
    std::cin >> n >> x;
    double sum = 0;
    sum += sin(x);

    for (int i = 1; i <= n; ++i) {
        sum += sin(sum);
    }
    std::cout << sum << std::endl;
}

void geeseandrabbits() {
    int counter = 0;
    int n, paws, geese, rabbits;
    std::cin >> n;
    paws = n * 2;
    geese = n;
    rabbits = 0;
    do {
        std::cout << "geese " << geese << " rabbits " << rabbits << std::endl;
        rabbits += 1;
        geese -= 2;
        counter += 1;
    } while (geese != -1 && geese != -2);
    std::cout << counter;
}

void pi() {
    int n, pres;
    int j = 1;
    std::cin >> pres >> n;
    double pi_ = 0.;
    for (int i = 1; i <= pres; ++i) {
        pi_ += (double) 4 / j;
        j += 2;
        pi_ -= (double) 4 / j;
        j += 2;
    }
}

void pointsInCircle() {
    double r;
    std::cin >> r;
    int counter = 0;
    for (int x = -(int) r; x <= r; ++x) {
        for (int y = -(int) r; y <= r; ++y) {
            if (x * x + y * y <= r * r) {
                counter += 1;
            }
        }
    }
    std::cout << counter;
}

void pointsInCircle2() {
    double a, r, x, y;
    int pres;
    int counter = 0;
    std::cin >> pres >> a;
    r = a / 2.;
    for (int i = 1; i <= pres; ++i) {
        x = rand() / (double) RAND_MAX * r; // NOLINT(cert-msc30-c, cert-msc50-cpp)
        y = rand() / (double) RAND_MAX * r; // NOLINT(cert-msc30-c, cert-msc50-cpp)
        if (x * x + y * y <= r * r) {
            counter += 1;
        }
    }
    std::cout << 4 * (double) counter / (double) pres;
}

void sumProdOfNum() {
    int n;
    std::cin >> n;
    int sum = 0;
    int prod = 1;
    while (n > 0) {
        sum += n % 10;
        prod *= n % 10;
        n /= 10;
    }
    std::cout << "Sum: " << sum << std::endl << "Product: " << prod;
}

void collatz() {
    int n;
    std::cin >> n;
    std::cout << n << " ";
    while (n != 1) {
        if (n % 2 == 0) {
            n /= 2;
            std::cout << n << " ";
        } else {
            n = 3 * n + 1;
            std::cout << n << " ";
        }
    }
}

void taylor() {
    int pres;
    int j = 1 * 2 * 3;
    double x;
    double sum = 0;
    std::cin >> x >> pres;
    sum += x;
    for (int i = 1; i <= pres; ++i) {
        sum += pow(-1, i) * pow(x, 2 * i + 1) / j;
        j *= (i + 3) * (i + 4);
    }
    std::cout << sum;
}

int main() {
//    lines();
//    lines_without_sqrt();
//    sum_sin();
//    animals();
//    pi();
//    pointsInCircle();
//    sumProdOfNum();
//    collatz();
//    pointsInCircle2();
//    taylor();
//    geeseandrabbits();
    return 0;
}

