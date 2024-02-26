# Wie execution funktionieren soll

Atari pdf seite 43

## Wichtig 
die ungenutzte variable aufräumen nach der erstellung einer funktion

## Generelle idee

wir werden zwei arrays haben, welche maximal 60 werte halten können jeweils, dabei könnten diese wahrscheinlich sogar kleiner sein und dieser Wert ist aktuell abiträr gewählt. 

Eins davon wird die aktuelle Funktionen speichern das andere die variabeln auf welchen wir operieren.

wir werden einen Int haben, welche bei bei der Variable welcher beim sortieren hilft des variabeln arrays, indem.

Dabei wird der Executor lediglich die aktuelle Zeile betrachten.

desweiterem wird er die nächste Zeile Zurückgeben und nichts anderes, Da an sich Alle Variabeln in dem normalen Stack bleiben sollen, Dies wird nur der Fall sein falls wir ein GOTO in der Zeile erhalten, das wird uns dann an eine andere Stelle in dem array bringen. Also wird das einziege was bestimm was grade ausgeführt wird ein INT sein, welcher von der Funktion die ganze Zeit überschrieben wird.

Standart Verhalten soll sein, dass er bei Zeile 0 anfängt.


Dabei sollten wir nur 1 Klasse benötigen 
# Klassen design

executor.cpp