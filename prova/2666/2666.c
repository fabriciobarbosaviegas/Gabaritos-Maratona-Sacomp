/*Comentarios adicionados posteriormente*/
#include <stdio.h>

#define MAXN 10005
#define MAXE 20005

int N, CAP;
long long E[MAXN];
long long ans;

/* Lista de adjacência */
int head[MAXN], nxt[MAXE], dest[MAXE], wt[MAXE], ecnt;

void add_edge(int u, int v, int w) {
    dest[ecnt] = v;
    wt[ecnt]   = w;
    nxt[ecnt]  = head[u];
    head[u]    = ecnt++;
}

/* Retorna total de ouro na sub-árvore de u;
   acumula custo das arestas filho -> pai         */
long long dfs(int u, int par) {
    long long sub = E[u];
    for (int e = head[u]; e != -1; e = nxt[e]) {
        int v = dest[e], w = wt[e];
        if (v == par) continue;
        long long sv = dfs(v, u);
        /* ceil(sv / CAP) viagens de ida + volta por esta aresta */
        ans += 2LL * ((sv + CAP - 1) / CAP) * w;
        sub += sv;
    }
    return sub;
}

int main(void) {
    scanf("%d %d", &N, &CAP);

    for (int i = 1; i <= N; i++) {
        scanf("%lld", &E[i]);
        head[i] = -1;
    }
    ecnt = 0;

    for (int i = 0; i < N - 1; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        add_edge(a, b, c);
        add_edge(b, a, c);
    }

    ans = 0;
    dfs(1, 0);
    printf("%lld\n", ans);
    return 0;
}