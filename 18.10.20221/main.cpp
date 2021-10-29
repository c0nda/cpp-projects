#include <iostream>

void sum_char() {
    unsigned char n;
    std::cin >> n;
    int counter = 0;
    double sum = 0;
    for (n = 1; n <= 255; ++n) {
        sum += 1. / double(n * n);
        counter += 1;
        if (n == 255) {
            break;
        }
    }
    std::cout << "Sum: " << sum << std::endl << "Iterations: " << counter << std::endl;
}

void sum_short() {
    unsigned short n;
    std::cin >> n;
    int counter = 0;
    double sum = 0;
    for (n = 1; n <= SHRT_MAX; ++n) {
        sum += 1. / double(n * n);
        counter += 1;
    }
    std::cout << "Sum: " << sum << std::endl << "Iterations: " << counter << std::endl;
}

void sum_int() {
    unsigned int n;
    std::cin >> n;
    int counter = 0;
    double sum = 0;
    for (n = 1; n <= INT_MAX; ++n) {
        sum += 1. / double(n * n);
        counter += 1;
    }
    std::cout << "Sum: " << sum << std::endl << "Iterations: " << counter;
}

void sum_ll() {
    unsigned long long n;
    std::cin >> n;
    int counter = 0;
    double sum = 0;
    for (n = 1; n <= LONG_LONG_MAX; ++n) {
        sum += 1. / double(n * n);
        counter += 1;
    }
    std::cout << "Sum: " << sum << std::endl << "Iterations: " << counter;
}

void hex() {
    int n, rem, counter = 0;
    std::string answer;
    std::cin >> n;
    char letter[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    while (n > 0) {
        rem = n % 16;
        for (int i = 0; i <= 15; ++i) {
            if (rem == i) {
                answer += letter[i];
                break;
            }
        }
        counter += 1;
        n /= 16;
    }
    for (int i = counter - 1; i >= 0; --i) {
        std::cout << answer[i];
    }
}

void time_hms() {
    int h1, m1, s1, h2, m2, s2, h3, m3, s3;
    std::cin >> h1 >> m1 >> s1 >> h2 >> m2 >> s2;
    if (s2 >= s1) {
        s3 = s2 - s1;
    } else {
        s3 = 60 - s1 + s2;
        m2 -= 1;
    }
    if (m2 >= m1) {
        m3 = m2 - m1;
    } else {
        m3 = 60 - m1 + m2;
        h2 -= 1;
    }
    if (h2 >= h1) {
        h3 = h2 - h1;
    } else {
        h3 = -1;
        std::cout << "Invalid values";
    }
    if (h3 != -1) {
        std::cout << h3 << " hours " << m3 << " min " << s3 << " sec";
    }
}

// разница между датами в днях
void time_ymd() {
    int y1, m1, d1, y2, m2, d2;
    int days = 0;
    std::cin >> d1 >> m1 >> y1 >> d2 >> m2 >> y2;
    int years = y2 - y1;
    int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (years == 0) {
        if (((y1 % 4 == 0 && y1 % 100 != 0) || (y1 % 400 == 0)) && (m1 < 3) && ((m2 >= 3) || (m2 == 2) && (d2 == 29))) {
            days += 1;
        }
        for (int i = m1; i < m2; ++i) {
            days += month[i - 1];
        }

        days = days - d1 + d2;
        std::cout << days << " days";
    } else {
        for (int i = m1; i <= 12; ++i) {
            days += month[i - 1];
        }
        if (((y1 % 4 == 0 && y1 % 100 != 0) || (y1 % 400 == 0)) && (m1 < 3)) {
            days += 1;
        }
        days -= d1;

        if (years > 1) {
            for (int i = 1; i < years; ++i) {
                days += 365;
                if (((y1 + i) % 4 == 0 && (y1 + i) % 100 != 0) || ((y1 + i) % 400 == 0)) {
                    days += 1;
                }
            }
        }

        if (((y2 % 4 == 0 && y2 % 100 != 0) || (y2 % 400 == 0)) && ((m2 >= 3) || (d2 == 29) && (m2 == 2))) {
            days += 1;
        }

        for (int i = 1; i < m2; ++i) {
            days += month[i - 1];
        }
        days += d2;
        std::cout << days << " days";
    }
}

// определение дня недели по дате
void dayofweek() {
    int D, M, Y, answerWK;
    std::cin >> D >> M >> Y;
    std::string nameWeekDay[7] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    int a = (14 - M) / 12;
    int y = Y - a;
    int m = M + 12 * a - 2;
    answerWK = (D + y + y / 4 - y / 100 + y / 400 + 31 * m / 12) % 7;
    std::cout << nameWeekDay[answerWK];
}

void roman() {
    int n;
    std::cin >> n;
    if (n >= 1000) {
        for (int i = 1; i <= n / 1000; ++i) {
            std::cout << "M";
        }
        n %= 1000;
    }
    if (n >= 900) {
        std::cout << "CM";
        n %= 100;
    }
    if (n >= 500) {
        std::cout << "D";
        for (int i = 1; i <= n / 100 - 5; ++i) {
            std::cout << "C";
        }
        n %= 100;
    }
    if (n >= 400){
        std::cout << "CD";
        n %= 100;
    }
    if (n >= 100) {
        for (int i = 1; i <= n / 100; ++i){
            std::cout << "C";
        }
        n %= 100;
    }
    if (n >= 90){
        std::cout << "XC";
        n %= 10;
    }
    if (n >= 50){
        std::cout << "L";
        for (int i = 1; i <= n / 10 - 5; ++i){
            std::cout << "X";
        }
        n %= 10;
    }
    if (n >= 40){
        std::cout << "XL";
        n %= 10;
    }
    if (n >= 10){
        for (int i = 1; i <= n / 10; ++i){
            std::cout << "X";
        }
        n %= 10;
    }
    if (n == 9){
        std::cout << "IX";
    }
    if (n >= 5 && n < 9){
        std::cout << "V";
        for (int i = 1; i <= n - 5; ++i){
            std::cout << "I";
        }
    }
    if (n == 4){
        std::cout << "IV";
    }
    if (n < 4){
        for (int i = 1; i <= n; ++i){
            std::cout << "I";
        }
    }
}

int main() {
//    sum_char();
//    sum_short();
//    sum_int();
//    sum_ll();
//    time_hms();
//    time_ymd();
//    dayofweek();
//    hex();
//    roman();
    return 0;
}
