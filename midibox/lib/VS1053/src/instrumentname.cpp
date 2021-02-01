#include <Arduino.h>


// Piano Family:
const char Instr000[] PROGMEM = "Acoustic Grand Piano";
const char Instr001[] PROGMEM = "Bright Acoustic Piano";
const char Instr002[] PROGMEM = "Electric Grand Piano";
const char Instr003[] PROGMEM = "Honky-tonk Piano";
const char Instr004[] PROGMEM = "Electric Piano 1";
const char Instr005[] PROGMEM = "Electric Piano 2";
const char Instr006[] PROGMEM = "Harpsichord";
const char Instr007[] PROGMEM = "Clavinet";
// Chromatic Percussion Family:
const char Instr008[] PROGMEM = "Celesta";
const char Instr009[] PROGMEM = "Glockenspiel";
const char Instr010[] PROGMEM = "Music Box";
const char Instr011[] PROGMEM = "Vibraphone";
const char Instr012[] PROGMEM = "Marimba";
const char Instr013[] PROGMEM = "Xylophone";
const char Instr014[] PROGMEM = "Tubular Bells";
const char Instr015[] PROGMEM = "Dulcimer";
// Organ Family:
const char Instr016[] PROGMEM = "Drawbar Organ";
const char Instr017[] PROGMEM = "Percussive Organ";
const char Instr018[] PROGMEM = "Rock Organ";
const char Instr019[] PROGMEM = "Church Organ";
const char Instr020[] PROGMEM = "Reed Organ";
const char Instr021[] PROGMEM = "Accordion";
const char Instr022[] PROGMEM = "Harmonica";
const char Instr023[] PROGMEM = "Tango Accordion";
// Guitar Family:
const char Instr024[] PROGMEM = "Acoustic Guitar (nylon)";
const char Instr025[] PROGMEM = "Acoustic Guitar (steel)";
const char Instr026[] PROGMEM = "Electric Guitar (jazz)";
const char Instr027[] PROGMEM = "Electric Guitar (clean)";
const char Instr028[] PROGMEM = "Electric Guitar (muted)";
const char Instr029[] PROGMEM = "Overdriven Guitar";
const char Instr030[] PROGMEM = "Distortion Guitar";
const char Instr031[] PROGMEM = "Guitar harmonics";
// Bass Family:
const char Instr032[] PROGMEM = "Acoustic Bass";
const char Instr033[] PROGMEM = "Electric Bass (finger)";
const char Instr034[] PROGMEM = "Electric Bass (pick)";
const char Instr035[] PROGMEM = "Fretless Bass";
const char Instr036[] PROGMEM = "Slap Bass 1";
const char Instr037[] PROGMEM = "Slap Bass 2";
const char Instr038[] PROGMEM = "Synth Bass 1";
const char Instr039[] PROGMEM = "Synth Bass 2";
// Strings Family:
const char Instr040[] PROGMEM = "Violin";
const char Instr041[] PROGMEM = "Viola";
const char Instr042[] PROGMEM = "Cello";
const char Instr043[] PROGMEM = "Contrabass";
const char Instr044[] PROGMEM = "Tremolo Strings";
const char Instr045[] PROGMEM = "Pizzicato Strings";
const char Instr046[] PROGMEM = "Orchestral Harp";
const char Instr047[] PROGMEM = "Timpani";
// Ensemble Family:
const char Instr048[] PROGMEM = "String Ensemble 1";
const char Instr049[] PROGMEM = "String Ensemble 2";
const char Instr050[] PROGMEM = "Synth Strings 1";
const char Instr051[] PROGMEM = "Synth Strings 2";
const char Instr052[] PROGMEM = "Choir Aahs";
const char Instr053[] PROGMEM = "Voice Oohs";
const char Instr054[] PROGMEM = "Synth Voice";
const char Instr055[] PROGMEM = "Orchestra Hit";
// Brass Family:
const char Instr056[] PROGMEM = "Trumpet";
const char Instr057[] PROGMEM = "Trombone";
const char Instr058[] PROGMEM = "Tuba";
const char Instr059[] PROGMEM = "Muted Trumpet";
const char Instr060[] PROGMEM = "French Horn";
const char Instr061[] PROGMEM = "Brass Section";
const char Instr062[] PROGMEM = "Synth Brass 1";
const char Instr063[] PROGMEM = "Synth Brass 2";
// Reed Family:
const char Instr064[] PROGMEM = "Soprano Sax";
const char Instr065[] PROGMEM = "Alto Sax";
const char Instr066[] PROGMEM = "Tenor Sax";
const char Instr067[] PROGMEM = "Baritone Sax";
const char Instr068[] PROGMEM = "Oboe";
const char Instr069[] PROGMEM = "English Horn";
const char Instr070[] PROGMEM = "Bassoon";
const char Instr071[] PROGMEM = "Clarinet";
// Pipe Family:
const char Instr072[] PROGMEM = "Piccolo";
const char Instr073[] PROGMEM = "Flute";
const char Instr074[] PROGMEM = "Recorder";
const char Instr075[] PROGMEM = "Pan Flute";
const char Instr076[] PROGMEM = "Blown Bottle";
const char Instr077[] PROGMEM = "Shakuhachi";
const char Instr078[] PROGMEM = "Whistle";
const char Instr079[] PROGMEM = "Ocarina";
// Synth Lead Family:
const char Instr080[] PROGMEM = "Lead 1 (square)";
const char Instr081[] PROGMEM = "Lead 2 (sawtooth)";
const char Instr082[] PROGMEM = "Lead 3 (calliope)";
const char Instr083[] PROGMEM = "Lead 4 (chiff)";
const char Instr084[] PROGMEM = "Lead 5 (charang)";
const char Instr085[] PROGMEM = "Lead 6 (voice)";
const char Instr086[] PROGMEM = "Lead 7 (fifths)";
const char Instr087[] PROGMEM = "Lead 8 (bass)";
// Synth Pad Family:
const char Instr088[] PROGMEM = "Pad 1 (new age)";
const char Instr089[] PROGMEM = "Pad 2 (warm)";
const char Instr090[] PROGMEM = "Pad 3 (polysynth)";
const char Instr091[] PROGMEM = "Pad 4 (choir)";
const char Instr092[] PROGMEM = "Pad 5 (bowed)";
const char Instr093[] PROGMEM = "Pad 6 (metallic)";
const char Instr094[] PROGMEM = "Pad 7 (halo)";
const char Instr095[] PROGMEM = "Pad 8 (sweep)";
// Synth Effects Family:
const char Instr096[] PROGMEM = "FX 1 (rain)";
const char Instr097[] PROGMEM = "FX 2 (soundtrack)";
const char Instr098[] PROGMEM = "FX 3 (crystal)";
const char Instr099[] PROGMEM = "FX 4 (atmosphere)";
const char Instr100[] PROGMEM = "FX 5 (brightness)";
const char Instr101[] PROGMEM = "FX 6 (goblins)";
const char Instr102[] PROGMEM = "FX 7 (echoes)";
const char Instr103[] PROGMEM = "FX 8 (scifi)";
// Ethnic Family:
const char Instr104[] PROGMEM = "Sitar";
const char Instr105[] PROGMEM = "Banjo";
const char Instr106[] PROGMEM = "Shamisen";
const char Instr107[] PROGMEM = "Koto";
const char Instr108[] PROGMEM = "Kalimba";
const char Instr109[] PROGMEM = "Bag pipe";
const char Instr110[] PROGMEM = "Fiddle";
const char Instr111[] PROGMEM = "Shanai";
// Percussive Family:
const char Instr112[] PROGMEM = "Tinkle Bell";
const char Instr113[] PROGMEM = "Agogo";
const char Instr114[] PROGMEM = "Steel Drums";
const char Instr115[] PROGMEM = "Woodblock";
const char Instr116[] PROGMEM = "Taiko Drum";
const char Instr117[] PROGMEM = "Melodic Tom";
const char Instr118[] PROGMEM = "Synth Drum";
const char Instr119[] PROGMEM = "Reverse Cymbal";
// Sound Effects Family:
const char Instr120[] PROGMEM = "Guitar Fret Noise";
const char Instr121[] PROGMEM = "Breath Noise";
const char Instr122[] PROGMEM = "Seashore";
const char Instr123[] PROGMEM = "Bird Tweet";
const char Instr124[] PROGMEM = "Telephone Ring";
const char Instr125[] PROGMEM = "Helicopter";
const char Instr126[] PROGMEM = "Applause";
const char Instr127[] PROGMEM = "Gunshot";

