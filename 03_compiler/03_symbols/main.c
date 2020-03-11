static int _1_staticGlobal = 5;
int _1_global = 6;
extern int _1_external;

static int _2_staticGlobalUn;
int _2_globalUn;
extern int _2_externalGlobalUn;

void _start()
{
    _1_staticGlobal = 0x10;
    _1_global = 0x12;
    _1_external = 0x14;

    _2_staticGlobalUn = 0x14;
    _2_globalUn = 0x16;
    _2_externalGlobalUn = 0x18;
}