#pragma once
/*
��̬��ӿڵ������á���������̬�⣬��ֻ��һ��dll�ļ�������������Ҫlib�ļ��ġ��������������������һ����̬���lib�ļ��������ӣ���lib�ļ������ӿ���Ϣ��
�����̬��Ľӿ�û�䣬��ôlib�ļ�����Զ����ı�ġ����Խӿڲ��������£��滻��̬��Ϳ���ʵ��������
*/
#ifdef UTILS_EXPORTS
    #define DLL_EXPORT_UTILS __declspec(dllexport)
#else
    #define DLL_EXPORT_UTILS __declspec(dllimport)
#endif