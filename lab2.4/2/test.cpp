
void ford_bellman(int n, int m, int s, int f) {
  vector<long long int> d (n, INF);
  d[s] = 0;
  for (size_t i = 0; i < n-1; i++) {
    bool any = false;
    for (size_t j = 0; j < m; j++) {
      if (d[e[j][0]] < INF) {
        d[e[j][1]] = (d[e[j][1]] < d[e[j][0]]+e[j][2]) ? d[e[j][1]] : d[e[j][0]]+e[j][2];
        any = true;
      }
    }
    if (!any)  break;
  }
  answ = d[f];
}
