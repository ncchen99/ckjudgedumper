void add_mat(const struct mat *m1_p, const struct mat *m2_p, struct mat *result_p) {  // matrix addition
    *result_p = *m1_p;
    for (int i = 0; i < m1_p->row; i++)
        for (int j = 0; j < m1_p->col; j++)
            result_p->value[i][j] += m2_p->value[i][j];
}

void mul_mat(const struct mat *m1_p, const struct mat *m2_p, struct mat *result_p) {  // matrix multiplication
    result_p->row = m1_p->row;
    result_p->col = m2_p->col;
    memset(result_p->value, 0, sizeof(result_p->value));
    for (int i = 0; i < m1_p->row; i++)
        for (int j = 0; j < m1_p->col; j++)
            for (int k = 0; k < m2_p->col; k++)
                result_p->value[i][k] += m1_p->value[i][j] * m2_p->value[j][k];
}