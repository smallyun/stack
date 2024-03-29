
#include <iostream.h>
#include <stdlib.h>

#define MAXSIZE   0xFFFF
 
template<class type>
class SeqStack
{
int   top;     //栈顶指示
type *stacka;    //数组名
int   maxsize;    //栈最大可容纳元素个数
public:
SeqStack();
SeqStack(int size);
SeqStack(type data[],int size);
virtual ~SeqStack()
{
   delete []stacka;
}
void Push(const type &item);    //元素item压栈
type Pop();        //数据元素出栈,返回之
type GetTop();       //读栈顶数据元素并返回

int   Empty()const
{
   return top==-1;
}           //判断栈是否为空
int   Full()const
{
   return top==maxsize-1;
}           //判断栈是否为满
void Clear()
{
   top=-1;
}           //清空栈
};

template<class type>
SeqStack<type>::SeqStack():
top(-1),maxsize(MAXSIZE)
{
stacka=new type[maxsize];
if(stacka==NULL){
   cerr<<"动态存储分配失败!"<<endl;
   exit(1);
}
}
template<class type>
SeqStack<type>::SeqStack(int size):
top(-1),maxsize(size)
{
stacka=new type[maxsize];    //创建存储栈的数组
if(stacka==NULL){      //分配不成功
   cerr<<"动态存储分配失败!"<<endl;
   exit(1);
}
}
template<class type>
SeqStack<type>::SeqStack(type data[],int size):
top(-1),maxsize(size)
{
stacka=new type[maxsize];    //创建存储栈的数组
if(stacka==NULL){      //分配不成功
   cerr<<"动态存储分配失败!"<<endl;
   exit(1);
}
for(int i=0;i<maxsize;i++){
   stacka[i]=data[i];
}

top+=maxsize;
}

template<class type>
void SeqStack<type>::Push(const type& item)
{
//若栈已满，出错处理；否则把元素item压栈
if(Full()){         
   cerr<<"栈已满，不能压栈!"<<endl;
   exit(1);
}
//这里我们采用指针先移动，然后再对元素进行操作的方式
top++;   

stacka[top]=item;
}

template<class type>
type SeqStack<type>::Pop()
{
if(Empty()){
   cerr<<"栈已空!"<<endl;
   exit(1);
}
//栈不空，取栈顶元素
type data=stacka[top];
top--;
//返回栈顶元素
return data;
}

template<class type>
type SeqStack<type>::GetTop()
{
//若栈不空，返回栈顶元素的值
if(Empty()){
   cerr<<"栈空!"<<endl;
   exit(1);
}
//返回栈顶元素的值
return stacka[top];
}
 
 

#include <SeqStack.h>
int main()
{
int data[10]={1,2,3,4,5,6,7,8,9,10};
SeqStack<int> stack(data,10);
while(!stack.Empty()){
   cout<<stack.Pop()<<" ";
}
cout<<endl;
return 0;
}
输出结果：
10 9 8 7 6 5 4 3 2 1
Press any key to continue
