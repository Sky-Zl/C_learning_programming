/* P25 练习1-23 删除C程序中的所有注释语句。C语言中，注释不允许嵌套 */

#include <iostream>
#include <fstream> 
using namespace std;

#define IN_MULTI_ANN 3	// 当前处于多行注释 
#define IN_SINGLE_ANN 2	// 当前处于单行注释 
#define IN_QUO 1		// 当前处于双引号内 
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
	int state=OUT;		/* next：c的下一个字符 */				

	while(inFile.get(c)){
		if( state == OUT){
			switch(c){
				case '/': 
					inFile.get(next);
					if(next == '*')
						{
							state = IN_MULTI_ANN;	/* 进入多行注释 */
						}
					else if(next == '/')
						{
							state = IN_SINGLE_ANN;	/* 进入单行注释 */
						}
					else{	// 没有进入注释，则打印刚读入的字符
						outFile.put(c);
						outFile.put(next);
					}
					break;
				case '\"':
					state = IN_QUO;				/* 进入字符串内 */
					outFile.put(c);
					break;
				default:	/* 其他字符则打印 */
					outFile.put(c);
					break;
			}
		}else if(state == IN_MULTI_ANN){
			if(c == '*'){
				inFile.get(next);	
				if(next == '/')		// 遇到 */ 多行注释结束 
				{
					state = OUT;
					outFile.put('\n');
				}
			}
		}else if(state == IN_SINGLE_ANN){
			if( c == '\n'){		// 单行注释结束
				state = OUT;
				outFile.put('\n');
			}
		}else if(state == IN_QUO){
				/* 双引号内的所有内容都需要保存 */
				if(c == '\"'){	// 双引号结束
					outFile.put(c);
					state = OUT;
				}else if( c == '\\'){	// 如果当前是转义字符则即使下一个字符是 " 也不用管，直接不考虑
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

