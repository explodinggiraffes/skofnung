==== External Dependency Versions ====

Versions of the dependencies in Skofnung's "extern" directory:

Ogre 13.4.4

==== Project Properties ====

Changes made to the Skofnung Visual Studio 2022 project:

+ Configuration Properties
  + General
    - C++ Language Standard: ISO C++ Standard (/std:c++20)
    + VC++ Directories
      - Include Directories
        ..\extern\ogre\include\OGRE\RTShaderSystem
        ..\extern\ogre\include\OGRE\Bites
        ..\extern\ogre\include\OGRE
      - Reference Directories
        ..\extern\ogre\bin
      - Library Directories
        ..\extern\ogre\lib        

+ Linker
  + Input
    - Additional Dependencies:
      OgreBites.lib
      OgreMain.lib
      OgreRTShaderSystem.lib

+ Build Events
  + Pre-Build Event:
    xcopy /y /d "..\extern\ogre\bin\*.dll" "$(OutDir)"
  + Post-Build Event:
    xcopy /y /d "..\extern\ogre\bin\*.cfg" "$(OutDir)"
    xcopy /y /d /s /i "..\extern\ogre\Media" "$(OutDir)\..\Media"
