class editing_window
{
private:
    char linebuffer[32767][120];//might have to optimize this cause this takes reserves a lot of memery should be around ~3-4 mbyte
    //values are abatrary 
    const char error_msgs[20][250]{
        "LINE TO LONG", 
        "SYNTAX ERROR",
        "TYPE MISSMATCH",
    };
    int last_usedline;
    void add_line();
    void remove_whitespace();//this might not be needed
    bool currently_running;
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
