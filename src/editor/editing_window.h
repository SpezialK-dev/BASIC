class editing_window
{
private:
    char linebuffer[32767][120];//might have to optimize this cause this takes reserves a lot of memery should be around ~3-4 mbyte
    //values are abatrary 
    const char error_msgs[20][250]{
        "LINE TO LONG", 
        "SYNTAX ERROR",
        "TYPE MISSMATCH",
        "READING/WRITING OUT OF LINE BUFFER SPACE"
    };
    int last_usedline;
    bool currently_running;
    void add_line();
    int get_line_number(char* input_line);
    void copy_to_line_buffer(char* input, int position);

public:
    void open_editor();
    char* get_linebuffer_line(int line_in_linebuffer);
    void raise_error(int error_code);
    editing_window();
};

inline editing_window::editing_window()
{
    currently_running=true;
    last_usedline = 0;
    //TODO preify this
    
}
