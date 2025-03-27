
// ****************************************************************************
// *                                                                          *
// * Aufgabe:                                                                 *
// *                                                                          *
// * -> Schreib ein Programm mit folgenden Eigenschaften:                     *
// *    Es gibt zwei Taster (TASTER1, TASTER2), zwei LEDs (LED1, LED2) und    *
// *    ein Potentiometer. Taster1 schaltet einen digitalen Blinker auf die   *
// *    beiden LEDs, Taster2 schaltet einen analogen Blinker auf die beiden   *
// *    LEDs. Die Geschwindigkeit des Blinkers soll mit dem Poti zwischen     *
// *    50ms und 1000ms eingestellt werden können. Ein langer Tastendruck     *
// *    auf einen der beiden Taster toggelt die Blinkfunktion ein/aus.        *
// *                                                                          *
// * -> Suche dir ein/zwei Mitarbeiter und forke dieses Projekt               *
// * -> Teile die Arbeit auf die Mitarbeiter so auf, dass ein fast-forward-   *
// *    merge ermöglicht wird.                                                *
// * -> Fülle die bestehenden Header-Dateien und erzeuge die entsprechenden   *
// *    Implementierungen (cpp-Dateien). Verwende ausschließlich Klassen!     *
// *                                                                          *
// * -> Erstelle einen pull-request                                           *
// *                                                                          *
// *                                                                          *
// ****************************************************************************

#include <Arduino.h>
#include "digitalblinker.h"
#include "analogblinker.h"
#include "helper.h"

#define LED1 6    // Low-side switch (leuchtet mit LOW)
#define LED2 3    // Low-side switch (leuchtet mit LOW)
#define TASTER1 4 // LOW wenn gedrückt
#define TASTER2 5 // LOW wenn gedrückt
#define POT1 A7
#define DB_ZEIT 50
#define BLINKTIME 1000
#define POL_TIME 50

blinker digitalblinker1;
analogblinker analogblinker1;

void setup()
{
    Serial.begin(115200); // Baud rate
    Serial.println("..Start..\n");
    pinMode(LED1, OUTPUT);
    pinMode(LED2, OUTPUT);
    pinMode(TASTER1, INPUT_PULLUP);
    pinMode(TASTER2, INPUT_PULLUP);
    pinMode(POT1, INPUT);
    db_taster1.init(TASTER1, DB_ZEIT, false);
    db_taster2.init(TASTER2, DB_ZEIT, false);
    fl_taster1.init(&db_taster1.out);
    fl_taster2.init(&db_taster2.out);
    analogblinker1.init(LED1,LED2,BLINKTIME,POL_TIME,false, false);
    digitalblinker1.init(LED1, true, LED2 , true, BLINKTIME, false);
}

void loop()
{
    digitalblinker1.poll();
    analogblinker1.poll();
    db_taster1.poll();
    db_taster2.poll();
    fl_taster1.poll();
    fl_taster2.poll();

    if (fl_taster1.pos)
    {
        digitalblinker1.poll();
    }
    if (fl_taster2.pos)
    {
        analogblinker1.poll();
    }
}