/* P25 ��ϰ1-23 ɾ��C�����е�����ע����䡣C�����У�ע�Ͳ�����Ƕ�� */

#include <iostream>
#include <fstream> 
using namespace std;

#define IN_MULTI_ANN 3	// ��ǰ���ڶ���ע�� 
#define IN_SINGLE_ANN 2	// ��ǰ���ڵ���ע�� 
#define IN_QUO 1		// ��ǰ����˫������ 
#define OUT 0			


int main(int argc,char *argv[]){
	

	if(argc != 3){
		cout<< "File name is missing!"<< endl;
	}
	ifstream inFile(argv[1],ios::in);
	if(!inFile){
		cout << "Source file open error."<<endl;
		return 0;
	}
	ofstream outFile(argv[2],ios::out);
	if(!outFile){
		cout << "New file open error." <<endl;
		inFile.close();
		return 0;
	}
	
	char c,next;
	int state=OUT;		/* next��c����һ���ַ� */				

	while(inFile.get(c)){
		if( state == OUT){
			switch(c){
				case '/': 
					inFile.get(next);
					if(next == '*')
						{
							state = IN_MULTI_ANN;	/* �������ע�� */
						}
					else if(next == '/')
						{
							state = IN_SINGLE_ANN;	/* ���뵥��ע�� */
						}
					else{	// û�н���ע�ͣ����ӡ�ն�����ַ�
						outFile.put(c);
						outFile.put(next);
					}
					break;
				case '\"':
					state = IN_QUO;				/* �����ַ����� */
					outFile.put(c);
					break;
				default:	/* �����ַ����ӡ */
					outFile.put(c);
					break;
			}
		}else if(state == IN_MULTI_ANN){
			if(c == '*'){
				inFile.get(next);	
				if(next == '/')		// ���� */ ����ע�ͽ��� 
				{
					state = OUT;
					outFile.put('\n');
				}
			}
		}else if(state == IN_SINGLE_ANN){
			if( c == '\n'){		// ����ע�ͽ���
				state = OUT;
				outFile.put('\n');
			}
		}else if(state == IN_QUO){
				/* ˫�����ڵ��������ݶ���Ҫ���� */
				if(c == '\"'){	// ˫���Ž���
					outFile.put(c);
					state = OUT;
				}else if( c == '\\'){	// �����ǰ��ת���ַ���ʹ��һ���ַ��� " Ҳ���ùܣ�ֱ�Ӳ�����
					inFile.get(next);
					outFile.put(c);
					outFile.put(next);
				}else{
					outFile.put(c);
				}
		}
	}
	outFile.put('\0');
}

