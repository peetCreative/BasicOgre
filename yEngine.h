//
// Created by peetcreative on 10.11.20.
//


#ifndef YENGINE_H
#define YENGINE_H

#include "OgrePrerequisites.h"
#include "Ogre.h"
#include "OgreRoot.h"
#include "Compositor/OgreCompositorManager2.h"
#include "Compositor/OgreCompositorWorkspace.h"

#include "OgreHlmsPbs.h"
#include "OgreHlmsUnlit.h"
#include "OgreHlmsManager.h"
#include "OgreHlmsPbsDatablock.h"
#include "OgreHlmsUnlitDatablock.h"

#include "OgreMesh2.h"
#include "OgreMeshManager2.h"
#include "OgreItem.h"

#include "OgreBoxEmitter.h"

#include <iostream>

class yEngine : public Ogre::FrameListener
{
public:
    yEngine();
    virtual ~yEngine();
    virtual void init();

    void startRender();

private:
    bool frameRenderingQueued(const Ogre::FrameEvent &evt);
    Ogre::SceneManager* sceneManager;
    Ogre::SceneNode* mainCameraNode;
    Ogre::SceneNode* cubeNode;
    Ogre::MeshPtr cubeMeshV2;

    Ogre::Root* mRoot;
    Ogre::HlmsPbs* mHlmsPbs;
    Ogre::HlmsUnlit* mHlmsUnlit;
};

#endif // YENGINE_H