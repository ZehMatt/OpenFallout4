# OpenFallout4
This project targets to fix some of the things that are wrong in Fallout 4, it may never come to full rewrite but I'll leave that to the community.

# Current Goals
- Fix variable framerate rendering to support more than 60hz without the game going crazy.

# How does it work.
This project hooks all functions that are rewritten in the C++ project, this will be compiled to a dll and then injected with the Fallout 4 executable.
NOTE: Fallout 4 is wrapped with the Steam DRM wrapper, there are ways to remove it but due to legal reasons I will not go any further here.

# Compiling
Its currently a simple VS 2017 project, you don't need anything.
