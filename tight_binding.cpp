#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>

int main(int argc, char* argv[]) {
    if (argc < 4) {
        std::cout << "Usage: " << argv[0] << " N t epsilon" << std::endl;
        return 1;
    }
    int N = std::atoi(argv[1]);
    double t = std::atof(argv[2]);
    double epsilon = std::atof(argv[3]);

    std::vector<double> energies;
    energies.reserve(N);
    for (int k = 0; k < N; ++k) {
        double kappa = 2.0 * M_PI * k / N;
        double energy = epsilon + 2.0 * t * std::cos(kappa);
        energies.push_back(energy);
    }

    std::cout << "Eigenvalues:" << std::endl;
    for (int i = 0; i < N; ++i) {
        std::cout << energies[i] << std::endl;
    }

    return 0;
}
