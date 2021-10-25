# Arduino

Configurer le projet en ajoutant le fichier suivant dans <b>./include/conf.h</b>:

```c
#ifndef CONF
#define CONF

const char *ssid = "";
const char *password = "";

const char serverUrl[] = "";
const unsigned short int port = 3000;

#endif
```
