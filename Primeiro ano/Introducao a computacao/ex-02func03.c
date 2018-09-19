/*
Escreva uma função de protótipo void init_vetor(int a[], int n, int val);
que inicialize o vetor a com n elementos com o valor de val.
*/
void init_vetor(int a[], int, int);

int main()
{
    int n, val;

    scanf("%d %d", &n, &val);
    int a[n];
    init_vetor(a[n], n, val);
    return 0;
}
void init_vetor(int a[], int n, int val)
{
    int i;

    for(i = 0; i < n; i++){
        a[i] = val;
        printf("%d", a[i]);
    }
}
