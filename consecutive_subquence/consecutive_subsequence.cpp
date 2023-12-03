#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    map<int, int> dp; // Mapa para armazenar o comprimento da subsequência

    int ans = 0, lst = -1;

    // Processamento principal
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        dp[v[i]] = dp[v[i] - 1] + 1;

        if (dp[v[i]] > ans) {
            ans = dp[v[i]];
            lst = v[i];
        }
    }

    cout << ans << '\n';

    // Reconstrução da subsequência
    vector<int> tes;
    for (int i = n - 1; i >= 0; --i) {
        if (v[i] == lst) {
            tes.push_back(i + 1); // Ajusta índice para base 1
            lst--;
        }
    }

    reverse(tes.begin(), tes.end());

    // Impressão dos índices da subsequência
    for (auto x : tes) {
        cout << x << ' ';
    }

    return 0;
}
