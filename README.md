# hello_world

This repository contains a simple C++ program to calculate the eigenvalues of a 1D tight binding Hamiltonian with periodic boundary conditions.

## Building

Compile the program using a C++11 compatible compiler:

```bash
g++ -std=c++11 -o tight_binding tight_binding.cpp
```

## Usage

Run the executable and provide the number of lattice sites `N`, hopping parameter `t`, and onsite energy `epsilon`:

```bash
./tight_binding N t epsilon
```

For example, to compute energies for a 4-site chain with hopping `t=1` and zero onsite energy:

```bash
./tight_binding 4 1.0 0.0
```

The output will list the eigenvalues of the system.
