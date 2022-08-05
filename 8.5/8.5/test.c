#define _CRT_SECURE_NO_WARNINGS
//NULL -空指针       NUL/Null -‘/0’     字符串函数 操作的对象都是字符串 ‘/0’
#include <string.h>
#include <assert.h>

struct s
{
	char name[20];
	int age;
};
void* my_memcpy(void* dest,const void *src,size_t num)
{
	assert(dest && src);
	void *ret = dest;
	while (num--)
	{
		*(char*)dest = *(char*)src;//从源头拿了一个字符放到目的地里去
		++(char*)dest;//后置++不行 dest 先和++结合了
		++(char*)src;
	}
	return ret;
}
void* my_memmove(void* dest, const void *src, size_t num)
{
	//分情况讨论 dest 指向的在 src 前 ，在src src+num 里 ，dest+ num里
	void *ret = dest;

	assert(dest && src);
	if (dest < src)//dest 指向的在 src 前
	{
		while (num--)
		{
			*(char*)dest = *(char*)src;//从源头拿了一个字符放到目的地里去
			++(char*)dest;//后置++不行 dest 先和++结合了
			++(char*)src;
		}
	}
	else//在src src + num 里
	{
		while (num--)
		{

			*((char*)dest + num) = *((char*)src + num);//num--了 刚好是 指向我们需要的那个字节数
		}
	}
	return ret;
}
int main()
{
//	int arr1[] = { 1, 2, 3, 4 }; //在内存中存储（小端）01 00 00 00|02 00 00 00....
//	int arr2[5] = { 0 };
//
//	strcpy(arr2,arr1);//虽然可以考过去，但只有 只考了一个字节 （01）遇到\0 停止了

// memcpy(目的地，源，字符数（n）) 内存拷贝 什么类型都能拷贝 所以用 void* 接收
	int arr1[] = { 1, 2, 3, 4 };
	int arr2[5] = { 0 };
	struct s arr3[] = { { "张三", 20 }, { "李氏",10 } };
	my_memcpy(arr2,arr1,sizeof(arr1));//如果在一块空间里 重叠部分进行拷贝不行 源数据会被覆盖，系统给出的memcpy 可以
	
	//内存函数
	//memmove（arr+2；arr；5） 处理内存重叠的部分 
	my_memmove(arr1+1,arr1,12);
	//memcmp 内存比较
	//memset 内存设置
	char arr5[10] = "";
	memset(arr5, '#', 10);//都设置成# 这里 int 是改10个字节 
	int arr6[10] = "";
	memset(arr5, 1, 10);//不是10个1
	return 0;
}