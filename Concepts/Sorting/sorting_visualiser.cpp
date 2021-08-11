#include<SDL2/SDL.h>
#include<bits/stdc++.h>
#include<limits>
#include<time.h>
using namespace std;

/*    
    Learning how to add text and provide more functionality

*/


//sdl variables and constants needed for the windows and visualisation
SDL_Window *createWindow;
SDL_Renderer *renderer;
const unsigned int screen_width = 1000;
const unsigned int screen_height = 1000;
const unsigned int sizeofbar = 5;
bool completed = false;

//variables for the array and array size
const int sizeofArray=50;
int arr[sizeofArray];


//function to close and destroy the SDL Window and Renderer once the program is over
void close(){

    //destroying the created window and render
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(createWindow);
        SDL_Quit();

    //setting the variables back to nullptr
        renderer = nullptr;
        createWindow = nullptr;
}

//function to initialise the SDL Interface and return true if the the initialising is successful
bool init(){

    /*initialises the SDL Library,where
        int SDL_Init(Uint32 flags); */        
        if(SDL_Init(SDL_INIT_EVERYTHING)<0){
            cout<<"Error In Intialising SDL : "<<SDL_GetError()<<endl;
            return false;
        }
    
    /*creating the window on the screen with desired constraints and flag,where
        SDL_Window * SDL_CreateWindow(const char *title, int x, int y, int w, int h, Uint32 flags); */
        createWindow = SDL_CreateWindow("Sorting Visualiser",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,screen_width,screen_height,SDL_WINDOW_SHOWN);
        if(!createWindow){
            cout<<"Error In Creating The SDL Window : "<<SDL_GetError()<<endl;
            return false;
        }        

    /*creating a 2D rendering context for the window,where
        SDL_Renderer * SDL_CreateRenderer(SDL_Window * window,int index, Uint32 flags); */
        renderer = SDL_CreateRenderer(createWindow,-1,SDL_RENDERER_ACCELERATED);
        if(!renderer){
            cout<<"Error In Creating 2D Rendering : "<<SDL_GetError()<<endl;
            return false;
        }

    //returning true if the initialising is successful
        return true;    
}

/*function for visualisation of the sorting done,where
    if the values aren't passed then the default -1 value is passed to the parameters*/
void visualise(int x=-1,int y=-1,int z=-1){

    /*set the color used for drawing operations(Rect, Line and Clear),where    
        int SDL_SetRenderDrawColor(SDL_Renderer * renderer,Uint8 r, Uint8 g, Uint8 b,Uint8 a); */
        SDL_SetRenderDrawColor(renderer,0,0,0,0);

    /*clear the entire screen to our selected color*/
        SDL_RenderClear(renderer);

    /*visualisation logic
        j -> used to track the position of the array elements
    */    
    for(int i=0,j=0;i<=screen_width-sizeofbar;i+=sizeofbar,++j){
        /*pump the event loop, gathering events from the input devices,
            void SDL_PumpEvents(void); */
            SDL_PumpEvents();

        /*a structure that contains the definition of a rectangle, with the origin at the upper left,where
            SDL_Rect{
                x,  -> x location of the rectangle's upper left corner
                y,  -> y location of the rectangle's upper left corner
                w,  -> width of the rectangle
                h}; -> heiht of the rectangle */ 
            SDL_Rect rectangle = {i,0,sizeofbar,arr[j]};
            
            /*if the rendering is completed then we produce the array in green color*/
            if(completed){                
                SDL_SetRenderDrawColor(renderer,100,180,100,0);
                SDL_RenderDrawRect(renderer,&rectangle);
            }else if(j==x || j==z){
                /*rendering the ones that are sorted in green color*/
                SDL_SetRenderDrawColor(renderer, 100, 180, 100, 0);
                SDL_RenderFillRect(renderer, &rectangle);

            }else if(j==y){
                /*rendering the current element being sorted to purple color*/
                SDL_SetRenderDrawColor(renderer, 68, 100, 100, 0);
                SDL_RenderFillRect(renderer, &rectangle);

            }else{
                SDL_SetRenderDrawColor(renderer, 185, 185, 185, 0);
                SDL_RenderDrawRect(renderer, &rectangle);                
            }                       
    }    
    SDL_RenderPresent(renderer);

}

void execute(){
    bool initialisation = init();
    if(!initialisation){
        cout<<"Couldn't Initialise SDL\n";
        return ;        
    }

    
}

int main(int agrv,char **agrs){
    execute();
    return 0;
}