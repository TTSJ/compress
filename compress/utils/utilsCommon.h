#pragma once
/*
动态库接口导出设置。不导出动态库，则只有一个dll文件，而链接是需要lib文件的。将方法导出，则会生成一个动态库的lib文件用于链接，此lib文件包含接口信息。
如果动态库的接口没变，那么lib文件是永远不会改变的。所以接口不变的情况下，替换动态库就可以实现升级。
*/
#ifdef UTILS_EXPORTS
    #define DLL_EXPORT_UTILS __declspec(dllexport)
#else
    #define DLL_EXPORT_UTILS __declspec(dllimport)
#endif