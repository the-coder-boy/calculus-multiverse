#pragma once
#include <iostream>
#include <raylib.h>

class GraphWindow {
private:
    const char * TITLE = "Graph-kun";
    const int SCREEN_HEIGHT = 750;
    const int SCREEN_WIDTH=950;
    int FPS = 90;
    const Color background = {5, 0, 31, 255};

    bool fileLoaded = false;

public:
    void CreateWindow();
    void MainLoop();
    void ShowSQLData(char * filePath);
};