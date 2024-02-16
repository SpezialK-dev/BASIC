class funktions_dic
{
private:
    
public:
    void PRINT(int a);
    void PRINT(float a);
    void PRINT(char* a);

    int PLUS(int a, int b);
    float PLUS(float a, float b);

    int MINUS(int a, int b);
    float MINUS(float a, float b);

    int TIMES(int a, int b);
    float TIMES(float a, float b);

    int MULTIPLICATIOn(int a, int b);
    float MULTIPLICATIOn(float a,float b);

    //conversion code
    float INT_TO_FLOAT(int a);
    int FLOAT_TO_INT(float a);

    void GOTO(int line_numb);

    //not sure of implementation
    void LET(int a);
    void LET(float a);
    //think of a way for strings
};
