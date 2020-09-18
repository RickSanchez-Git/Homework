#include <stdio.h>
#include <stdlib.h>

void outputValues(int m1[], int m2[], int l1, int l2){
    printf("First mas: \n");
    for (int i = 0; i < l1; i++){
        printf("%d \n", m1[i]);
    }
    printf("Second mas: \n");
    for (int i = 0; i < l2; i++){
        printf("%d \n", m2[i]);
    }
}

void setValues(int m1[], int m2[], int l1, int l2){
    printf("Enter %d digits for mas 1: \n", l1);
    for (int i = 0; i < l1; i++){
        if (scanf ("%d", &m1[i]) != 1) {
            printf("Incorrect\n");
            scanf("%*[^\n]");
            --i;
        }
    }
    printf("Enter %d digits for mas 2: \n", l2);
    for (int i = 0; i < l2; i++){
        if (scanf ("%d", &m2[i]) != 1) {
            printf("Incorrect\n");
            scanf("%*[^\n]");
            --i;
        }
    }
}

int push_back(int *pointer, int size, int *pointer_size){
    int wrong_input = 1;
    int ans;
    int *p = (int*)calloc(size + 1, sizeof(int));
    for (int i = 0; i < size; i++){
        p[i] = pointer[i];
    }
    printf("Enter value\n");
    while (wrong_input){
        if (scanf("%d", &ans) != 1) {
            printf("Incorrect\n");
            scanf("%*[^\n]");
        } else {
            wrong_input = 0;
        }
    }
    p[size] = ans;
    free(pointer);
    *pointer_size += 1;
    return p;
}

int _remove(int *pointer, int size, int *pointer_size){
    int wrong_input = 1;
    int ans;
    int *p = (int*)calloc(size - 1, sizeof(int));
    printf("Enter number of element(start from 0)\n");
    while (wrong_input){
        if ((scanf("%d", &ans) != 1) || (ans <= -1) || (ans > size)) {
            printf("Incorrect\n");
            scanf("%*[^\n]");
        } else {
            wrong_input = 0;
        }
    }
    for (int i = 0; i < ans; i++){
        p[i] = pointer[i];
    }
    for (int i = ans + 1; i < size; i++){
        p[i - 1] = pointer[i];
    }
    free(pointer);
    *pointer_size -= 1;
    return p;
}

int main(void)
{
    int second_ans;
    int size_1 = 2;
    int size_2 = 2;
    char ans[80];
    int *mas_1 = (int*)calloc(size_1, sizeof(int));
    int *mas_2 = (int*)calloc(size_2, sizeof(int));
    int off = 1;
    while (off){
        printf("\nEnter command(setValues, outputValues, addValue1(for 1st mas and addValue2 for 2nd mas), deleteValue1, deleteValue2, 0 to exit): \n");
        scanf("%s", &ans);
        if (strcmpi(ans, "setValues") == 0){
            setValues(mas_1, mas_2, size_1, size_2);
        } else if (strcmpi(ans, "outputValues") == 0){
            outputValues(mas_1, mas_2, size_1, size_2);
        } else if (strcmpi(ans, "addValue1") == 0){
            mas_1 = push_back(mas_1, size_1, &size_1);
        } else if (strcmpi(ans, "addValue2") == 0){
            mas_2 = push_back(mas_2, size_2, &size_2);
        } else if (strcmpi(ans, "deleteValue1") == 0){
            mas_1 = _remove(mas_1, size_1, &size_1);
        } else if (strcmpi(ans, "deleteValue2") == 0){
            mas_2 = _remove(mas_2, size_2, &size_2);
        } else if (strcmpi(ans, "0") == 0){
            off = 0;
        } else {
            printf("Incorrect\n");
        }
    }
    return 0;
}
