## Zadanie A

Proszę zaimplementować typ `priorotyQueue` będący oparty na matematycznym zbiorze i posiadający, dla słownika `A` oraz elementu `x`, operacje:

- wstawianie elementu `x` do kolejki `A`
- zwracanie i jednocześnie usuwanie elementu o najmniejszym "priorytecie" z kolejki `A`

Niech `p(x)` będzie funkcją zwracającą "priorytet" elementu `x`. Jeżeli w słowniku przechowywane będą liczby całkowite, priorytetem może być identyczność - `p(1) = 1, p(2) = 2, ...`

Państwa implementację proszę oprzeć na wybranej, omawianej wcześniej, implementacji zbioru. Proszę zbadać złożoność obliczeniową operacji usuwania z kolejki elementu o najmniejszym "priorytecie" (wykres, wartość teoretyczna, dyskusja).