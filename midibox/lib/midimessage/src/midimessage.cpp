#include "midimessage.h"
#include <Arduino.h>

void MidiMessage::Print(Message msg)
{
    Serial.println(F("CHANNEL"));
    Serial.println(msg.info.infos.channel);
    switch (msg.info.infos.id)
    {
    case MidiMessage::MessageType::PROGRAM_CHANGE:
        Serial.println(F("PROGRAM_CHANGE"));
        Serial.println(msg.data1.infos.value);
        break;
    case MidiMessage::MessageType::CHANNEL_AFTERTOUCH:
        Serial.println(F("CHANNEL_AFTERTOUCH"));
        Serial.println(msg.data1.infos.value);
        break;
    case MidiMessage::MessageType::SYSTEM:
        Serial.println(F("SYSTEM"));
        break;
    case MidiMessage::MessageType::NOTE_OFF:
        Serial.println(F("NOTE_OFF"));
        Serial.println(msg.data1.infos.value);
        break;
    case MidiMessage::MessageType::NOTE_ON:
        Serial.println(F("NOTE_ON"));
        Serial.println(msg.data1.infos.value);
        break;
    case MidiMessage::MessageType::CONTROL_CHANGE:
        Serial.println(F("CONTROL_CHANGE"));
        Serial.println(F("number"));
        Serial.println(msg.data1.infos.value);
        Serial.println(F("value"));
        Serial.println(msg.data2.infos.value);
        break;
    case MidiMessage::MessageType::POLY_AFTERTOUCH:
        Serial.println(F("POLY_AFTERTOUCH"));
        Serial.println(F("number"));
        Serial.println(msg.data1.infos.value);
        Serial.println(F("value"));
        Serial.println(msg.data2.infos.value);
        break;
    case MidiMessage::MessageType::PITCH_BEND:
        Serial.println(F("PITCH_BEND"));
        Serial.println(F("low"));
        Serial.println(msg.data1.infos.value);
        Serial.println(F("high"));
        Serial.println(msg.data2.infos.value);
        break;
    }
}

int MidiMessage::MessageLength(int message_type)
{
    switch (message_type)
    {
    case MidiMessage::MessageType::PROGRAM_CHANGE:
    case MidiMessage::MessageType::CHANNEL_AFTERTOUCH:
    case MidiMessage::MessageType::SYSTEM:
        return 2;

    case MidiMessage::MessageType::NOTE_OFF:
    case MidiMessage::MessageType::NOTE_ON:
    case MidiMessage::MessageType::CONTROL_CHANGE:
    case MidiMessage::MessageType::POLY_AFTERTOUCH:
    case MidiMessage::MessageType::PITCH_BEND:
        return 3;
    default:
        return 0;
    }
}
