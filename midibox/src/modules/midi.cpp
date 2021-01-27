#include "midi.h"
#include <Arduino.h>

int MessageLength(int message_type)
{
    switch (message_type)
    {
    case Midi::MessageType::PROGRAM_CHANGE:
    case Midi::MessageType::CHANNEL_AFTERTOUCH:
    case Midi::MessageType::SYSTEM:
        return 2;

    case Midi::MessageType::NOTE_OFF:
    case Midi::MessageType::NOTE_ON:
    case Midi::MessageType::CONTROL_CHANGE:
    case Midi::MessageType::POLY_AFTERTOUCH:
    case Midi::MessageType::PITCH_BEND:
        return 3;
    default:
        return 0;
    }
}

void Midi::Init()
{
    Serial1.begin(31250);
}

bool Midi::Available()
{
    int dataAvailable = Serial1.available();

    if (!dataAvailable)
        return false;

    MessageInfo msgInfo;
    msgInfo.data = Serial1.peek();

    int messageLength = MessageLength(msgInfo.infos.id);

    return dataAvailable >= messageLength;
}

Midi::Message Midi::Read()
{
    Message msg;
    msg.info.data = Serial1.read();
    int messageLength = MessageLength(msg.info.infos.id);
    msg.data1.data = Serial1.read();
    if (messageLength > 2)
        msg.data2.data = Serial1.read();

    return msg;
}

void Midi::PrintMessage(Message msg)
{
    switch (msg.info.infos.id)
    {
    case Midi::MessageType::PROGRAM_CHANGE:
        Serial.println("PROGRAM_CHANGE");
        Serial.println(msg.data1.infos.value);
        break;
    case Midi::MessageType::CHANNEL_AFTERTOUCH:
        Serial.println("CHANNEL_AFTERTOUCH");
        Serial.println(msg.data1.infos.value);
        break;
    case Midi::MessageType::SYSTEM:
        Serial.println("SYSTEM");
        break;
    case Midi::MessageType::NOTE_OFF:
        Serial.println("NOTE_OFF");
        Serial.println(msg.data1.infos.value);
        break;
    case Midi::MessageType::NOTE_ON:
        Serial.println("NOTE_ON");
        Serial.println(msg.data1.infos.value);
        break;
    case Midi::MessageType::CONTROL_CHANGE:
        Serial.println("CONTROL_CHANGE");
        Serial.println("number");
        Serial.println(msg.data1.infos.value);
        Serial.println("value");
        Serial.println(msg.data2.infos.value);
        break;
    case Midi::MessageType::POLY_AFTERTOUCH:
        Serial.println("POLY_AFTERTOUCH");
        Serial.println("number");
        Serial.println(msg.data1.infos.value);
        Serial.println("value");
        Serial.println(msg.data2.infos.value);
        break;
    case Midi::MessageType::PITCH_BEND:
        Serial.println("PITCH_BEND");
        Serial.println("low");
        Serial.println(msg.data1.infos.value);
        Serial.println("high");
        Serial.println(msg.data2.infos.value);
        break;
    }
}
