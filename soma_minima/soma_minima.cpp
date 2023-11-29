class Solution {
public:
    int auxiliar(int i, int j, string s1, string s2, vector<vector<int>> &matriz) {
        int n = s1.length();
        int m = s2.length();
        
        // Verifica se já calculou a solução para os índices i e j
        if (matriz[i][j] != -1) 
            return matriz[i][j];

        int aux = 0;

        // Caso base: Se uma das strings estiver vazia, retorna a soma dos caracteres restantes na outra string
        if (i >= n) {
            int soma2 = 0;
            for (int k = j; k < m; k++) {
                soma2 += (s2[k] - 'a' + 97);
            }
            return soma2;
        }

        if (j >= m) {
            int soma1 = 0;
            for (int k = i; k < n; k++) {
                soma1 += (s1[k] - 'a' + 97);
            }
            return soma1;
        }

        // Caso recursivo: Calcular a solução para os índices i e j
        if (s1[i] == s2[j]) {
            aux = 0 + auxiliar(i + 1, j + 1, s1, s2, matriz);
        } else {
            aux = min((s1[i] - 'a' + 97) + auxiliar(i + 1, j, s1, s2, matriz),
                      (s2[j] - 'a' + 97) + auxiliar(i, j + 1, s1, s2, matriz));
        }

        // Armazenar o resultado na matriz de memoização
        return matriz[i][j] = aux;
    }

    // Abordagem de Tabulação
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        
        // Inicializar a matriz para armazenar resultados intermediários
        vector<vector<int>> matriz(n + 1, vector<int>(m + 1, 0));

        // Calcular as somas totais dos caracteres em ambas as strings
        int soma2 = 0;
        for (int k = 0; k < m; k++) {
            soma2 += (s2[k] - 'a' + 97);
        }

        int soma1 = 0;
        for (int k = 0; k < n; k++) {
            soma1 += (s1[k] - 'a' + 97);
        }

        // Preencher os casos base na matriz 
        matriz[n][0] = soma2;
        for (int j = 1; j <= m; j++) {
            matriz[n][j] = soma2 - (s2[j - 1] - 'a' + 97);
            soma2 -= (s2[j - 1] - 'a' + 97);
        }

        matriz[0][m] = soma1;
        for (int i = 1; i <= n; i++) {
            matriz[i][m] = soma1 - (s1[i - 1] - 'a' + 97);
            soma1 -= (s1[i - 1] - 'a' + 97);
        }

        // Preencher a matriz matriz 
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (s1[i] == s2[j]) {
                    matriz[i][j] = matriz[i + 1][j + 1];
                } else {
                    matriz[i][j] = min((s1[i] - 'a' + 97) + matriz[i + 1][j],
                                  (s2[j] - 'a' + 97) + matriz[i][j + 1]);
                }
            }
        }

        return matriz[0][0];
    }
};
