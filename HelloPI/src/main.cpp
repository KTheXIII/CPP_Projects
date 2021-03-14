#include <iostream>
#include <cmath>
#include <string>
#include <cstdio>

double pi_bbp(double k) {
    return (1.0 / std::pow(16.0, k)) *
           ((4.0 / (8.0 * k + 1.0)) - (2.0 / (8.0 * k + 4.0)) -
            (1.0 / (8.0 * k + 5.0)) - (1.0 / (8.0 * k + 6.0)));
}

int main(int argc, char const* argv[]) {
    double sum = 0;

    double max_iterations = 1000000000.0;
    if (argc > 1) {
        std::string arg1 = argv[1];
        try {
            max_iterations = std::stod(arg1);
        } catch (std::exception& e) {
            std::cerr << e.what() << "\n";
        }
    }
    for (double i = 0; i < max_iterations; i++) sum += pi_bbp(i);

    std::cout.precision(17);
    std::cout << "PI (BBP): " << std::fixed << sum << "\n";

    return 0;
}
