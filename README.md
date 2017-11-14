# random
A small boilerplate for using qmake to compile CUDA libraries.

## Configuration
The following environment variables are needed to compile this out of the box:
* CUDA_PATH : Needs to point to the base directory of your cuda lib and includes
* CUDA_ARCH : Your local device compute (e.g. 30 or 52 or whatever)
* HOST_COMPILER : Your local g++ compiler (remember, cuda compiles only with g++ 4.9)

## Build instructions
Assuming you have Qt installed, you should just have to type qmake and make from the command line to get this compiled. To run the test, simply type 
> bin/test <numFloats>
were numfloats is the number of random floats you want.

## What it does
This will build two libraries to do roughly the same thing, one in CUDA and one using STL random. It also builds a simple test application which links against both libraries and measures the performance on each.

The main thing to be looking at is the .pro file for the cuda library, which is non-obvious.

The performance comparison isn't exactly fair as the GPU memory allocation and copy is being added in the total computation time, which is the main reason the CPU outperforms the GPU for most problem sizes (unless they get really big).

## Things to note
I've only tested this on Linux. It is currently configured for the NCCA lab build, which is a little non-standard in the installation directories for CUDA. Hopefully it is relatively easy to modify the project file(s) to accomodate alternative build environments.

