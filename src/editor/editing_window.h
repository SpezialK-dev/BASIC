class editing_window
{
private:
    char linebuffer[32767][120];//might have to optimize this cause this takes reserves a lot of memery should be around ~3-4 mbyte
    int last_usedline;
    void add_line();
    void remove_whitespace();//this might not be needed
    bool currently_running;
public:
    void open_editor();
    char* get_linebuffer_line(int line_in_linebuffer);
    editing_window();
     
};

editing_window::editing_window()
{
    currently_running=true;
    last_usedline = 0;
}
