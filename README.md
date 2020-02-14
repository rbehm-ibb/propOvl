# propOvl
create a dat  file from SPIN DAT to be stored in upper EEPROM for overlay loading

This program take simple SPIN files containing mostly DAT sections, compiles them to binary data as would a SPIN compiler do.

It then saves these to a file to be stored in upper (or another) EEPROM for overlay loading.

Usable for large data blocks like graphics, font, etc.

## Extension

Also create a downloader to store these data into EEPROM and a overlay loader to be included into the prop pgm.

