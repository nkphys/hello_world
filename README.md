# hello_world

This repository contains a simple C++ program that calculates the eigenvalues of a two-dimensional tight binding Hamiltonian with periodic boundary conditions. The program also writes the single particle density of states to a file.

## Building

Compile the program using a C++11 compatible compiler:

```bash
g++ -std=c++11 -o tight_binding tight_binding.cpp
```

## Usage

Run the executable and provide the lattice dimensions `Nx` and `Ny`, hopping parameter `t`, and onsite energy `epsilon`. Optionally a number of histogram bins for the DOS can be supplied:

```bash
./tight_binding Nx Ny t epsilon [bins]
```

For example, to compute energies for a `4x4` lattice with hopping `t=1` and zero onsite energy using 100 bins:

```bash
./tight_binding 4 4 1.0 0.0 100
```

The program will print all eigenvalues to the console and write the density of states to `dos.txt`.
