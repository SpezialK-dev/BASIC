# Tokenazation 

eine Idee, welche ich mir aus der Atari implementation abgeschaut habe, also werden hier viele Ideen daraus stammen und entsprechen wie ich das verstanden habe was dort umgesetzt werden soll. 

## Meine Implementation 

### Design Entscheidungen

Ich werde denn Typen CHAR nutzten also token zu welchem wir umwandeln. Dabei sind wie in der Atari implementation die ersten 80 chars für Sprachbefehle auch wenn wir diese wahrscheinlich noch nicht kommplett ausnutzten werden. Dafür bleiben uns dann noch 176 spaces frei für variabeln. Wobei sich das relativ leicht auch noch später zu einem int verändern lassen. 


Der Grund warum ich mich gegen einen INT entschieden habe ist, da er mir viel zu groß ist. Eine künstliche limitierung finde ich auch persönlich nicht so gut vorallem wenn wir dieses Programm später Porten wollen. Deswegen habe ich mich persönlich für CHAR entschieden, wenn ich aber später merke das er doch zu klein ist für das was ich brauch werde ich es verändern. 


Ansonsten besteht immernoch die Möglichkeit denn variabeln raum zu verkleinern, das ist aber etwas was ich wirklich ungern machen würde. 

### Generelle Idee zum Ablauf

Hierfür wurde die Zeilennummer schon im Vorhinein aus dem Array entfernt.

1. CHAR Array wird eingegeben. 
2. Herausfiltern von denn verschiedenen Wörtern




#### kleiner exkurs zur Spaces in code

An Sich wäre es möglich zu sagen wir können spaces Ignorieren, aber das würde eine Menge an performance essen. Also zumindestens die implementation welche mir einfällt. 

Diese wäre man hat einen [sub string search algorithmus](https://en.wikipedia.org/wiki/String-searching_algorithm) drüber laufen, das Problem ist, das müsste man machen für alle 80 Variabel namen machen. Dies stelle ich mir als sehr unfunktional vor. Desweiterem erstell das das Folgende Problem, dass Bestimmte namen nicht mehr möglich sind. 

Als Beispiel 

> XANDZ würde immer als AND erkannt werden, dies denke ich mal könnte variabel namen probleme geben. 

Mein AKtueller ansatz besteht daraus bei spaces zu trennen und dann immer die wörter/ elemente zwischen spaces zu classifizieren, dies sollte Deutlich weniger Probleme erstellen im endefekt. 