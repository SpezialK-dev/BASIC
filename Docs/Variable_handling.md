# Variable handling

## Wie es im ATARI BASIC funktionierte
In ATARI BASIC haben wir einen Variable Name Table


## Wie ich es löse

Ich werde es auch denke ich mal so lösen, aber ich werde 


### Namenspeicher

Merkmale 

- Speicher C style Arrays ab um portabler zu sein, desweiterem sind es dann "NUR" mehrdimensionale Arrays was beim programmieren hilft.
- es gibt insgesamt 128 Variabel und die dürfen eine namenslänge von 20 Zeichen haben dabei wird der rest wegeworfen und einfach ignoriert.
- wenn etwas überschrieben wurde dann hat es denn Wert 0 wenn man es als int vergleicht.
- Damit etwas als leer erkannt muss index 0 denn int wert 0 haben


### Wertespeicher
wir machen uns es wie python zu nutzten und und haben nur eine Array an pointern, Da c++ kein garbage collector hat, sollte es reichen, wenn ich variabeln erstelle auf diese einen pointer. Das erlaubt es uns selbst arrays zu speichern. 

Wir werden als alles mit VOID Zeiger initalisieren, von welchen dann später der Type geändert wird.

#### problem 
Wir wissen nicht welcher Typ es ist also erstellen wir einfach eine klasse welche nur einen pointer und einen char speicher für den Typen. 

Die klasse kann in der selben Datei gespeichert werden, da es an sich keinen unterschied machen sollte und mehr als storage solution dient


#### Wie ich es machen werde 

##### Festellen des Types 
werden wir in create new variable handeln

wir allokieren memory mit new keyword für den wert, nachdem wir denn Typen festgestellt haben. 


#### platzierung des items im array 

Für das erste werden wir einfach nur denn höchsten wert nehemen um eine variable zu finden

Zuständliche variabeln 
char last_numb = 0;


Später kann man das effizienter machen, indem man die Sache alphabetisch sortiert und somit den zugriff eventuell schneller macht

#### Type detection

klene Feinheiten. Strings können mommentan keine ints an erster Stelle enthalten!!!
also "1,2" wird nicht als string aufgefasst sondern als int!!!
Dies kann sich in der Zukunft noch ändern

Grober Ablauf Type detection
1. Festellen Nummer oder String?
2. Nummer
   2.1 Floating Point number oder nicht?

um bei zahlen umzuwandeln subtrahieren wir mit dem char '0' und geben als ausgabe typ einen int an, dann funktioniert es. Ansonstne nicht!!
##### Typenumwandlung

###### INT

Wir iterieren durch das array und multiplizieren denn vorwert mit 10 und addieren unsere aktuelle zahl hinzu egal, wie viele 0 wir davor haben es wird funtkionieren

#### Eigene Klasse für Datentypen