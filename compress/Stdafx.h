#ifndef _STDAFX_H_
#define _STDAFX_H_

#ifdef _MSC_VER   //΢��������İ汾�꣬vs2015��1900
    /*
    �����windows�µ���Ŀ��,���Ǿ������Կ�����stdafx.h������ô���궨��#define WIN32_LEAN_AND_MEAN,��������ʵ�����ǵ�������Ŀ�а�����<windows.h>
    ʱȥ��һЩͷ�ļ��İ���,�ӿ�����ٶ�,��ҿ�������<windows.h>������һ��WIN32_LEAN_AND_MEAN���ܿ���ȥ������Щͷ�ļ��İ�����
    */
    #define WIN32_LEAN_AND_MEAN     // Exclude rarely-used stuff from Windows headers
    /*
    warning C4996: strcpy was declared deprecated
    ��ʹ��VC 2005 �Ŀ����߻��������������⣬��ʹ��std�����ռ�⺯����ʱ���������������������ľ��棺    warning C4996: strcpy was declared deprecated
    ���������ľ��棬����ΪVC2005����ΪCRT�е�һ�麯�����ʹ�ò��������ܻ���������ڴ�й¶��������������Ƿ����ʵȰ�ȫ���⡣��Щ�����磺strcpy��strcat�ȡ�
    ������Щ���⣬VC2005����ʹ����Щ�����ĸ��߼��İ�ȫ�汾��������Щ�������������һ��_s�ĺ�������Щ��ȫ�汾����ʹ����������Ч��Ҳ����ʶ���磺strcpy_s,calloc_s�ȡ�
    ��Ȼ�����ִ��ʹ���ϰ汾���ǰ�ȫ�汾����������ʹ��_CRT_SECURE_NO_DEPRECATE�����������Щ�������⡣�취���ڱ���ѡ�� C/C++ | Preprocessor | Preprocessor Definitions�У�����_CRT_SECURE_NO_DEPRECATE��Ǽ��ɡ����ڳ���ͷ���
    #pragma  warning(disable:4996)   //ȫ���ص�          #pragma  warning(once:4996)      //����ʾһ��
    */
    #pragma warning(disable:4819 4996 4101 4251 4275 4800)
    #pragma warning (error: 4715)  
#endif //_MSC_VER

#include <stdio.h>
#include <stdlib.h>

#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <set>

    // treat some warnings as errors

/*
windowsƽ̨��Ŀ����x64����x86һ����������WIN32�����
*/
#ifdef WIN32
#pragma warning (error: 4002)
#pragma warning (error: 4667)
#pragma warning (error: 4715)
#pragma warning (error: 4390)       // if (xxx) ;
#pragma warning (error: 4172)       // return address of local temp memory
#endif // WIN32

#endif //_STDAFX_H_