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

void swap(int i,int j){
    int temp = numbers[i];
    numbers[i] = numbers[j];
    numbers[j] = temp;
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
        int j = rand() % (i + 1); //random in the range of index 

        //swap
        swap(i,j);
    }
}


int bi = 0,bj = 0;

void bubble_sort()
{
    if(bi < COUNT)
    {
        if(bj < COUNT - bi - 1)
        {
            if(numbers[bj] > numbers[bj + 1])
            {
                swap(bj,bj + 1);
            }
            bj++;
        }else
        {
            bj = 0;
            bi++;
        }
        
    }
}


int si = 0, sj = 0, min_idx = 0;

void selection_sort()
{
    if(si < COUNT)
    {
        if(sj == 0)
        {
            min_idx = si;
            sj = si + 1;
        }
        
        if(sj < COUNT)
        {
            if(numbers[sj] < numbers[min_idx])
            {
                min_idx = sj;
            }
            sj++;
        }else
        {
            swap(si,min_idx);
            
            si++;
            sj = 0;
        }
    }
}

void insertion_sort()
{
    
}

void sort_step()
{
    bubble_sort();
}

int main()
{

    inti_numbers();
    
    InitWindow(WIDTH,HEIGHT,"SORTING VISUALIZER");

    SetTargetFPS(1);
    while(!WindowShouldClose()){
        sort_step();
        BeginDrawing();
        ClearBackground(BLACK);
        draw_bars();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}