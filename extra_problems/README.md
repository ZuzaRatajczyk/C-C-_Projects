# Ile dób?
Program oblicza liczbę zadanych przedziałów czasu mieszczących się pomiędzy dwiema chwilami (ile dób dzieli dane daty)
Chwilę określamy przez podanie szóstki liczb całkowitych *r*, *m*, *d*, *g*, *min*, *s* oznaczających kolejno rok, miesiąc, dzień, godzinę, minutę i sekundę 
(1600≤r≤2500, 1≤m≤12, 1≤d≤31, 0≤g≤23,0≤min≤59, 0≤s≤59).


### Wejście standardowe

Pierwsza linia standardowego wejścia zawiera liczbę całkowitą D(1≤D≤2000), oznaczającą liczbę zestawów danych, 
które są umieszczone w kolejnych 2*D wierszach. Każdy zestaw składa się z dwóch wierszy, które zawierają po sześć liczb całkowitych definiujących dwa punkty 
*T1* i *T2* na  osi  czasu.  
Chwila *T1* zawsze  poprzedza  (jest  wcześniejsza) chwilę *T2*. 
Wszystkie liczby w wierszach są rozdzielone pojedynczymi spacjami.
Należy założyć, że opisy chwil *T1* i *T2* są prawidłowe. 

### Wyjście Standardowe 

Wyjście zawiera w kolejnych D wierszach pojedyncze liczby całkowite będące rozwiązaniem dla kolejnych testów, 
tzn. liczbę dób mieszczących się pomiędzy danymi chwilami *T1* i *T2*.

### Przykład dla danych wejściowych:
```
5

1997 12 31 0 0 0 

1998 1 1 0 0 0 

1997 12 31 23 59 59

1998 12 31 23 59 59

1997 12 31 23 59 59

1998 1 1 23 59 58

2000 2 20 0 0 0 

2000 3 20 23 59 59 

2000 2 29 0 0 0 2

000 3 1 0 0 0 
```

Prawidłowy wynik to:

```
1

365

0

29

1
```
