// this is a modification of the vector_add.c with cuda kernel implemented
#include <stdio.h>
#include <cuda_runtime.h>

// compute vector sum c = a + b
// each thread performs one pair-wise addition
// calling this kernel launches a new grid of threads
__global__
void vecAddKernel(float* A, float* B, float* C, int n){
    int i = threadIdx.x + blockDim.x * blockIdx.x; // very important to understand blockDim vs blockIdx
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
    // <<<dimGrid, dimBlock>>>
    vecAddKernel<<<ceil(n/256.0), 256>>>(A_d, B_d, C_d, n);
    
    // part 3: copy c from the device memory
    // free device vectors
    cudaMemcpy(C_h, C_d, size, cudaMemcpyDeviceToHost);

    cudaFree(A_d);
    cudaFree(B_d);
    cudaFree(C_d);
}

int main()
{
    float A[5] = {1.0, 2.0, 3.0, 4.0, 5.0};
    float B[5] = {1.0, 2.0, 3.0, 4.0, 5.0};
    float C[5];

    vecAdd(A, B, C, 5);

    return 0;
}