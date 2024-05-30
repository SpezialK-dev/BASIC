#ifndef editing_window_h
#define editing_window_h

static const int MAX_LINE_NUMB =32767;

class funktionstable;
class variable_handling;

class editing_window
{
private:
    unsigned char **linebuffer;//[32767][120];//might have to optimize this cause this takes reserves a lot of memery should be around ~3-4 mbyte 
  bool line_set[MAX_LINE_NUMB];
    //values are abatrary 
    const char error_msgs[20][250]{
        "LINE TO LONG", 
        "SYNTAX ERROR",
        "TYPE MISSMATCH",
        "READING/WRITING OUT OF LINE BUFFER SPACE"
    };
    int last_usedline;
    bool currently_running;
    bool add_line(funktionstable *funkt_table,variable_handling* variables_table);
    int get_line_number(char* input_line);
    void copy_to_line_buffer(unsigned char* input, int position);
    
public:
    void open_editor(funktionstable *funkt_table, variable_handling* variables_table);
    unsigned char* get_linebuffer_line(int line_in_linebuffer);
    void raise_error(int error_code);
    editing_window();
  ~editing_window();
    void end_editing_window();
  bool get_linebuffer_bool(int line_in_linebuffer);
};

inline editing_window::editing_window()
{   
    linebuffer = new unsigned char* [MAX_LINE_NUMB];
    for(int i = 0; i <= MAX_LINE_NUMB; i++){
        //linebuffer[i] = new unsigned char[120];  
        line_set[i] = false;
    }
    currently_running=true;
    last_usedline = 0;
    //TODO preify this
    
}

#endif /* editing_window_h */
