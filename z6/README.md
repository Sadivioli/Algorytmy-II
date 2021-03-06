# Zestaw 6

## Zadanie A

Proszę zaimplementować ADT graph, posiadający wszystkie operacje z `zadania A` w `zestawie 4`. Tym razem proszę wykorzystać reprezentację w której dla każdego wierzchołka przechowywana jest list sąsiadów. Sprawdzić złożoność obliczeniową wybranej operacji i porównać z `zadaniem A` `zestawu 4`.

## Zadanie B

Proszę się zastanowić jak wykorzystać reprezentację grafową do rozwiązania problemu znalezienia minimalnej liczby "faz" sygnalizacji świetlnej na skrzyżowaniu (strzałeczki oznaczają ulice jednokierunkowe):


Sygnalizacja świetlna w każdej "fazie" powinna zezwalać na ruch przez skrzyżowanie jedynie tym samochodom, których trajektorie nie będą się przecinać. Aby usprawnić działanie skrzyżowania, liczba tych etapów powinna być jak najmniejsza.

Wykorzystując jedną z napisanych przez Państwa implementacji grafów oraz `zadanie A` z poprzedniego zestawu proszę narysować reprezentację grafową takiego skrzyżowania.

Rozwiązanie zadania B:

Budujemy graf, w którym wierzchołkami są możliwe trasy, a krawędzie istnieją pomiędzy trasami, które ze sobą kolidują.

Aby znaleźć najmniejszą ilość cykli musimy zastosować algorytm kolorowania grafu. Każdy kolor odpowiada jednej fazie w cyklu

## Zadanie C

Na szachownicy, na określonej pozycji, znajduje się pojedyncza figura - skoczek (koń). Proszę znaleźć taką trasę skoczka po szachownicy, aby każde pole było odwiedzone jedynie raz. Można wykorzystać jedną z wcześniej zaimplementowanych przez Państwa reprezentacji grafu lub skorzystać z gotowych bibliotek. Państwa wynik końcowy proszę przedstawić w formie rysunku.

### Depth-first search z heurystyką Warnsdorff'a

Program `ZadanieC` rozpoczyna poszukiwanie z losowego pola szachownicy i wykorzystuje rekurencyjne przeszukiwanie grafu wgłąb. Pola, z których można wykonać najmniej ruchów są odwiedzane w pierwszej kolejności. Program szuka wszystkich możliwości (po wyszukaniu kilku polecam go przerywać przez `Ctrl+C`)

Przykładowa trasa odnaleziona przez program:


Złożoność obliczeniowa
  g++ complex.cpp graph.cpp -o complex
	./complex

Graf A: 
    dot -Tjpg graph.txt -o graphA.jpg

Graf B: 
    dot -Tjpg graf_schema.txt -o grafB.jpg
