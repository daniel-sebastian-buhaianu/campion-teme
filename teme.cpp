#include <fstream>
#define MAX_TEME 301
using namespace std;
int nrTeme;
bool elementComun[MAX_TEME][MAX_TEME],
     esteGrupataTema[MAX_TEME];
int numarMinimDeReviste();
int main()
{
    int nrPerechi;
    ifstream fin("teme.in");
    fin >> nrTeme >> nrPerechi;
    while (nrPerechi > 0)
    {
        int i, j;
        fin >> i >> j;
        elementComun[i][j] = elementComun[j][i] = 1;
        nrPerechi--;
    }
    fin.close();
    ofstream fout("teme.out");
    fout << numarMinimDeReviste();
    fout.close();
    return 0;
}
void grupeazaTema(int i)
{
    esteGrupataTema[i] = 1;
    for (int j = 1; j <= nrTeme; j++)
        if (elementComun[i][j] && !esteGrupataTema[j])
            grupeazaTema(j);
}
int numarMinimDeReviste()
{
    int nrReviste = 0;
    for (int i = 1; i <= nrTeme; i++)
        if (!esteGrupataTema[i])
        {
            nrReviste++;
            grupeazaTema(i);
        }
    return nrReviste;
}
