# Project Name
### Authors: Nathan Miler

## Build Directions

Version: g++ version 13.2.0, cmake version 4.0.0-rc5, Visual Studio 2022

Tool: command line cmake

Step-by-step guide:
1. Go into build directory (<code>cd build</code>) in the developer command prompt
2. Run the command <code>msbuild wumpus.sln /p:Configuration=Release</code>
3. Go into the Release directory (<code>cd Release</code>)
4. Run <code>wumpus.exe</code> or <code>./wumpus.exe</code>
   
How to enter debug mode:
- In step 2, run <code>msbuild wumpus.sln /p:Configuration=Debug</code> instead, and in step 3, go into the Debug directory (<code>cd Debug</code>)
- Typing <code>m</code> into the action prompt will show the map

## Change Log

- Did not include use of InventoryItem.h