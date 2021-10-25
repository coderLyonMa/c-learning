#include <debug_macros.h>
#include <show_bytes.h>


int main()
{
//    char* s = "hello world";
 
    prt_and_exec(char* s = "hello world");
    prt_and_exec(printf("%s\n", s));
    prt_and_exec(printf("ok google"));
    prt_and_exec(printf("0%o\n", 99));
    prt_and_exec(printf("0x%x\n", 12345U));

    // 小数点的作用在于控制左对齐和右对齐
    // 数字代表至少占据的宽度
    // 右对齐
    prt_and_exec(printf("%20e\n", 123.456));
    //        1.234560e+02

    // 左对齐，右边填充

    prt_and_exec(printf("%.20e\n", 123.456));
    // 1.23456000000000003070e+02
    prt_and_exec(printf("%.20E\n", 123.456));
    // 1.23456000000000003070E+02
    // 小数点后占据10个字符的位置
    prt_and_exec(printf("%11.10f\n", 123.456));
    prt_and_exec(printf("%10.10d\n", 123456));
    prt_and_exec(printf("%.*s\n", 11, s));
    // ASCII 值 
    prt_and_exec(printf("ASCII 值\n"));
    char* cs = "值";
    prt_and_exec(printf("%x\n", "值"));
    int str_len(char* s);
    
    printd(str_len("值"));
}

int str_len(char* s)
{
    char* t = s;
    while (*t)
        ++t;
    return t - s;
}
