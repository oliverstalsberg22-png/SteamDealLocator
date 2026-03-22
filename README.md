# SteamDiscountFinder

C++ console app that pulls data from the CheapShark API using CPR.
Features: 

## Features
- Browse current Steam game deals
- Filter deals by price, deal rating, and percent off
- View sale price vs normal price

## Dependencies
- C++17 or later
- [CPR](https://github.com/libcpr/cpr)
- [nlohmann-json](https://github.com/nlohmann/json)
- [vcpkg](https://github.com/microsoft/vcpkg)
- [CheapShark API](https://apidocs.cheapshark.com/)

## Setup
1. Open Visual Studio
2. Click "Clone a repository" on the start screen
3. Paste the repository URL and click Clone
4. Navigate to the project folder and install dependencies via terminal
```
cd SteamDiscountFinder
vcpkg install
```
5. Set build configuration to Release at the top of Visual Studio
6. Build the project

## Extra
After building, copy the following files from 
vcpkg_installed\x64-windows\bin\ into your x64\Release\ folder:
- libcurl.dll
- zlib1.dll

## Usage
- Run the application and filter through steam sales using menu
