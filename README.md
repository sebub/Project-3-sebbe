# Project 3 : Superliga Statestik
- Programmet afleveres: 15.11.2022 kl. 21.00
- Aflevering: Sidste commit inden deadline der er pushet til Github tæller

# Beskrivelse
Denne opgave er baseret på en fil med resultaterne fra de første 22 runder af den danske superliga fra 2020-2021. 
Navnet på din inputfil skal være [kampe-2020-2021.txt](src/kampe-2020-2021.txt). 
Hver linje i filen er et kampresultat, eksempelvis

```
Fre     11/09 19.00     SDR - FCM     2 - 0     2210
```

Denne linje betyder at SDR (Sønderjyske) har spillet på hjemmebane mod FCM (FC Midtjylland) fredag 11. september kl. 19.00, kampen blev overværet af 2210 tilskuere, SDR scorede to mål og FCM scorede ikke i kampen.

I opgaven skal samtlige kampe indlæses i et array af structs (kamp-arrayet). Hvis du ønsker det kan du antage at der netop er 132 kampe i turneringen. 
Det benyttede struct skal opbevare oplysninger om kampens ugedag, dato (uden årstal), klokkeslæt, de to hold, kampens resultat og tilskuertal.

Opgaven går nu ud på at gennemløbe alle kampresultater med henblik på at lave et array af hold (hold-arrayet), hvor et hold er en struct. 
Hold-structen skal indeholde holdnavn, point, antal mål scoret af holdet og antal mål scoret mod holdet. 
Hvis du ønsker det kan du antage at der netop er 12 hold som spiller i turneringen. 
Hold-arrayet kan opfattes som et associativt array, der associererer holdnavnet med et hold-struct, og derfor kan dele af [opgaven om associative arrays](http://people.cs.aau.dk/~normark/impr-c/arrays-opgaver-slide-exercise-7.html) bruges i denne opgave. 
Hvis du ønsker det kan du placere holdene på faste, forudprogrammerede pladser i hold-arrayet.

Hold-arrayet skal nu sorteres, så vi kan finde stillingen i turneringen efter 22 runder. 
I denne opgave sorteres primært efter point og sekundært efter målforskel. 
Målforskellen er antal mål scoret af holdet minus antal mål scoret mod holdet. 
En vundet kamp giver 3 point, en uafgjort kamp giver 1 point, og en tabt kamp giver ingen point. 
Udskriv stillingen af turneringen på standard output med én linje per hold i følgende format:

```
Holdnavn Point Mål-af-hold Mål-mod-hold
```

Gør dig umage med at udskrive stillingen pænt, med fire lige brede søjler der er indrykket på en naturlig og overskuelig måde.

Du kan se stillingen efter grundspillet i 2020-2021 på [denne oversigt fra DBU](https://www.dbu.dk/resultater/pulje/334856).
