#include<iostream>
using namespace std;

#define MAXN 1000001

int n, m, d; // dlugosc lancucha, dlugosc opisu, dlugosc ladnego fragmentu
int l[MAXN], c[MAXN]; // tablica ilości lancuchów, tablica kolorów
int lancuch[MAXN], ile_w_kolorze[MAXN], ile_ma_byc[MAXN];
int ile_niezgodnosci, wynik;

void licz_zgodnosc(int k, int dodaj) { // dodaj = +1 - dodajemy ogniwo w kolorze k, dodaj = -1 - odejmujemy
    if(ile_w_kolorze[k] == ile_ma_byc[k]) ile_niezgodnosci++;
    ile_w_kolorze[k] += dodaj;
    if(ile_w_kolorze[k] == ile_ma_byc[k]) ile_niezgodnosci--;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> l[i];
        d += l[i];
        if(d > n) {
            cout << 0 << "\n";
            return 0;
        }
    }
    for(int i = 0; i < m; i++) {
        cin >> c[i];
    }
    for(int i = 0; i < m; i++)
        ile_ma_byc[c[i]] = l[i]; // lanuchów koloru c[i] jest w ilości l[i]
    for(int i = 0; i < n; i++) {
        cin >> lancuch[i];
    }

    ile_niezgodnosci = m;
    for(int i = 0; i < d; i++) // sprawdz, czy pierwsze d elementów tworzą ładny fragment
        licz_zgodnosc(lancuch[i], 1);
    if(ile_niezgodnosci == 0) wynik++;
    for(int i = 0; i + d < n; i++) { // sprawdzaj kolejne kombinacje, czy tworzą ładny fragment usuwając najstarszy i dodając najnowszy łańcuch
        licz_zgodnosc(lancuch[i], -1);
        licz_zgodnosc(lancuch[i + d], 1);
        if(ile_niezgodnosci == 0) wynik++;
    }

    cout << wynik << "\n";
    return 0;
}
