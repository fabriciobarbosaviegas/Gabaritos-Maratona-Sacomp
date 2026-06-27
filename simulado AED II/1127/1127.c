/*Comentarios adicionados posteriormente*/

#include <stdio.h>

#define MAXN 255
#define INF  1000000

int N, M, C, K;
int adj[MAXN][MAXN];   /* matriz de adjacência; -1 = sem aresta */
int dist[MAXN];
int visited[MAXN];
int route_cost[MAXN];  /* pedágio acumulado da rota a partir de i até C-1 */

void dijkstra(int src) {
    for (int i = 0; i < N; i++) {
        dist[i]    = INF;
        visited[i] = 0;
    }
    dist[src] = 0;

    for (int iter = 0; iter < N; iter++) {
        /* cidade não visitada com menor distância */
        int u = -1;
        for (int i = 0; i < N; i++)
            if (!visited[i] && dist[i] < INF)
                if (u == -1 || dist[i] < dist[u]) u = i;

        if (u == -1) break;
        visited[u] = 1;

        /* cidade da rota de serviço: nó terminal, não expande */
        if (u < C) continue;

        for (int v = 0; v < N; v++)
            if (adj[u][v] >= 0 && !visited[v]) {
                int nd = dist[u] + adj[u][v];
                if (nd < dist[v]) dist[v] = nd;
            }
    }
}

int main(void) {
    while (scanf("%d %d %d %d", &N, &M, &C, &K) == 4) {
        if (!N && !M && !C && !K) break;

        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                adj[i][j] = -1;

        for (int i = 0; i < M; i++) {
            int u, v, p;
            scanf("%d %d %d", &u, &v, &p);
            adj[u][v] = p;
            adj[v][u] = p;
        }

        /* custo de seguir a rota a partir da cidade i até C-1 */
        route_cost[C - 1] = 0;
        for (int i = C - 2; i >= 0; i--)
            route_cost[i] = adj[i][i + 1] + route_cost[i + 1];

        dijkstra(K);

        /* melhor ponto de entrada na rota */
        int ans = INF;
        for (int i = 0; i < C; i++)
            if (dist[i] < INF) {
                int total = dist[i] + route_cost[i];
                if (total < ans) ans = total;
            }

        printf("%d\n", ans);
    }

    return 0;
}