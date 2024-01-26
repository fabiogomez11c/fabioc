
void vecAdd(float* A_h, float* B_h, float* C_h, int N){
    for (int i = 0; i < N; ++i){
        C_h[i] = A_h[i] + B_h[i];
    }
}

int main(){

    float A[5] = {1.0, 2.0, 3.0, 4.0, 5.0};
    float B[5] = {1.0, 2.0, 3.0, 4.0, 5.0};
    float C[5];

    vecAdd(A, B, C, 5);

    return 0;
}