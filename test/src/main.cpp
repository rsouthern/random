
#include <stdio.h>
#include <time.h>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <string>
#include <sys/time.h>

#include "rand_cpu.h"
#include "rand_gpu.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: test <num floats>\n";
        return EXIT_FAILURE;
    }
    uint N = std::stoi(argv[1]);

    std::vector<float> vec_cpu(N), vec_gpu(N);
    
    // Some stuff we need to perform timings
    struct timeval tim;
    double before, after;

    // Time a function and output the result
    gettimeofday(&tim, NULL);
    before=tim.tv_sec+(tim.tv_usec * 1e-6);
    Rand_CPU::randFloats(vec_cpu);
    gettimeofday(&tim, NULL);
    after=tim.tv_sec+(tim.tv_usec * 1e-6);
    double cpuTime = after - before;

    // Time a function and output the result
    gettimeofday(&tim, NULL);
    before=tim.tv_sec+(tim.tv_usec * 1e-6);
    Rand_GPU::randFloats(vec_gpu);
    gettimeofday(&tim, NULL);
    after=tim.tv_sec+(tim.tv_usec * 1e-6);
    double gpuTime = after - before;

    std::cout << "CPU took "<<cpuTime<<"s, GPU took "<<gpuTime<<"s\n";

    return EXIT_SUCCESS;
}