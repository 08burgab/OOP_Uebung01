#ifndef HELPER_H
#define HELPER_H

#include <Arduino.h>

class db
{
public:
    void init(uint8_t _taster, uint8_t _db_zeit, bool _inv);
    bool poll();
    bool vorher, out, in, inv = LOW; 

private:
    unsigned long last = 0;         
    uint8_t taster = 0;             
    uint8_t db_zeit = 0;            
};
db db_taster1;
db db_taster2;

struct flanke
{
public:
    void init(bool *_input);
    bool poll();
    bool vorher, out, in, pos, neg = LOW; 

private:
    bool *input;                          
};
flanke fl_taster1;
flanke fl_taster2;

// GLOBALE VARIABLEN
unsigned long last = 0;
bool state = false;

#endif