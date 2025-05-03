#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int* original_list;
int* sorted_list;
int size;

typedef struct {
    int start;
    int end;
} ThreadArgs;

void bubble_sort(int start, int end) {
    for (int i = start; i < end - 1; i++) {
        for (int j = start; j < end - 1 - (i - start); j++) {
            if (original_list[j] > original_list[j + 1]) {
                int temp = original_list[j];
                original_list[j] = original_list[j + 1];
                original_list[j + 1] = temp;
            }
        }
    }
}

void* sort_thread(void* args) {
    ThreadArgs* arg = (ThreadArgs*)args;
    bubble_sort(arg->start, arg->end);
    pthread_exit(NULL);
}

void* merge_thread(void* args) {
    int mid = size / 2;
    int i = 0, j = mid, k = 0;

    while (i < mid && j < size) {
        if (original_list[i] < original_list[j]) {
            sorted_list[k++] = original_list[i++];
        } else {
            sorted_list[k++] = original_list[j++];
        }
    }

    while (i < mid) {
        sorted_list[k++] = original_list[i++];
    }

    while (j < size) {
        sorted_list[k++] = original_list[j++];
    }

    pthread_exit(NULL);
}

int main() {
    printf("Enter number of elements: ");
    scanf("%d", &size);

    original_list = (int*)malloc(size * sizeof(int));
    sorted_list = (int*)malloc(size * sizeof(int));

    if (original_list == NULL || sorted_list == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter %d integers:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &original_list[i]);
    }

    pthread_t tid1, tid2, tid_merge;
    ThreadArgs args1 = {0, size / 2};
    ThreadArgs args2 = {size / 2, size};

    pthread_create(&tid1, NULL, sort_thread, &args1);
    pthread_create(&tid2, NULL, sort_thread, &args2);

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    pthread_create(&tid_merge, NULL, merge_thread, NULL);
    pthread_join(tid_merge, NULL);

    printf("Sorted list: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", sorted_list[i]);
    }
    printf("\n");

    free(original_list);
    free(sorted_list);

    return 0;
}
