/*
����
һ����'.'��β�ļ�Ӣ�ľ��ӣ�����֮���ÿո�ָ���û����д��ʽ������������ʽ

����
һ����'.'��β�ļ�Ӣ�ľ��ӣ����Ȳ�����500��������֮���ÿո�ָ���û����д��ʽ������������ʽ

���
�þ�������ĵ��ʡ��������һ�����������һ��
*/ 
//�ó����ʵ�����Ծ���β�ľ��ӣ�������Ծ���β�����޷��������һ������
#include <iostream>
using namespace std;
int main()
{
    int maxlen=0;//������¼�����
    char s[500];
    cin.getline(s,500);
    int tmplen=0;//��¼��ǰ���ʵĳ���
    int last=0;//��¼����ʽ���ʱ���±�
    for(int i=0;s[i]!='\0';i++)
    {
        if(s[i]=='.')//�ж������������
        {
            if(maxlen<tmplen)
            {
                maxlen=tmplen;
                tmplen=0;
                last=i;
            }
            break;
        }
        else if(s[i]!=' ')
            tmplen++;
        else //�����ո� 
        {
            if(maxlen<tmplen)
            {
                maxlen=tmplen;
                last=i;
            }
            tmplen=0;
        }
    } 
    //������
    cout << "�þ����������Ϊ��" ;
    for(int i=last-maxlen;i<last;i++)
        cout << s[i] ;
    return 0;
}

