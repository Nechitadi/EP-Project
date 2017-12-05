# Proiect Echipamente Programabile
### Adrian Nechita

## Afisarea pe un display LCD datele citite de la senzorul de temperatura si umiditate relativa DHT22
 
Se creeaza un proiect nou in PSoC Designer.
La User Modules -> Misc Digital -> LCD -> place.
La source files avem nevoie de doua fisiere ".c": main.c si dht22.c.
Dht22.c contine functiile care calculeaza temperatura si umiditatea 
relativa din datele pe care le comunica senzorul si returneaza valorile.

In fisierul main.c, in functia main de tip void declaram doua variabile, 
temp si word pe care le initializam cu 0.
Intr-o bucla while(1) care executa comenzile atata timp cat device-ul e 
pornit introducem functiile care citesc si afiseaza temperatura si 
umiditatea relativa.
Atribuim variabilei temp valoarea temperaturii care este returnata de 
catre functia DHT22_CalculateTemp().
Cu ajutorul comenzii LCD_Position(0, 0) precizam pozitia de pe LCD unde 
dorim afisarea.
Comanda LCD_PrCString(); afiseaza un sir de caractere introdus.
LCD_WriteData afiseaza un singur caracter in cod ASCII.
Valoarea temperaturii o convertim in baza 10.
Apoi afisam umiditatea relativa pe randul urmator prin pasi similari cu 
cei pentru afisarea temperaturii.
Bucla for de la sfarsitul functiei are rolul de a crea un delay intre doua afisari consecutive
(intarziere).