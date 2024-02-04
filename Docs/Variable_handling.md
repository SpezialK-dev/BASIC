# Variable handling

## Wie es im ATARI BASIC funktionierte
In ATARI BASIC haben wir einen Variable Name Table


## Wie ich es löse

Ich werde es auch denke ich mal so lösen, aber ich werde 


### Namenspeicher

Merkmale 

- Speicher C style Arrays ab um portabler zu sein, desweiterem sind es dann "NUR" mehrdimensionale Arrays was beim programmieren hilft.
- es gibt insgesamt 128 Variabel und die dürfen eine namenslänge von 20 Zeichen haben dabei wird der rest wegeworfen und einfach ignoriert.

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
