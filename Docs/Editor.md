# The design of the editor

Das programm soll default mäßig im Editor Modus starten, von dort an kann man dann in denn execution modus wechseln. Dabei wird der Executor eine eigene klasse sein welche vom Editor dann ausgeführt wird. 

Hierbei soll beim eingeben auch schon gleich die Tokenazation passieren, Sachen wie Syntax Error detection werden wir uns bis auf ein paar rudimäntäre dinge ersparen aus dem Zeitfaktor, sowie da sie nicht Zeitlich reinpassen werden.

## Unterteilung des Editors in verschiedene Klassen

1. tokenizer.cpp
2. editing_window.cpp

### tokenizer.cpp
beschäftig sich mit dem unwandeln in tokens, mehr nicht. 
Hierbei sollte es eine öffentliche Methode geben um Um in tokens umzuwandeln und wieder zurück. 

## Editing window
soll denn tokenizer aufrufen, ist für die eingabe verantwortlich, sowie die verarbeitung der eingabe.