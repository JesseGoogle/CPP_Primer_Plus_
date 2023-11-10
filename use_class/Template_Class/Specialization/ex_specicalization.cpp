/**
 * ���潲�˶������ģ���࣬��������һ�������ʽʵ���������߽��ػ� explicit specialization��
 * 
 * ��ʾʵ���� ��ָ�ص����ͣ������滻ģ���еķ��ͣ��Ķ��塣
 * ��Щʱ�򣬿�����Ҫ��Ϊ��������ʵ����ʱ����ģ������޸ģ�ʹ����Ϊ��ͬ��
 * 
 * �����廯ģ���ͨ��ģ�嶼��ʵ��������ƥ��ʱ����������ʹ�þ��廯�汾��
*/

#include <iostream>
#include <cstring>

/*ģ����*/
template<typename Data_Type>
class EX_Specialization
{
    private:
        Data_Type dat;

    public:
        EX_Specialization() : dat(0) {}
        EX_Specialization(Data_Type _dat) : dat(_dat) {}
        void show() const { std::cout << dat << '\n'; }

        ~EX_Specialization() {}
};

/*ȫ�ػ������� C �����ַ���*/
template<>
class EX_Specialization<char *>
{
    private:
        char * _str;
        enum  { DEFAULT_SIZE = 12};

    public:
        EX_Specialization() : _str(new char[DEFAULT_SIZE]) {}
        EX_Specialization(const char * _s) : _str(new char[std::strlen(_s)]) { std::strcpy(_str, _s); }

        void show() { printf("%s\n", _str); }

        ~EX_Specialization() { delete[] _str; } 
};

int main(int argc, char const *argv[])
{
    
    EX_Specialization<double> ex_01(12.1345);
    EX_Specialization<char *> ex_02("ȫ�ػ������� C �����ַ���");

    ex_01.show();
    ex_02.show();

    return EXIT_SUCCESS;
}
