#include "yEngine.h"

int main(int argc, char *argv[])
{
    yEngine* engine = new yEngine();
    engine->init();

    //start the actual Ogre Render thread
    engine->startRender();

    return 0;
}