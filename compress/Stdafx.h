#ifndef _STDAFX_H_
#define _STDAFX_H_

#ifdef _MSC_VER   //微软编译器的版本宏，vs2015是1900
    /*
    在许多windows下的项目中,我们经常可以看到在stdafx.h中有这么个宏定义#define WIN32_LEAN_AND_MEAN,它的作用实际上是当我们项目中包含了<windows.h>
    时去除一些头文件的包含,加快编译速度,大家可以跳进<windows.h>中搜索一下WIN32_LEAN_AND_MEAN就能看到去除了哪些头文件的包含了
    */
    #define WIN32_LEAN_AND_MEAN     // Exclude rarely-used stuff from Windows headers
    /*
    warning C4996: strcpy was declared deprecated
    在使用VC 2005 的开发者会遇到这样的问题，在使用std命名空间库函数的时候，往往会出现类似于下面的警告：    warning C4996: strcpy was declared deprecated
    出现这样的警告，是因为VC2005中认为CRT中的一组函数如果使用不当，可能会产生诸如内存泄露、缓冲区溢出、非法访问等安全问题。这些函数如：strcpy、strcat等。
    对于这些问题，VC2005建议使用这些函数的更高级的安全版本，即在这些函数名后面加了一个_s的函数。这些安全版本函数使用起来更有效，也便于识别，如：strcpy_s,calloc_s等。
    当然，如果执意使用老版本、非安全版本函数，可以使用_CRT_SECURE_NO_DEPRECATE标记来忽略这些警告问题。办法是在编译选项 C/C++ | Preprocessor | Preprocessor Definitions中，增加_CRT_SECURE_NO_DEPRECATE标记即可。或在程序开头添加
    #pragma  warning(disable:4996)   //全部关掉          #pragma  warning(once:4996)      //仅显示一个
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
windows平台项目不管x64还是x86一定都定义了WIN32这个宏
*/
#ifdef WIN32
#pragma warning (error: 4002)
#pragma warning (error: 4667)
#pragma warning (error: 4715)
#pragma warning (error: 4390)       // if (xxx) ;
#pragma warning (error: 4172)       // return address of local temp memory
#endif // WIN32

#endif //_STDAFX_H_