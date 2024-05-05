#include <iostream>
#include <raylib.h>
#include "headers/GraphWindow.h"
#include "headers/GraphSQL.h"

GraphSQL graphSQL;

void GraphWindow::CreateWindow()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, TITLE);
    SetTargetFPS(FPS);

    MainLoop();
    CloseWindow();
}

void GraphWindow::MainLoop()
{
    while (!WindowShouldClose())
    {
        if (IsFileDropped())
        {
            FilePathList droppedFiles = LoadDroppedFiles();

            ShowSQLData(*droppedFiles.paths);

            UnloadDroppedFiles(droppedFiles);
        }
        BeginDrawing();
        ClearBackground(background);

        if (!fileLoaded)
        {
            DrawText("DROP YOUR CONTENT :-)", 350, 750 / 2, 20, WHITE);
        }

        EndDrawing();
    }

    graphSQL.SQLClose();
}

// get the sql data
void GraphWindow::ShowSQLData(char *filePath)
{
    graphSQL.LoadDB(filePath);
    graphSQL.GetData("expenses");
}