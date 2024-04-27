#include <lcom/lcf.h>
#include "labjack.h"
#include "dvr_graphics.h"
#include "io.h"

// Any header files included below this line should have been created by you

int main(int argc, char *argv[])
{
  // sets the language of LCF messages (can be either EN-US or PT-PT)
  lcf_set_language("EN-US");

  // enables to log function invocations that are being "wrapped" by LCF
  // [comment this out if you don't want/need it]
  lcf_trace_calls("/home/lcom/labs/proj/src/trace.txt");

  // enables to save the output of printf function calls on a file
  // [comment this out if you don't want/need it]
  lcf_log_output("/home/lcom/labs/proj/src/output.txt");

  // handles control over to LCF
  // [LCF handles command line arguments and invokes the right function]
  if (lcf_start(argc, argv))
    return 1;

  // LCF clean up tasks
  // [must be the last statement before return]
  lcf_cleanup();

  return 0;
}

int counter = 0;
extern uint8_t scancode;
extern int output;

//chamado pela lcom_run
int (proj_main_loop)(int argc, char **argv)
{
int r= set_frame_buffer(0x105);
  if(r!=OK){return r;}
  r = set_graphic_mode(0x105);
  if(r!=OK){return r;}
  r = print_xpm(penguin, 56, 76);
  if(r!=OK){return r;}
 
  sleep(1);
    
    // Mover a imagem com o mouse
    r = move_xpm_mouse(penguin, 50, 50);
    if (r != OK) {
        return r;
    }
  r=vg_exit();
  return 0;
}

