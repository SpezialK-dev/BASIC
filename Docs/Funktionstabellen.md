# Funktionstabel

hier werde ich sowohl Statment und Operatoren tabels beschreiben 

Ich denke ich werde eine classe dafür schreiben, welche eine Sowohl für den Statment table als auch den Operator tabel gelten soll, wobei ich mir noch nicht sicher bin ob ich 2 Verschiedene instancen davon erstellen werde, oder ob es eine werden soll wo einfach nur basierend index entschioeden wird. 

## Idee der Implementierung

ich werde wieder einen custom datentyp denke ich mal implementieren, dieser wird einen funtkionspointer halten, sowie ein char array mit den typen, welche benötigt werden, sodass man sie übergeben kann.
für das einzelne Aufrufen werde ich überladung nutzten müssen von Konstruktoren, wobei ich mir da noch nicht sicher bin wie ich es machen werde, eventuell eine generische Funtkion welche denn pointer sowie die werte übergeben bekommt. oder ich mache es so wie in Haskall wo nur ein wert übergeben werden kann und baue die irgend was mit Pointer magie. 



# Was ist der Statment table ?

Der Statment table ist die klasse, welche keine dynamischen veränderungen durchlaufen wird. 
der Statment table ist für für die einzelne funktionen der Sprache gedacht 

Wobei ich diesen eventuell vergrößern werde im vergliech zu Atari BASIC. unmd den Operator table verkleinern werde. 
Weil meiner meinung nach es nicht genug Platz für funktionen gibt und zu viel für Operatoren. 

# Was ist der Operator table.
Er soll die Operatoren wie "+,-,*./,..." implementieren und darstellen, wobei ich hier eventuell von der Atari aufteilung abweiche, weil meiner Meinung nach
dort zu viel platz für Operatoren verwendet wird und zu wenige für Statments exesiteren. 