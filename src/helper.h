#ifndef HELPER_H
#define HELPER_H

#include <Arduino.h>

// Klasse für Entprellung
class db
{
public:
    void init(uint8_t _taster, uint8_t _db_zeit, bool _inv);
    bool poll();
    bool vorher = LOW, out = LOW, in = LOW, inv = LOW;

private:
    unsigned long last = 0;
    uint8_t taster = 0;
    uint8_t db_zeit = 0;
};

// Globale Instanzen der db-Klasse
db db_taster1;
db db_taster2;

// Klasse für Flankenerkennung
class flanke
{
public:
    void init(bool *input);
    bool poll();
    bool vorher = LOW, out = LOW, pos = LOW, neg = LOW;

private:
    bool *input;
};

// Globale Instanzen der flanke-Klasse
flanke fl_taster1;
flanke fl_taster2;

#endif