void add_vector(int *a, int *b, int *result, int num_dimensions) {
    for (int i = 0; i < num_dimensions; ++i) {
        result[i] = a[i] + b[i];
    }
}

void multiply_vector(int *a, int *b, int *result, int num_dimensions) {
    for (int i = 0; i < num_dimensions; ++i) {
        result[i] = a[i] * b[i];
    }
}
