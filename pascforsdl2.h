#ifndef PASCFORSDL2_H
#define PASCFORSDL2_H

//checking libraries
#if defined(__has_include)
#if __has_include(<SDL2/SDL.h>)
#include <SDL2/SDL.h>
#define SDL2
#endif
#endif
#if defined(__has_include)
#if __has_include(<SDL2/SDL_opengles2.h>)
#include <SDL2/SDL_opengles2.h>
#define OPENGLES2
#endif
#endif

//Shaders option
#define beginvec3  "attribute vec3 aPos;\n void main() {\n"
#define beginvec2 "attribute vec2 aPos;\n void main() {\n"
#define endvec3 "gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n }\n"
#define endvec2 "gl_Position = vec4(aPos.x, aPos.y, 0.0, 1.0);\n }\n"
#define fragdef "precision mediump float;\n" "void main() {\n"
#define fragcolors(r, g, b, a) "gl_FragColor = vec4(" #r "," #g "," #b "," #a "); }"



//SDL2
#ifdef SDL2
//window
#define WinBase SDL_Window
#define Window(title, x, y, w, h, flags) SDL_CreateWindow(title, x, y, w, h, flags)
#define WinGSize(window, w, h) SDL_GetWindowSize(window, &w, &h)
#define WinSSize(window, w, h) SDL_SetWindowSize(window, w, h)
#define WinPos(window, x, y) SDL_SetWindowPosition(window, x, y)
#define WinDes(w) SDL_DestroyWindow(w)
#define WinFLSC(w, f) SDL_SetWindowFullscreen(w, f)
#define WinHide(w) SDL_HideWindow(w)
#define WinShow(w) SDL_ShowWindow(w)
#define Context(w) SDL_GL_CreateContext(w)
#define WinSwap(w) SDL_GL_SwapWindow(w)
//Audio
#define AudSpec SDL_AudioSpec
#define OpenAud(req, obt) SDL_OpenAudio(req, obt)
#define PauseAud(f) SDL_PauseAudio(f)  
#define QueAud(d, s) SDL_QueueAudio(1, d, s) 
#define ClrAud() SDL_ClearQueuedAudio(1)
#define CloseAud() SDL_CloseAudio()
#define AF32  AUDIO_F32  
#define AS16  AUDIO_S16
#define MONO  1
#define STEREO 2

//Renderer
#define RenBase SDL_Renderer
#define Rend(w, i, f) SDL_CreateRenderer(w, i, f)
#define RenCol(r, R, G, B, A) SDL_SetRenderDrawColor(r, R, G, B, A)
#define RenClear(r) SDL_RenderClear(r)
#define RenPres(r) SDL_RenderPresent(r)
#define RenDes(r) SDL_DestroyRenderer(r)

//time
#define wait(ms) SDL_Delay(ms)
#define GetTicks SDL_GetTicks()

//text and log
#define ShowErr(t, msg) SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, t, msg, NULL)
#define log(msg) SDL_Log(msg)

//Event
#define EvBase SDL_Event
#define EvPol(ev) SDL_PollEvent(&(ev))
#define GetMState(x, y) SDL_GetMouseState(&x, &y)
#define XPOS(e) e.button.x
#define YPOS(e) e.button.y
#define MOBTDW SDL_MOUSEBUTTONDOWN
#define MOBTUP SDL_MOUSEBUTTONUP
#define BTLF SDL_BUTTON_LEFT
#define FINDW SDL_FINGERDOWN
#define FINUP SDL_FINGERUP
#define FINMO SDL_FINGERMOTION
//Init
#define Init(f) SDL_Init(f)

//Flags
#define FS SDL_WINDOW_FULLSCREEN
#define HIDE SDL_WINDOW_HIDDEN
#define RESIZE SDL_WINDOW_RESIZABLE
#define BRDLS SDL_WINDOW_BORDERLESS
#define MAX SDL_WINDOWPOS_MAXIMIZED
#define MIN SDL_WINDOW_MINIMIZED
#define GL SDL_WINDOW_OPENGL
#define CENT SDL_WINDOWPOS_CENTERED
#define UNDE SDL_WINDOWPOS_UNDEFINED
#define VID SDL_INIT_VIDEO
#define AUB SDL_INIT_AUDIO
#define JST SDL_INIT_JOYSTICK
#define GCTR SDL_INIT_GAMECONTROLLER
#define EVENT SDL_INIT_EVENTS
#define ALL SDL_INIT_EVERYTHING
#define QUIT SDL_QUIT
#define KDWN SDL_KEYDOWN
#define Rect SDL_Rect
#define REAC SDL_RENDERER_ACCELERATED
#define VSYNC SDL_RENDERER_PRESENTVSYNC
#define GLAB GL_ARRAY_BUFFER
#define VERSH GL_VERTEX_SHADER
#define FRAGSH GL_FRAGMENT_SHADER
#define TRNGLS GL_TRIANGLES
#define TRNFAN GL_TRIAGLE_FAN
#define TRNSTR GL_TRIANGLES_STRIP
#define POINTS GL_POINTS
#define LINES GL_LINES
#define LOOP GL_LINE_LOOP
#define STRP GL_LINE_STRIP
#define COLBB GL_COLOR_BUFFER_BIT
#define COLDB GL_DEPTH_BUFFER_BIT
#define COLSB GL_STENCIL_BUFFER_BIT
#define STATIC GL_STATIC_DRAW
#define DYNAM GL_DYNAMIC_DRAW
#define GFL GL_FLOAT
#define GUI GL_UNSIGNED_INT
#define GUB GL_UNSIGNED_BYTE
#define GSH GL_UNSIGNED_SHORT
#define GUS GL_UNSIGNED_SHORT
#define GFIX GL_FIXED
#define TEX2D GL_TEXTURE_2D
#define TEXMINF GL_TEXTURE_MIN_FILTER
#define TEXMAGF GL_TEXTURE_MAG_FILTER
#define TEXWRAS GL_TEXTURE_WRAP_S
#define TEXWRAT GL_TEXTURE_WRAP_T
#define NEAREST GL_NEAREST
#define LINEAR GL_LINEAR
#endif


//OPENGLES2
#ifdef OPENGLES2
//Shaders
#define shader const char
#define CrtSh(t) glCreateShader(t)
#define ShSrc(s, c)  glShaderSource(s, 1, &c, NULL)
#define ShCom(s) glCompileShader(s)
#define LinkPrg(p) glLinkProgram(p)
#define GlClr(m) glClear(m)
#define ShAtt(p, s) glAttachShader(p, s)
#define UsePrg(p) glUseProgram(p)
#define CrtPrg() glCreateProgram()
#define GenBuf(n, b) glGenBuffers(n, &b)
#define BindBuf(t, b) glBindBuffer(t, b)
#define BuffDat(t, s, d, u) glBufferData(t, s, d, u)
#define EnVA(i) glEnableVertexAttribArray(i)
#define AtrPtr(i, s, t, n, st, p) glVertexAttribPointer(i, s, t, n, st, p)
#define Dray(f, n, th) glDrawArrays(f, n, th)

//Variables
#define G GLint
#define Gu GLuint

//Vertices
#define ver(name) float name[]
#endif
#endif 