const char* const INSTRUMENT_NAMES[] PROGMEM = 
{ Instr000, Instr001, Instr002, Instr003, Instr004, Instr005, Instr006, Instr007, Instr008, Instr009, Instr010, Instr011, Instr012, Instr013, Instr014, Instr015, 
  Instr016, Instr017, Instr018, Instr019, Instr020, Instr021, Instr022, Instr023, Instr024, Instr025, Instr026, Instr027, Instr028, Instr029, Instr030, Instr031, 
  Instr032, Instr033, Instr034, Instr035, Instr036, Instr037, Instr038, Instr039, Instr040, Instr041, Instr042, Instr043, Instr044, Instr045, Instr046, Instr047, 
  Instr048, Instr049, Instr050, Instr051, Instr052, Instr053, Instr054, Instr055, Instr056, Instr057, Instr058, Instr059, Instr060, Instr061, Instr062, Instr063, 
  Instr064, Instr065, Instr066, Instr067, Instr068, Instr069, Instr070, Instr071, Instr072, Instr073, Instr074, Instr075, Instr076, Instr077, Instr078, Instr079, 
  Instr080, Instr081, Instr082, Instr083, Instr084, Instr085, Instr086, Instr087, Instr088, Instr089, Instr090, Instr091, Instr092, Instr093, Instr094, Instr095, 
  Instr096, Instr097, Instr098, Instr099, Instr100, Instr101, Instr102, Instr103, Instr104, Instr105, Instr106, Instr107, Instr108, Instr109, Instr110, Instr111, 
  Instr112, Instr113, Instr114, Instr115, Instr116, Instr117, Instr118, Instr119, Instr120, Instr121, Instr122, Instr123, Instr124, Instr125, Instr126, Instr127,
};

const char* InstrumentName(uint8_t number)
{
    if(number > 127)
        return PSTR("UNKNOWN BANK");

    return (const char *) pgm_read_word(&INSTRUMENT_NAMES[number]);
}
