#include "Arduino.h"
#include "helper.h"

void db::init(uint8_t _taster, uint8_t _db_zeit, bool _inv)
{
    taster = _taster;
    db_zeit = _db_zeit;
    inv = _inv;
}

bool db::poll()
{
    in = digitalRead(taster);
    in = inv ? !in : in; // ternary
    bool out = vorher;

    if (millis() - last > db_zeit)
    {
        if (in != vorher)
        {

            out = vorher; // output
        }
        else
        {
            out = in;
        }
        last = millis(); // last wird auf den aktuellen zeitpunkt gesetzt
        vorher = in;
    }
}

void flanke::init(bool *_input)
{
    in = *input;
}

bool flanke::poll()
{
    pos = false;
    if (in && !vorher)
        pos = true;

    neg = false;
    if (!in && vorher)
        out = true;

    vorher = in;
}