#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 50

void generate_adjacency_matrix(int graph[MAX_SIZE][MAX_SIZE], int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            graph[i][j] = rand() % 2;
            graph[j][i] = graph[i][j]; // так как граф неориентированный
        }
        graph[i][i] = 0; // вершина не соединена сама с собой
    }
}

void print_adjacency_matrix(int graph[MAX_SIZE][MAX_SIZE], int size) {
    printf("Матрица смежности:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

int get_graph_size(int graph[MAX_SIZE][MAX_SIZE], int size) {
    return size;
}

void find_isolated_vertices(int graph[MAX_SIZE][MAX_SIZE], int size) {
    printf("Изолированные вершины: ");
    for (int i = 0; i < size; i++) {
        int is_isolated = 1;
        for (int j = 0; j < size; j++) {
            if (graph[i][j] != 0) {
                is_isolated = 0;
                break;
            }
        }
        if (is_isolated) {
            printf("%d ", i + 1);
        }
    }
    printf("\n");
}

void find_end_vertices(int graph[MAX_SIZE][MAX_SIZE], int size) {
    printf("Концевые вершины: ");
    for (int i = 0; i < size; i++) {
        int degree = 0;
        for (int j = 0; j < size; j++) {
            if (graph[i][j] != 0) {
                degree++;
            }
        }
        if (degree == 1) {
            printf("%d ", i + 1);
        }
    }
    printf("\n");
}

void find_dominating_vertices(int graph[MAX_SIZE][MAX_SIZE], int size) {
    printf("Доминирующие вершины: ");
    for (int i = 0; i < size; i++) {
        int degree = 0;
        for (int j = 0; j < size; j++) {
            if (graph[i][j] != 0) {
                degree++;
            }
        }
        if (degree == size -1) {
            printf("%d ", i + 1);
        }
    }
    printf("\n");
}

int main() {
    int size = 5; // размер графа
    int graph[MAX_SIZE][MAX_SIZE];

    // Генерация матрицы смежности
    generate_adjacency_matrix(graph, size);

    // Печать матрицы смежности
    print_adjacency_matrix(graph, size);

    // Размер графа
    int graph_size = get_graph_size(graph, size);
    printf("Размер графа: %d\n", graph_size);

    // Нахождение изолированных вершин
    find_isolated_vertices(graph, size);

    // Нахождение конечных вершин
    find_end_vertices(graph, size);

    // Нахождение доминирующих вершин
    find_dominating_vertices(graph, size);

    return 0;
}