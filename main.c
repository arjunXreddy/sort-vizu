#include <raylib.h>
#include <stdlib.h>
#include <stdio.h>

#define WIDTH 900
#define HEIGHT 600


#define COUNT 50

int numbers[COUNT];

void draw_bars()
{
    for(int i = 0; i < COUNT ; ++i){
        int value = numbers[i];
        //bar height
        int bar_height = value*HEIGHT*0.75/COUNT;
        DrawRectangle(((float)i/COUNT)*WIDTH,(HEIGHT * 0.75 - bar_height),WIDTH/COUNT - 2,bar_height + 1,WHITE);
    }
}



void inti_numbers()
{
    for(int i =0;i<COUNT;++i)
    {
        numbers[i] = i;
    }
    // Fisher Yates Shuffer
    for(int i = COUNT - 1;i>=0;i--)
    {
        int j = rand() % (COUNT + 1); //random in the range of index 

        //swap
        int temp = numbers[i];
        numbers[i] = numbers[j];
        numbers[j] = temp;
    }
}

void sort_step()
{

}

int main() {

    inti_numbers();
    
    InitWindow(WIDTH,HEIGHT,"SORTING VISUALIZER");

    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(BLACK);
        draw_bars();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}