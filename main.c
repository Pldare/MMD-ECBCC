#include <stdio.h>
#include <stdlib.h>
float FMUN(float mun2,float mun3,float mun5,float mun6,float mun8,float mun9);
float UFMUN(float umun2,float umun3,float umun5,float umun6,float umun8,float umun9);
float Z_(float AA,float BB);
float PF(float DD,float EE,float FF,float GG,float HH,float JJ);
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{ 
	float demoa[2],demob[2],democ[2],demoz[2];
	double AZ,BZ,CZ,DZ,DDZ;
	double mum1,mum2,mum3,mum4,mum5,mum6;
	double Aa_,Ba_,Ca_,Da_; 
	double Ab_,Bb_,Cb_,Db_;
	double XX1,XX2,YY1,YY2,ZZ1,ZZ2;
	double XO,YO,ZO,XXO,ZZO; 
	printf("please scanf MMD's bone XYZ char\n");
	printf("请输入从mmd中复制来的第一个XYZ坐标\n");
	scanf("%f,%f,%f",&demoa[0],&demoa[1],&demoa[2]);
	printf("%f\n%f\n%f\n",demoa[0],demoa[1],demoa[2]);
	printf("输入从mmd中复制来的第二个XYZ坐标\n");
	scanf("%f,%f,%f",&demob[0],&demob[1],&demob[2]);
	printf("%f\n%f\n%f\n",demob[0],demob[1],demob[2]);
	printf("输入从mmd中复制来的第三个XYZ坐标\n");
	scanf("%f,%f,%f",&democ[0],&democ[1],&democ[2]);
	printf("%f\n%f\n%f\n",democ[0],democ[1],democ[2]);
	double num1=demoa[1];//第一组的Y 
	double num2=demoa[2];//第一组的Z 
	double num3=demob[1];//第二组的Y
	double num4=demob[2];//第二组的Z 
	double num5=democ[1];//第三组的Y 
	double num6=democ[2];//第三组的Z
	//其余X部分的传值 
	double num7= demoa[0];//第一部分的X 
	double num8= demob[0];//第二部分的X 
	double num9= democ[0];//第三部分的X
	printf("%.15g\r\n%.15g\r\n%.15g\r\n%.15g\r\n%.15g\r\n%.15g\r\n%.15g\r\n%.15g\r\n%.15g\r\n",num7,num1,num2,num8,num3,num4,num9,num5,num6); 
	AZ= FMUN(num1,num2,num3,num4,num5,num6);//2test 
	BZ= UFMUN(num7,num2,num8,num4,num9,num6);//DZ预处理 
	CZ= FMUN(num7,num1,num8,num3,num9,num5);
	DDZ= num7*num3*num6 - num7*num5*num4 - num8*num1*num6 + num8*num5*num2 + num9*num1*num4 - num9*num3*num2;//纠正 
	DZ=-DDZ;
	printf("预处理AZ=%.15g\r\n",AZ);
	printf("预处理BZ=%.15g\r\n",BZ);
	printf("预处理CZ=%.15g\r\n",CZ);
	printf("预处理DZ=%.15g\r\n",DZ);
	printf("开始处理A_\n");
	//再次运算
	Aa_=Z_(num8,num7);
	Ba_=Z_(num3,num1);
	Ca_=Z_(num4,num2);
	Da_=PF(num7,num1,num2,num8,num3,num4);
	printf("预处理Aa=%.15g\r\n",Aa_);
	printf("预处理Ba=%.15g\r\n",Ba_);
	printf("预处理Ca=%.15g\r\n",Ca_);
	printf("预处理Da=%.15g\r\n",Da_);
	printf("开始处理B_部分\n");
	Ab_=Z_(num9,num7);
	Bb_=Z_(num5,num1);
	Cb_=Z_(num6,num2);
	Db_=PF(num7,num1,num2,num9,num5,num6);
	printf("预处理Ab=%.15g\r\n",Ab_);
	printf("预处理Bb=%.15g\r\n",Bb_);
	printf("预处理Cb=%.15g\r\n",Cb_);
	printf("预处理Db=%.15g\r\n",Db_);
	printf("最终计算\n");
	XX1=BZ*Ca_*Db_ - BZ*Cb_*Da_ - Ba_*CZ*Db_ + Ba_*Cb_*DZ + Bb_*CZ*Da_ -Bb_*Ca_*DZ;
	XX2=AZ*Ba_*Cb_ - AZ*Bb_*Ca_ - Aa_*BZ*Cb_ + Aa_*Bb_*CZ + Ab_*BZ*Ca_ - Ab_*Ba_*CZ;
	YY1=AZ*Ca_*Db_ - AZ*Cb_*Da_ - Aa_*CZ*Db_ + Aa_*Cb_*DZ + Ab_*CZ*Da_ - Ab_*Ca_*DZ;
	YY2=AZ*Ba_*Cb_ - AZ*Bb_*Ca_ - Aa_*BZ*Cb_ + Aa_*Bb_*CZ + Ab_*BZ*Ca_ - Ab_*Ba_*CZ;
	ZZ1=AZ*Ba_*Db_ - AZ*Bb_*Da_ - Aa_*BZ*Db_ + Aa_*Bb_*DZ + Ab_*BZ*Da_ - Ab_*Ba_*DZ;
	ZZ2=AZ*Ba_*Cb_ - AZ*Bb_*Ca_ - Aa_*BZ*Cb_ + Aa_*Bb_*CZ + Ab_*BZ*Ca_ - Ab_*Ba_*CZ;
	XXO=XX1/XX2;
	XO=-XXO;
	YO=YY1/YY2;
	ZZO=ZZ1/ZZ2;
	ZO=-ZZO;
	printf("%.15g,%.15g,%.15g\n",XO,YO,ZO);
	printf("请自行选中数据ctrl+c复制\n");
	system("pause"); 
	return 0;
}
float FMUN(float mun2,float mun3,float mun5,float mun6,float mun8,float mun9)//ABCDZ算法部分 
{
	float result;
	result=mun2*mun6 - mun5*mun3 - mun2*mun9 + mun8*mun3 + mun5*mun9 - mun8*mun6;
	//printf("调用Z函数部分\n");
	return result; 
}
float UFMUN(float umun2,float umun3,float umun5,float umun6,float umun8,float umun9)//-ABCDZ算法部分 
{
	float uresult,uuresult;
	uuresult=umun2*umun6 - umun5*umun3 - umun2*umun9 + umun8*umun3 + umun5*umun9 - umun8*umun6;
	//printf("调用-Z函数部分\n");
	uresult=-uuresult;
	return uresult; 
}
//再次函数
 float Z_(float AA,float BB)
 {
 	float CC;
 	float ZZ=2;
 	CC=ZZ*(AA-BB);
 	//printf("调用Z_函数部分\n"); 
 	return CC;
 }
 float PF(float DD,float EE,float FF,float GG,float HH,float JJ)
 {
 	float KK,D,E,F,G,H,J;
 	D=DD*DD;
 	E=EE*EE;
 	F=FF*FF;
 	G=GG*GG;
 	H=HH*HH;
 	J=JJ*JJ;
 	KK=D+E+F-G-H-J;
 	//printf("调用平方函数部分\n");
 	return KK;
 }
