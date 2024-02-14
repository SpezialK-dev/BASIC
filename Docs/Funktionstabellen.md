# Funktionstabel

hier werde ich sowohl Statment und Operatoren tabels beschreiben 

Ich denke ich werde eine classe dafür schreiben, welche eine Sowohl für den Statment table als auch den Operator tabel gelten soll, wobei ich mir noch nicht sicher bin ob ich 2 Verschiedene instancen davon erstellen werde, oder ob es eine werden soll wo einfach nur basierend index entschioeden wird. 

## Idee der Implementierung

ich werde wieder einen custom datentyp denke ich mal implementieren, dieser wird einen funtkionspointer halten, sowie ein char array mit den typen, welche benötigt werden, sodass man sie übergeben kann.
für das einzelne Aufrufen werde ich überladung nutzten müssen von Konstruktoren, wobei ich mir da noch nicht sicher bin wie ich es machen werde, eventuell eine generische Funtkion welche denn pointer sowie die werte übergeben bekommt. oder ich mache es so wie in Haskall wo nur ein wert übergeben werden kann und baue die irgend was mit Pointer magie. 


Das heißt wir werden 3 klassen haben 
1. funktionstable.cpp
2. funk_var.cpp
3. funktions_dic.cpp

### 1. funktionstable.cpp
Hier werden die Funktionen gespeichert. dabei muss es eine Funktion geben welche die Tabelle anhand des namen durchsucht, dabei ist meine erste idee es dabei einfach relativ simpel zu durchsuchen.  
Nach einer kleinen Anpassung soll es jetzt hier 2 Arrays geben eins welches funk_var speichert und eins was die funktionen selbst speichert, dabei ist der index der selbe. Dies soll es einfacher machen auf die Funktionen zuzugreifen. auch wenn es leider die array zugriffe an sich erhöht. 

### 2. funk_var.cpp
Die klasse welche in der Funktionstabelle gespeichert wird. Objekte dieser Klasse speichern einen Pointer auf die Funktion, denn namen, der Token ist der Index, und es speichert auch ein array mit dem Typensignatur. Wobei ich hier eventuell ein limit einstellen werde an wie viele Variabeln man übergeben kann.
Es muss auch denn Return typen speichern.


### 3. funktions_dic.cpp
hier werden die ganzen Funktionen selbst definiert. Dies mache ich damit es übersichtlicher bleibt und man leichter erkennt was hilfsfunktion allein für Funktionen der Sprache selbst sind.

# Was ist der Statment table ?

Der Statment table ist die klasse, welche keine dynamischen veränderungen durchlaufen wird. 
der Statment table ist für für die einzelne funktionen der Sprache gedacht 

Wobei ich diesen eventuell vergrößern werde im vergliech zu Atari BASIC. unmd den Operator table verkleinern werde. 
Weil meiner meinung nach es nicht genug Platz für funktionen gibt und zu viel für Operatoren. 

# Was ist der Operator table.
Er soll die Operatoren wie "+,-,*./,..." implementieren und darstellen, wobei ich hier eventuell von der Atari aufteilung abweiche, weil meiner Meinung nach
dort zu viel platz für Operatoren verwendet wird und zu wenige für Statments exesiteren. 