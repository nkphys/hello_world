#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <algorithm>

int main(int argc, char* argv[]) {
    if (argc < 5) {
        std::cout << "Usage: " << argv[0] << " Nx Ny t epsilon [bins]" << std::endl;
        return 1;
    }

    int Nx = std::atoi(argv[1]);
    int Ny = std::atoi(argv[2]);
    double t = std::atof(argv[3]);
    double epsilon = std::atof(argv[4]);
    int bins = (argc > 5) ? std::atoi(argv[5]) : 100;

    std::vector<double> energies;
    energies.reserve(static_cast<size_t>(Nx) * static_cast<size_t>(Ny));
    for (int ix = 0; ix < Nx; ++ix) {
        double kx = 2.0 * M_PI * ix / Nx;
        for (int iy = 0; iy < Ny; ++iy) {
            double ky = 2.0 * M_PI * iy / Ny;
            double energy = epsilon + 2.0 * t * (std::cos(kx) + std::cos(ky));
            energies.push_back(energy);
        }
    }

    std::cout << "Eigenvalues:" << std::endl;
    for (const auto& e : energies) {
        std::cout << e << std::endl;
    }

    double minE = *std::min_element(energies.begin(), energies.end());
    double maxE = *std::max_element(energies.begin(), energies.end());
    double bin_width = (maxE - minE) / bins;
    std::vector<double> dos(bins, 0.0);

    for (const auto& e : energies) {
        int bin = static_cast<int>((e - minE) / bin_width);
        if (bin >= bins) bin = bins - 1;  // handle upper edge
        dos[bin] += 1.0;
    }

    double norm = energies.size() * bin_width;
    for (auto& v : dos) {
        v /= norm;
    }

    std::ofstream out("dos.txt");
    for (int i = 0; i < bins; ++i) {
        double ecenter = minE + (i + 0.5) * bin_width;
        out << ecenter << " " << dos[i] << '\n';
    }
    out.close();
    std::cout << "Density of states written to dos.txt" << std::endl;

    return 0;
}
