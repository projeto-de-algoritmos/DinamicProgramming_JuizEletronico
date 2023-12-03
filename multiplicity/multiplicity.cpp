#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, ans = 0;
    cin >> n;
    vector<int> a(n + 1), cnt(n + 1, 0);
    cnt[0] = 1; // Caso base: há uma maneira de ter uma subsequência de comprimento 0.

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        vector<int> divisors;

        // Encontrar todos os divisores de a[i] que sejam menores ou iguais a n.
        for (int j = 1; j * j <= a[i]; j++) {
            if (a[i] % j == 0) {
                if (j <= n) divisors.push_back(j);
                if (j != a[i] / j && a[i] / j <= n) divisors.push_back(a[i] / j);
            }
        }

        // Processar divisores em ordem decrescente.
        sort(divisors.begin(), divisors.end(), greater<int>());
        for (int div : divisors) {
            cnt[div] = (cnt[div] + cnt[div - 1]) % MOD;
        }
    }

    // Somar as contagens de todas as extensões.
    for (int i = 1; i <= n; i++) {
        ans = (ans + cnt[i]) % MOD;
    }

    cout << ans << endl;
    return 0;
}
