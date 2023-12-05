class Solution {
public:
    int dividir(int i,int ultimo, vector<int>& slices, int n,  vector<vector<int>> &matriz){
        if(n==0){
            return 0;
        }
        if(i>ultimo){
            return 0;
        }
        if(matriz[i][n]!=-1){
            return matriz[i][n];
        }

    int pegar = slices[i] + dividir(i+2,ultimo,slices,n-1,matriz);
    int nao_pegar = 0 + dividir(i+1,ultimo,slices,n,matriz);
    matriz[i][n]= max(pegar ,nao_pegar );
    return matriz[i][n];

    }


    int maxSizeSlices(vector<int>& slices) {
        int k=slices.size();
        int n=k/3;
        vector<vector<int>> matriz1(k, vector<int>(k,-1));
        int case1=dividir(0,k-2,slices,n,matriz1);
                vector<vector<int>> matriz2(k, vector<int>(k,-1));
        int case2=dividir(1,k-1,slices,n,matriz2);
        return max(case1,case2);
    }
};