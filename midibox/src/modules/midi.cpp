#include "midi.h"
#include <Arduino.h>

using namespace MidiMessage;

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

Message Midi::Read()
{
    Message msg;
    msg.info.data = Serial1.read();
    int messageLength = MessageLength(msg.info.infos.id);
    msg.data1.data = Serial1.read();
    if (messageLength > 2)
        msg.data2.data = Serial1.read();

    return msg;
}

