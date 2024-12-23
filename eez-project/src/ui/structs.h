#ifndef EEZ_LVGL_UI_STRUCTS_H
#define EEZ_LVGL_UI_STRUCTS_H

#include "eez-flow.h"


#if defined(EEZ_FOR_LVGL)

#include <stdint.h>
#include <stdbool.h>

#include "vars.h"

using namespace eez;

enum FlowStructures {
    FLOW_STRUCTURE_USER = 16384,
    FLOW_STRUCTURE_ZONE = 16385
};

enum FlowArrayOfStructures {
    FLOW_ARRAY_OF_STRUCTURE_USER = 81920,
    FLOW_ARRAY_OF_STRUCTURE_ZONE = 81921
};

enum UserFlowStructureFields {
    FLOW_STRUCTURE_USER_FIELD_NAME = 0,
    FLOW_STRUCTURE_USER_NUM_FIELDS
};

enum ZoneFlowStructureFields {
    FLOW_STRUCTURE_ZONE_FIELD_NAME = 0,
    FLOW_STRUCTURE_ZONE_FIELD_TEMPERATURE = 1,
    FLOW_STRUCTURE_ZONE_FIELD_POWER = 2,
    FLOW_STRUCTURE_ZONE_FIELD_LOCKED = 3,
    FLOW_STRUCTURE_ZONE_FIELD_LIGHTING_PERCENT = 4,
    FLOW_STRUCTURE_ZONE_FIELD_HEATING_SAVED = 5,
    FLOW_STRUCTURE_ZONE_FIELD_LIGHTING_SAVED = 6,
    FLOW_STRUCTURE_ZONE_NUM_FIELDS
};

struct UserValue {
    Value value;
    
    UserValue() {
        value = Value::makeArrayRef(FLOW_STRUCTURE_USER_NUM_FIELDS, FLOW_STRUCTURE_USER, 0);
    }
    
    UserValue(Value value) : value(value) {}
    
    operator Value() const { return value; }
    
    operator bool() const { return value.isArray(); }
    
    const char *name() {
        return value.getArray()->values[FLOW_STRUCTURE_USER_FIELD_NAME].getString();
    }
    void name(const char *name) {
        value.getArray()->values[FLOW_STRUCTURE_USER_FIELD_NAME] = StringValue(name);
    }
};

typedef ArrayOf<UserValue, FLOW_ARRAY_OF_STRUCTURE_USER> ArrayOfUserValue;
struct ZoneValue {
    Value value;
    
    ZoneValue() {
        value = Value::makeArrayRef(FLOW_STRUCTURE_ZONE_NUM_FIELDS, FLOW_STRUCTURE_ZONE, 0);
    }
    
    ZoneValue(Value value) : value(value) {}
    
    operator Value() const { return value; }
    
    operator bool() const { return value.isArray(); }
    
    const char *name() {
        return value.getArray()->values[FLOW_STRUCTURE_ZONE_FIELD_NAME].getString();
    }
    void name(const char *name) {
        value.getArray()->values[FLOW_STRUCTURE_ZONE_FIELD_NAME] = StringValue(name);
    }
    
    float temperature() {
        return value.getArray()->values[FLOW_STRUCTURE_ZONE_FIELD_TEMPERATURE].getFloat();
    }
    void temperature(float temperature) {
        value.getArray()->values[FLOW_STRUCTURE_ZONE_FIELD_TEMPERATURE] = FloatValue(temperature);
    }
    
    float power() {
        return value.getArray()->values[FLOW_STRUCTURE_ZONE_FIELD_POWER].getFloat();
    }
    void power(float power) {
        value.getArray()->values[FLOW_STRUCTURE_ZONE_FIELD_POWER] = FloatValue(power);
    }
    
    bool locked() {
        return value.getArray()->values[FLOW_STRUCTURE_ZONE_FIELD_LOCKED].getBoolean();
    }
    void locked(bool locked) {
        value.getArray()->values[FLOW_STRUCTURE_ZONE_FIELD_LOCKED] = BooleanValue(locked);
    }
    
    float lighting_percent() {
        return value.getArray()->values[FLOW_STRUCTURE_ZONE_FIELD_LIGHTING_PERCENT].getFloat();
    }
    void lighting_percent(float lighting_percent) {
        value.getArray()->values[FLOW_STRUCTURE_ZONE_FIELD_LIGHTING_PERCENT] = FloatValue(lighting_percent);
    }
    
    bool heating_saved() {
        return value.getArray()->values[FLOW_STRUCTURE_ZONE_FIELD_HEATING_SAVED].getBoolean();
    }
    void heating_saved(bool heating_saved) {
        value.getArray()->values[FLOW_STRUCTURE_ZONE_FIELD_HEATING_SAVED] = BooleanValue(heating_saved);
    }
    
    bool lighting_saved() {
        return value.getArray()->values[FLOW_STRUCTURE_ZONE_FIELD_LIGHTING_SAVED].getBoolean();
    }
    void lighting_saved(bool lighting_saved) {
        value.getArray()->values[FLOW_STRUCTURE_ZONE_FIELD_LIGHTING_SAVED] = BooleanValue(lighting_saved);
    }
};

typedef ArrayOf<ZoneValue, FLOW_ARRAY_OF_STRUCTURE_ZONE> ArrayOfZoneValue;


#endif

#endif /*EEZ_LVGL_UI_STRUCTS_H*/
