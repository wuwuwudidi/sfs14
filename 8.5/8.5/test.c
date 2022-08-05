#define _CRT_SECURE_NO_WARNINGS
//NULL -��ָ��       NUL/Null -��/0��     �ַ������� �����Ķ������ַ��� ��/0��
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
		*(char*)dest = *(char*)src;//��Դͷ����һ���ַ��ŵ�Ŀ�ĵ���ȥ
		++(char*)dest;//����++���� dest �Ⱥ�++�����
		++(char*)src;
	}
	return ret;
}
void* my_memmove(void* dest, const void *src, size_t num)
{
	//��������� dest ָ����� src ǰ ����src src+num �� ��dest+ num��
	void *ret = dest;

	assert(dest && src);
	if (dest < src)//dest ָ����� src ǰ
	{
		while (num--)
		{
			*(char*)dest = *(char*)src;//��Դͷ����һ���ַ��ŵ�Ŀ�ĵ���ȥ
			++(char*)dest;//����++���� dest �Ⱥ�++�����
			++(char*)src;
		}
	}
	else//��src src + num ��
	{
		while (num--)
		{

			*((char*)dest + num) = *((char*)src + num);//num--�� �պ��� ָ��������Ҫ���Ǹ��ֽ���
		}
	}
	return ret;
}
int main()
{
//	int arr1[] = { 1, 2, 3, 4 }; //���ڴ��д洢��С�ˣ�01 00 00 00|02 00 00 00....
//	int arr2[5] = { 0 };
//
//	strcpy(arr2,arr1);//��Ȼ���Կ���ȥ����ֻ�� ֻ����һ���ֽ� ��01������\0 ֹͣ��

// memcpy(Ŀ�ĵأ�Դ���ַ�����n��) �ڴ濽�� ʲô���Ͷ��ܿ��� ������ void* ����
	int arr1[] = { 1, 2, 3, 4 };
	int arr2[5] = { 0 };
	struct s arr3[] = { { "����", 20 }, { "����",10 } };
	my_memcpy(arr2,arr1,sizeof(arr1));//�����һ��ռ��� �ص����ֽ��п������� Դ���ݻᱻ���ǣ�ϵͳ������memcpy ����
	
	//�ڴ溯��
	//memmove��arr+2��arr��5�� �����ڴ��ص��Ĳ��� 
	my_memmove(arr1+1,arr1,12);
	//memcmp �ڴ�Ƚ�
	//memset �ڴ�����
	char arr5[10] = "";
	memset(arr5, '#', 10);//�����ó�# ���� int �Ǹ�10���ֽ� 
	int arr6[10] = "";
	memset(arr5, 1, 10);//����10��1
	return 0;
}