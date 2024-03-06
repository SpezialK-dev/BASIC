# Tokenazation 

eine Idee, welche ich mir aus der Atari implementation abgeschaut habe, also werden hier viele Ideen daraus stammen und entsprechen wie ich das verstanden habe was dort umgesetzt werden soll. 

## Meine Implementation 

Soll im editor passieren 

### Design Entscheidungen

Ich werde denn Typen CHAR nutzten also token zu welchem wir umwandeln. Dabei sind wie in der Atari implementation die ersten 80 chars für Sprachbefehle auch wenn wir diese wahrscheinlich noch nicht kommplett ausnutzten werden. Dafür bleiben uns dann noch 176 spaces frei für variabeln. Wobei sich das relativ leicht auch noch später zu einem int verändern lassen. 


Der Grund warum ich mich gegen einen INT entschieden habe ist, da er mir viel zu groß ist. Eine künstliche limitierung finde ich auch persönlich nicht so gut vorallem wenn wir dieses Programm später Porten wollen. Deswegen habe ich mich persönlich für CHAR entschieden, wenn ich aber später merke das er doch zu klein ist für das was ich brauch werde ich es verändern. 


Ansonsten besteht immernoch die Möglichkeit denn variabeln raum zu verkleinern, das ist aber etwas was ich wirklich ungern machen würde. 

### Translation Table design

Hier werden wir starke inspiration von der Werte Tabelle von Atari verwenden (Seite 22 in dem PDF Dokument oder 8 in Buch)

DEZ     HEX     ERKLÄRUNG

0-13    00-0D   Unused

14      OE      Floating Point Numeric Constant. The next six bytes will hold its value.

15      OF      String Constant.The next byte is the string length. A string of that length follows .

16-60   10-3C   Operators. See table starting at $A7E3 for specific operators and values.

61-84   3D-54   Functions. See table starting at $A820 for specific functions and values.

85-127  55-7F   Unused. 

128-255 80-FF   Variables.

ich werde mich für das Erste auch an diesen Plan halten, da ich es mir hilft wenn man andere code teile beachten will und keine umrechnungen stattfinden müssen und kein umdenken von denn Instruktionen in dem ATARI BASIC  

Bei mir Fangen alle Funktionen einfach bei 16 an, ich kann später noch eine Anpassung eventuell vornehmen wo es wirklich eine Trennung zwischen Operatoren und Funktionen gibt aber mommentan ist das erstmal noch nicht geplant

### Generelle Idee zum Ablauf

Hierfür wurde die Zeilennummer schon im Vorhinein aus dem Array entfernt.

1. CHAR Array wird eingegeben. 
2. Herausfiltern von denn verschiedenen Wörtern
3. Der token wird gesucht 
    3.1 wenn der Token ein LET ist wird dieser nicht reingeschrieben, sondern es wird eine Routine aufgerufen, welche einen neue variable definiert
4. Token wird in ein weiteres Array reingeschrieben, welches dann zurück gegeben wird.


##### Problematik Variabeln:

wenn eine Variable nicht bereits erstellt wurde und zu dem Stack hinzugefügt wurde, was eigentlich during runtime passieren sollte, dann hat man das problem, dass wir den Wert nicht speichern können, weil wir schlecht die Informationen so komprimieren können ohne einen datenverlust zu haben. Deswegen müssen variabeln bereits zur kompilierungszeit zu dem Stack hinzugefügt werden und erstellt werden. 

Eventuell gibt es dafür noch eine bessere Methode das zu machen diese fällt mir aber zum aktuellen Zeitpunkt nicht ein, deswegen wird das mein aktueller ablauf sein, dass wir Eine flag haben welche dafür genutzt wird wenn eine variable gefunden wurde, welche durch ein LET definiert wird. 

Wobei da, die Frage ist ob LET überhaupt dann code technische wirkung haben kann? Dies ist mommentan unwahrscheinlich, weswegen wahrscheinlich dort ein leerer funtkionspointer gesetzt werden wird. 

dabei wird, soll die Syntax zum beschreiben einer variable wie folgt sein 

```BASIC 
LET var = VALUE
```
dabei werde ich die untertrennung hier mit dem = machen und nicht mit dem leerzeichen wie bei anderen Stellen code, dafür werden aber leerzeichen rausgenommen werden müssen, und diese Teile geschortet werden.

Dafür werde ich trozdem irgendwie eine Flag benötigen. An sich sollte wärend dieses processes der variable noch kein wert zugewiesen werden, sondern es bei einem Void pointer belassen sein, das würde aber bedeuten wir müssen die festen werte woanders speichern? 

#### kleiner exkurs zur Spaces in code

An Sich wäre es möglich zu sagen wir können spaces Ignorieren, aber das würde eine Menge an performance essen. Also zumindestens die implementation welche mir einfällt. 

Diese wäre man hat einen [sub string search algorithmus](https://en.wikipedia.org/wiki/String-searching_algorithm) drüber laufen, das Problem ist, das müsste man machen für alle 80 Variabel namen machen. Dies stelle ich mir als sehr unfunktional vor. Desweiterem erstell das das Folgende Problem, dass Bestimmte namen nicht mehr möglich sind. 

Als Beispiel 

> XANDZ würde immer als AND erkannt werden, dies denke ich mal könnte variabel namen probleme geben. 

Mein Aktueller ansatz besteht daraus bei spaces zu trennen und dann immer die wörter/ elemente zwischen spaces zu klassifizieren, dies sollte Deutlich weniger Probleme erstellen im Endefekt. 

dadurch kann ich einen deutlich effizienteres verfahren nutzten im elemente zu finden. Undzwar kann ich einfach ein Suchverfahren in einer Sortierten Liste anwenden. Da Mein plan ist, alle Elemente sowohl bei den Variabeln als auch bei Funktionsnamen alphabetisch sortier zu haben, damit man durch sie sehr effizient suchen kann. Dies sollte das Zuordnen relativ schnell machen, wobei ich auch eventuell noch andere Sachen ausprobieren werde. 


### Verantwortliche Klassen



### Tokenizer.cpp

search_through_funktions und search_through_variables sollen 999 zurückgeben wenn nichts gefunden wurde. Da diese Zahl in der Aktuellen umsetztung nie erreicht werden kann.