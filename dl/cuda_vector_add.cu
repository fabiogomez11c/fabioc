// this is a modification of the vector_add.c with cuda kernel implemented
#include <stdio.h>
#include <cuda_runtime.h>

// compute vector sum c = a + b
// each thread performs one pair-wise addition
// calling this kernel launches a new grid of threads
__global__
void vecAddKernel(float* A, float* B, float* C, int n){
    int i = threadIdx.x + blockDim.x * blockIdx.x;
    if (i < n){
        C[i] = A[i] + B[i];
    }
}

void vecAdd(float* A_h, float* B_h, float* C_h, int n){
    int size = n * sizeof(float); // size of a float data type * the length of the array
    float *A_d, *B_d, *C_d;

    // part 1: allocate device memory for A, B and C
    // copy A and B in device memory
    cudaMalloc((void**)&A_d, size);
    cudaMalloc((void**)&B_d, size);
    cudaMalloc((void**)&C_d, size);

    cudaMemcpy(A_d, A_h, size, cudaMemcpyHostToDevice);
    cudaMemcpy(B_d, B_h, size, cudaMemcpyHostToDevice);

    // part 2: call kernel - to launch a grid of kernels
    // to perform the actual vector addition
    
    // part 3: copy c from the device memory
    // free device vectors
    cudaMemcpy(C_d, C_h, size, cudaMemcpyDeviceToHost);

    cudaFree(A_d);
    cudaFree(B_d);
    cudaFree(C_d);
}

int main()
{
    return 0;
}